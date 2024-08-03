// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamagingObject/DamagingObject.h"
#include "PlayerCharacter_Attack.generated.h"

class UBoxComponent;

UCLASS()
class STAIRWAYTEST_API APlayerCharacter_Attack_BasicAttack : public ADamagingObject
{
	GENERATED_BODY()

public:
	APlayerCharacter_Attack_BasicAttack();

	// ##############################################################################
	// ##############################################################################
	// ###########		Component
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
};
