// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BasicAttack/EnemyCharacter_Generic_Attack.h"

#include "Components/BoxComponent.h"

AEnemyCharacter_Generic_Attack::AEnemyCharacter_Generic_Attack()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(GetCollisionRoot());
	BoxComponent->SetBoxExtent(FVector(50.f, 75.f, 100.f));
	BoxComponent->SetHiddenInGame(false);
}

