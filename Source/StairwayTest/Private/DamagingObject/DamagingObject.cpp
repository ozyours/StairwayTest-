// Fill out your copyright notice in the Description page of Project Settings.

#include "DamagingObject/DamagingObject.h"

#include "Character/StatsComponent.h"

ADamagingObject::ADamagingObject()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	CollisionRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CollisionRoot"));
	CollisionRoot->SetupAttachment(GetRootComponent());

	AppearanceRoot = CreateDefaultSubobject<USceneComponent>(TEXT("AppearanceRoot"));
	AppearanceRoot->SetupAttachment(GetRootComponent());
}

void ADamagingObject::BeginPlay()
{
	Super::BeginPlay();
}

void ADamagingObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(TH_ActivationTimer);
}

void ADamagingObject::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (bActivation)
	{
		if (auto _stats_component = OtherActor->GetComponentByClass(UStatsComponent::StaticClass()))
			DealDamage(reinterpret_cast<UStatsComponent*>(_stats_component));
	}
}

void ADamagingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADamagingObject::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// set all children components collision
	{
		TArray<USceneComponent*> _children_component;
		CollisionRoot->GetChildrenComponents(true, _children_component);
		for (auto* _component : _children_component)
		{
			if (auto* _primitive_component = Cast<UPrimitiveComponent>(_component))
			{
				_primitive_component->SetCollisionProfileName("Attack");
			}
		}
	}

	// clear all children components collision
	{
		TArray<USceneComponent*> _children_component;
		AppearanceRoot->GetChildrenComponents(true, _children_component);
		for (auto* _component : _children_component)
		{
			if (auto* _primitive_component = Cast<UPrimitiveComponent>(_component))
			{
				_primitive_component->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
			}
		}
	}
}

// ##############################################################################
// ##############################################################################
// ###########		Activation
// ##############################################################################
// ##############################################################################

void ADamagingObject::OnActivated()
{
	if (Param_DeactivationTimer() > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(TH_ActivationTimer, [this]()
		{
			Deactivate();
		}, Param_DeactivationTimer(), false);
	}

	// check overlapping actors
	{
		TArray<AActor*> _overlapping_actors;
		GetOverlappingActors(_overlapping_actors);

		for (auto* _actor : _overlapping_actors)
		{
			if (auto _stats_component = _actor->GetComponentByClass(UStatsComponent::StaticClass()))
				DealDamage(reinterpret_cast<UStatsComponent*>(_stats_component));
		}
	}
}

void ADamagingObject::OnDeactivated()
{
	if (Param_DestroyAfterDeactivationTimer() > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(TH_ActivationTimer, [this]()
		{
			Destroy();
		}, Param_DestroyAfterDeactivationTimer(), false);
	}
}

void ADamagingObject::Activate(UStatsComponent* _DamagingCaster)
{
	if (bActivation)
		return;

	check(_DamagingCaster);
	bActivation = true;
	DamagingCaster = _DamagingCaster;
	DamageAmount = DamagingCaster->GetAttack() * Param_AttackScale;
	OnActivated();
}

void ADamagingObject::Deactivate()
{
	if (!bActivation)
		return;

	bActivation = false;
	OnDeactivated();
}

// ##############################################################################
// ##############################################################################
// ###########		Damaging
// ##############################################################################
// ##############################################################################

bool ADamagingObject::HitRequirements(UStatsComponent* _TargetStatsComponent) const
{
	return _TargetStatsComponent &&
		_TargetStatsComponent->IsActive() &&
		_TargetStatsComponent->GetIsAlive() &&
		_TargetStatsComponent->GetPlayerTeam() != GetDamagingCaster()->GetPlayerTeam();
}

void ADamagingObject::DealDamage(UStatsComponent* _TargetStatsComponent)
{
	if (HitRequirements(_TargetStatsComponent))
	{
		OnDamage(_TargetStatsComponent);
	}
}

void ADamagingObject::OnDamage(UStatsComponent* _TargetStatsComponent)
{
	_TargetStatsComponent->ApplyDamage(GetDamagingCaster(), DamageAmount);
}
