// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAction/CharacterAction.h"

#include "Character/CombatantCharacter.h"
#include "Character/CombatantCharacterAnimation.h"
#include "CharacterAction/CharacterAction_Metadata.h"

Test::Metadata::CharacterActionMetadata UCharacterAction::CharacterActionMetadata()
{
	unimplemented();
	return Test::Metadata::CharacterActionMetadata();
}

void UCharacterAction::BeginPlay()
{
	checkf(GetWorld(), TEXT("GetWorld() is return nullptr. Make sure its outer is CombatantCharacter"));

	DH_Tick = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this](float _DeltaTime)
	{
		if (!GetWorld()->IsPaused())
			Tick(_DeltaTime);
		return true;
	}));
}

void UCharacterAction::EndPlay()
{
	FTSTicker::GetCoreTicker().RemoveTicker(DH_Tick);
}

ACombatantCharacter* UCharacterAction::GetCombatantCharacterOwner()
{
	if (!CombatantCharacterOwner)
		CombatantCharacterOwner = GetTypedOuter<ACombatantCharacter>();
	return CombatantCharacterOwner;
}

void UCharacterAction::Tick(const float _DeltaTime)
{
}

// ##############################################################################
// ##############################################################################
// ###########		Action Execution
// ##############################################################################
// ##############################################################################

void UCharacterAction::BeginAction()
{
	if (BeginActionRequirements())
		return;

	// Bind animation notification
	if (auto* _animation_bp = Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance()))
	{
		DH_AnimNotify = _animation_bp->OnAnimationNotify_Delegate.AddLambda([this](UCombatantCharacterAnimation*, FName _NotifyName)
		{
			OnAnimationNotify(_NotifyName);
		});
	}

	OnBeginAction();
}

void UCharacterAction::EndAction()
{
	if (EndActionRequirements())
		return;

	if (auto* _animation_bp = Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance()))
	{
		_animation_bp->OnAnimationNotify_Delegate.Remove(DH_AnimNotify);
	}

	OnEndAction();
}

bool UCharacterAction::BeginActionRequirements()
{
	return IsExecuting;
}

bool UCharacterAction::EndActionRequirements()
{
	return !IsExecuting;
}

void UCharacterAction::OnBeginAction()
{
	IsExecuting = true;
	OnBeginAction_Delegate.Broadcast(this);
}

void UCharacterAction::OnEndAction()
{
	IsExecuting = false;
	OnEndAction_Delegate.Broadcast(this);
}

// ##############################################################################
// ##############################################################################
// ###########		Animation Notify
// ##############################################################################
// ##############################################################################

void UCharacterAction::OnAnimationNotify(const FName& _NotifyName)
{
}
