// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

namespace Test::Metadata
{
	struct CombatantCharacterMetadata;
}

class UStatsComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FStatsComponentElmininationSignature, UStatsComponent*)
DECLARE_MULTICAST_DELEGATE_TwoParams(FStatsComponentReceiveDamage, UStatsComponent*, uint64)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STAIRWAYTEST_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UStatsComponent();

protected:
	virtual void BeginPlay() override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Stats
	// ##############################################################################
	// ##############################################################################

private:
	bool bSetup = false;
	bool IsAlive = true;
	bool Param_PlayerTeam = true;
	uint64 Param_HP = 1000;
	uint64 Param_Attack = 1000;

	uint64 CurrentHP = 0;

public:
	void SetupStats(const Test::Metadata::CombatantCharacterMetadata& _Metadata);

	bool GetIsAlive() const { return IsAlive; }
	bool GetPlayerTeam() const { return Param_PlayerTeam; }
	uint64 GetHP() const { return Param_HP; }
	uint64 GetAttack() const { return Param_Attack; }

	uint64 GetCurrentHP() const { return CurrentHP; }

	// ###############################################
	// ###############################################
	// ####		Apply Damage
	// ####

private:
	void OnEliminated();

public:
	void ApplyDamage(UStatsComponent* _AttackerStatsComponent, uint64 _Damage);

	FStatsComponentElmininationSignature OnEliminated_Delegate;
	FStatsComponentReceiveDamage OnApplyDamage_Delegate;
};
