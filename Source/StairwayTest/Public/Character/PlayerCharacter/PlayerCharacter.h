// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CombatantCharacter.h"
#include "Character/CombatantCharacter_MetadataObject.h"
#include "PlayerCharacter.generated.h"

class UAISense;
class UAIPerceptionStimuliSourceComponent;
class USpringArmComponent;
class UCameraComponent;

class UInputMappingContext;
class UInputAction;

// Define and declare the metadata
namespace Test::Metadata
{
	struct PlayerCharacter : CombatantCharacterMetadata
	{
		PlayerCharacter();
	};
}

// Define and declare the object metadata
UCLASS()
class STAIRWAYTEST_API UMetadata_PlayerCharacter : public UCombatantCharacterMetadata
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata() override;
};

// Player's combatant character
UCLASS()
class STAIRWAYTEST_API APlayerCharacter : public ACombatantCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraSpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* WeaponLeft;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* WeaponRight;

	UPROPERTY()
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY()
	UInputAction* IA_Camera;
	UPROPERTY()
	UInputAction* IA_Move;

	UPROPERTY()
	UInputAction* IA_Attack;

	void Move(const struct FInputActionValue& Value);
	void Camera(const struct FInputActionValue& Value);
	void Attack(const struct FInputActionValue& Value);

	UPROPERTY(VisibleAnywhere)
	UAIPerceptionStimuliSourceComponent* AIPerceptionStimulus;
};
