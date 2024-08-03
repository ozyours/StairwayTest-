// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/CombatantCharacter.h"

#include "Character/CombatantCharacter_Metadata.h"
#include "Character/CombatantCharacter_MetadataObject.h"
#include "Character/PlayerCharacter/PlayerCharacter_Action.h"
#include "Character/StatsComponent.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACombatantCharacter::ACombatantCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	StatsComponent = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComponent"));
}

Test::Metadata::CombatantCharacterMetadata ACombatantCharacter::CombatantCharacterMetadata()
{
	checkf(false, TEXT("Unimplemented Metadata: %s"), *GetName());
	return Test::Metadata::CombatantCharacterMetadata();
}

void ACombatantCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetStatsComponent()->SetupStats(CombatantCharacterMetadata());
}

void ACombatantCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (BasicAttackAction)
		BasicAttackAction->EndPlay();
}

// ##############################################################################
// ##############################################################################
// ###########		Activation
// ##############################################################################
// ##############################################################################

void ACombatantCharacter::OnActivated()
{
	// Setup basic attack action
	check(CombatantCharacterMetadata().Param_BasicAttackAction.Param_Class);
	BasicAttackAction = NewObject<UChainedCharacterAction>(this, CombatantCharacterMetadata().Param_BasicAttackAction.Param_Class);
	BasicAttackAction->BeginPlay();

	GetStatsComponent()->Activate();
	GetStatsComponent()->OnEliminated_Delegate.AddLambda([this](UStatsComponent*)
	{
		Deactivate();
	});
}

void ACombatantCharacter::OnDeactivated()
{
	GetStatsComponent()->Deactivate();
}

void ACombatantCharacter::Activate()
{
	if (bActivation)
		return;

	bActivation = true;
	OnActivated();
}

void ACombatantCharacter::Deactivate()
{
	if (!bActivation)
		return;

	bActivation = false;
	OnDeactivated();
}

// ##############################################################################
// ##############################################################################
// ###########		Spawn
// ##############################################################################
// ##############################################################################

ACombatantCharacter* ACombatantCharacter::Spawn(UWorld* _World, const TSubclassOf<ACombatantCharacter>& _Class, const FVector& _Location, const FRotator& _Rotation)
{
	FActorSpawnParameters _spawn_parameters;
	_spawn_parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	return _World->SpawnActor<ACombatantCharacter>(_Class, _Location, _Rotation, _spawn_parameters);
}

ACombatantCharacter* ACombatantCharacter::Spawn(UWorld* _World, const Test::Metadata::CombatantCharacterMetadata& _Metadata, const FVector& _Location, const FRotator& _Rotation)
{
	return Spawn(_World, _Metadata.Param_Class, _Location, _Rotation);
}

ACombatantCharacter* ACombatantCharacter::Spawn(UWorld* _World, const TSubclassOf<UCombatantCharacterMetadata> _Metadata, const FVector& _Location, const FRotator& _Rotation)
{
	return Spawn(_World, _Metadata->GetDefaultObject<UCombatantCharacterMetadata>()->CombatantCharacterMetadata(), _Location, _Rotation);
}
