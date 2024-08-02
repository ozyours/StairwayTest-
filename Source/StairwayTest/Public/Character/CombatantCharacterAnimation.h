// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CombatantCharacterAnimation.generated.h"

/**
 *
 */
UCLASS(Abstract)
class STAIRWAYTEST_API UCombatantCharacterAnimation : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	bool IsRunning = false;
};
