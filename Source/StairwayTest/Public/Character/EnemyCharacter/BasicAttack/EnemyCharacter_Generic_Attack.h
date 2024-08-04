// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamagingObject/DamagingObject.h"
#include "EnemyCharacter_Generic_Attack.generated.h"

class UBoxComponent;

UCLASS()
class STAIRWAYTEST_API AEnemyCharacter_Generic_Attack : public ADamagingObject
{
	GENERATED_BODY()

public:
	AEnemyCharacter_Generic_Attack();
	
	virtual bool Param_AttackEnemy() const override { return false; }

	// ##############################################################################
	// ##############################################################################
	// ###########		Component
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
};
