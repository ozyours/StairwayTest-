// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CombatantCharacter.h"
#include "EnemyCharacter.generated.h"

class UWidgetComponent;

UCLASS()
class STAIRWAYTEST_API AEnemyCharacter : public ACombatantCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Component
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY()
	UWidgetComponent* HPWidgetComponent;

	// ##############################################################################
	// ##############################################################################
	// ###########		Activation
	// ##############################################################################
	// ##############################################################################

protected:
	// virtual void OnActivated() override;
	virtual void OnDeactivated() override;
};
