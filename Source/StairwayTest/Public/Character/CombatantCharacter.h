// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatantCharacter.generated.h"

class UCombatantCharacterMetadata;
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

	// ##############################################################################
	// ##############################################################################
	// ###########		Activation
	// ##############################################################################
	// ##############################################################################

private:
	bool bActivation = false;

protected:
	virtual void OnActivated();
	virtual void OnDeactivated();

public:
	bool GetActivation() const { return bActivation; }
	void Activate();
	void Deactivate();

	// ##############################################################################
	// ##############################################################################
	// ###########		Spawn
	// ##############################################################################
	// ##############################################################################

public:
	static ACombatantCharacter* Spawn(UWorld* _World, const Test::Metadata::CombatantCharacterMetadata& _Metadata, const FVector& _Location, const FRotator& _Rotation = FRotator(0));
	static ACombatantCharacter* Spawn(UWorld* _World, const TSubclassOf<UCombatantCharacterMetadata> _Metadata, const FVector& _Location, const FRotator& _Rotation = FRotator(0));
};
