// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamagingObject.generated.h"

class UStatsComponent;

UCLASS()
class STAIRWAYTEST_API ADamagingObject : public AActor
{
	GENERATED_BODY()

public:
	ADamagingObject();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Parameter
	// ##############################################################################
	// ##############################################################################
public:
	// Should attack enemy
	// True = attack enemy. False = attach player.
	virtual bool Param_AttackEnemy() const { return true; }

	// Determine the auto deactivation timer after activation
	// 0 or below to disable the timer
	virtual float Param_DeactivationTimer() const { return 0.25f; }
	// Determine the auto destroy timer after deactivation
	// 0 or below to disable the timer
	virtual float Param_DestroyAfterDeactivationTimer() const { return 0.1f; }

	// Set the damage by scale of the attacker's attack
	float Param_AttackScale = 1.f;

	// ##############################################################################
	// ##############################################################################
	// ###########		Component
	// ##############################################################################
	// ##############################################################################
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// For primitive components will affect the object collision shape
	// All children primitive components' collision will be set 
	UPROPERTY(VisibleAnywhere)
	USceneComponent* CollisionRoot;

	// For appearance of the damaging object
	// All children primitive components' collision will be removed
	UPROPERTY(VisibleAnywhere)
	USceneComponent* AppearanceRoot;

public:
	USceneComponent* GetCollisionRoot() const { return CollisionRoot; }
	USceneComponent* GetAppearanceRoot() const { return AppearanceRoot; }

	// ##############################################################################
	// ##############################################################################
	// ###########		Activation
	// ##############################################################################
	// ##############################################################################

private:
	bool bActivation = false;
	FTimerHandle TH_ActivationTimer;

protected:
	virtual void OnActivated();
	virtual void OnDeactivated();

public:
	bool GetActivation() const { return bActivation; }
	void Activate(UStatsComponent* _DamagingCaster);
	void Deactivate();

	// ##############################################################################
	// ##############################################################################
	// ###########		Damaging
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY()
	UStatsComponent* DamagingCaster = nullptr;
	uint64 DamageAmount = 0;

protected:
	virtual bool HitRequirements(UStatsComponent* _TargetStatsComponent) const;
	void DealDamage(UStatsComponent* _TargetStatsComponent);
	virtual void OnDamage(UStatsComponent* _TargetStatsComponent);

public:
	UStatsComponent* GetDamagingCaster() const { return DamagingCaster; }
	uint64 GetDamageAmount() const { return DamageAmount; }
};
