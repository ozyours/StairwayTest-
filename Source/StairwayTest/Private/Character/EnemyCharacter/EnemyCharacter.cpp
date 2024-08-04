// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/EnemyCharacter.h"

#include "Character/EnemyCharacter/EnemyAIController.h"
#include "Character/EnemyCharacter/EnemyCharacter_HPWidget.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = AEnemyAIController::StaticClass();

	HPWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPWidgetComponent"));
	HPWidgetComponent->SetupAttachment(GetRootComponent());
	HPWidgetComponent->SetDrawSize(FVector2D(128.f, 16.f));
	HPWidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 80.f));
	HPWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);

	GetCharacterMovement()->bUseRVOAvoidance = true;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	Activate();
	HPWidgetComponent->SetSlateWidget(SNew(SEnemyCharacter_HPWidget).EnemyCharacter(this));
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ##############################################################################
// ##############################################################################
// ###########		Activation
// ##############################################################################
// ##############################################################################

void AEnemyCharacter::OnDeactivated()
{
	Super::OnDeactivated();
	GetController()->UnPossess();
	SetLifeSpan(1.f);
}
