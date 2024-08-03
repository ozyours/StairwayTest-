// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/StatsComponent.h"

#include "Character/CombatantCharacter_Metadata.h"

UStatsComponent::UStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bAutoActivate = false;
}

void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();
}

// ##############################################################################
// ##############################################################################
// ###########		Stats
// ##############################################################################
// ##############################################################################

void UStatsComponent::SetupStats(const Test::Metadata::CombatantCharacterMetadata& _Metadata)
{
	if (bSetup)
	{
		UE_LOG(LogTemp, Warning, TEXT("UStatsComponent::SetupStats: StatsComponent owned by %s already setup."), *(GetOwner() ? GetOwner()->GetName() : "None"));
		return;
	}

	bSetup = true;
	Param_PlayerTeam = _Metadata.Param_PlayerTeam;
	Param_HP = _Metadata.Param_HP;
	Param_Attack = _Metadata.Param_Attack;

	CurrentHP = Param_HP;
}

// ###############################################
// ###############################################
// ####		Apply Damage
// ####

void UStatsComponent::OnEliminated()
{
	OnEliminated_Delegate.Broadcast(this);
}

void UStatsComponent::ApplyDamage(UStatsComponent* _AttackerStatsComponent, uint64 _Damage)
{
	if (!IsAlive || !IsActive())
		return;

	if (_Damage >= CurrentHP)
	{
		CurrentHP = 0;
		IsAlive = false;
		OnEliminated();
	}
	else
	{
		CurrentHP -= _Damage;
	}
	OnApplyDamage_Delegate.Broadcast(this, _Damage);
}
