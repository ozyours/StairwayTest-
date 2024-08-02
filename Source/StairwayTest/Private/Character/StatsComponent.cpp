// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/StatsComponent.h"

UStatsComponent::UStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStatsComponent::ApplyDamage(uint64 _Damage)
{
	if (!IsAlive)
		return;

	if (_Damage >= Param_HP)
	{
		Param_HP = 0;
		OnEliminated();
	}
	else
	{
		Param_HP -= _Damage;
	}
	OnApplyDamage.Broadcast(this, _Damage);
}

void UStatsComponent::OnEliminated()
{
	OnEliminatedDelegate.Broadcast(this);
}