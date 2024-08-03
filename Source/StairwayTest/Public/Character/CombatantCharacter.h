// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatantCharacter.generated.h"

class UChainedCharacterAction;
class UStatsComponent;

namespace Test::Metadata
{
	struct CombatantCharacterMetadata;
}

UCLASS(Abstract)
class STAIRWAYTEST_API ACombatantCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACombatantCharacter();

	// The character metadata
	// Always override the function and set the metadata
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Component
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY(VisibleAnywhere)
	UStatsComponent* StatsComponent;

public:
	UStatsComponent* GetStatsComponent() const { return StatsComponent; }

	// ##############################################################################
	// ##############################################################################
	// ###########		Character Action
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY()
	UChainedCharacterAction* BasicAttackAction = nullptr;

public:
	UChainedCharacterAction* GetBasicAttackAction() const { return BasicAttackAction; }
};
