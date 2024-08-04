// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAction/ChainedCharacterAction.h"

#include "CharacterAction/CharacterAction_Metadata.h"

void UChainedCharacterAction::BeginPlay()
{
	Super::BeginPlay();

	checkf(ChainActions().Num() > 0, TEXT("Make sure the chain action is not empty."));
	for (const auto _entry : ChainActions())
	{
		auto* _action = NewObject<UCharacterAction>(this, _entry.Param_Class);
		_action->BeginPlay();
		DH_ChainActionFinished.Add(_action->OnEndAction_Delegate.AddUObject(this, &UChainedCharacterAction::OnChainActionFinished));
		ChainActionObjects.Add(_action);
	}
}

void UChainedCharacterAction::EndPlay()
{
	Super::EndPlay();

	for (int i = 0; i < ChainActionObjects.Num(); i++)
	{
		auto* _action = ChainActionObjects[i];
		_action->EndPlay();
		_action->OnEndAction_Delegate.Remove(DH_ChainActionFinished[i]);
	}
	DH_ChainActionFinished.Empty();
}

void UChainedCharacterAction::Tick(const float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (!GetIsExecuting())
	{
		CurrentChainTimout = FMath::Max(CurrentChainTimout - _DeltaTime, 0.f);
		if (CurrentChainTimout == 0)
		{
			ChainIndex = 0;
		}
	}
}

// ##############################################################################
// ##############################################################################
// ###########		Action Execution
// ##############################################################################
// ##############################################################################

void UChainedCharacterAction::OnBeginAction()
{
	Super::OnBeginAction();
	ChainActionObjects[ChainIndex]->BeginAction();
}

void UChainedCharacterAction::OnEndAction()
{
	Super::OnEndAction();
}

// ##############################################################################
// ##############################################################################
// ###########		Chain Action
// ##############################################################################
// ##############################################################################

TArray<Test::Metadata::CharacterActionMetadata> UChainedCharacterAction::ChainActions()
{
	return TArray<Test::Metadata::CharacterActionMetadata>();
}

void UChainedCharacterAction::OnChainActionFinished(UCharacterAction* _CharacterAction)
{
	ChainIndex++;
	if (ChainIndex > ChainActionObjects.Num() - 1)
	{
		ChainIndex = 0;
		CurrentChainTimout = 0;
	}
	else
	{
		CurrentChainTimout = ChainTimeout;
	}

	EndAction();
}
