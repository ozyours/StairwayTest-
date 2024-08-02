// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

class UStatsComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FStatsComponentElmininationSignature, UStatsComponent*)
DECLARE_MULTICAST_DELEGATE_TwoParams(FStatsComponentReceiveDamage, UStatsComponent*, uint64)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STAIRWAYTEST_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()
	friend class ACombatantCharacter;

public:
	UStatsComponent();

protected:
	virtual void BeginPlay() override;

private:
	bool IsAlive = true;
	uint64 Param_HP = 1000;

public:
	void ApplyDamage(uint64 _Damage);

	FStatsComponentElmininationSignature OnEliminatedDelegate;
	FStatsComponentReceiveDamage OnApplyDamage;

private:
	void OnEliminated();
};
