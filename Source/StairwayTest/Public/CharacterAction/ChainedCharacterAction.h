// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterAction.h"
#include "ChainedCharacterAction.generated.h"

namespace Test::Metadata
{
	struct ChainedCharacterActionMetadata;
}

// Chaining character action for doing combo attack
UCLASS(Abstract)
class STAIRWAYTEST_API UChainedCharacterAction : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void EndPlay() override;

protected:
	virtual void Tick(const float _DeltaTime) override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Action Execution
	// ##############################################################################
	// ##############################################################################

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Chain Action
	// ##############################################################################
	// ##############################################################################

public:
	int GetChainIndex() const { return ChainIndex; }

protected:
	virtual TArray<Test::Metadata::CharacterActionMetadata> ChainActions();

private:
	static constexpr float ChainTimeout = 0.25f;
	float CurrentChainTimout = 0.f;
	int ChainIndex = 0;

	UPROPERTY()
	TArray<UCharacterAction*> ChainActionObjects;

	TArray<FDelegateHandle> DH_ChainActionFinished;
	void OnChainActionFinished(UCharacterAction* _CharacterAction);
};
