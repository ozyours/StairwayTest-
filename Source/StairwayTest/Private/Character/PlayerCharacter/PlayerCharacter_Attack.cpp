// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/PlayerCharacter/PlayerCharacter_Attack.h"

#include "Components/BoxComponent.h"

APlayerCharacter_Attack_BasicAttack::APlayerCharacter_Attack_BasicAttack()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(GetCollisionRoot());
	BoxComponent->SetBoxExtent(FVector(50.f, 75.f, 100.f));
	BoxComponent->SetHiddenInGame(false);
}
