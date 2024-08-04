// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_FocusPlayerTarget.generated.h"

/**
 * 
 */
UCLASS()
class STAIRWAYTEST_API UBTS_FocusPlayerTarget : public UBTService
{
	GENERATED_BODY()

public:
	UBTS_FocusPlayerTarget();

protected:
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
