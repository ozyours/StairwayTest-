// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CombatantCharacterAnimation.generated.h"

class UCombatantCharacterAnimation;

DECLARE_MULTICAST_DELEGATE_TwoParams(FAnimationNotify, UCombatantCharacterAnimation*, FName);

/**
 *
 */
UCLASS(Abstract)
class STAIRWAYTEST_API UCombatantCharacterAnimation : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	FAnimationNotify OnAnimationNotify_Delegate;

protected:
	virtual bool HandleNotify(const FAnimNotifyEvent& AnimNotifyEvent) override;

public:
	UPROPERTY(BlueprintReadOnly)
	bool IsRunning = false;

	UPROPERTY(BlueprintReadOnly)
	int BasicAttackIndex = -1;
};
