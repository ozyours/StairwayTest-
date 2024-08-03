// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/PlayerCharacter/PlayerCharacter.h"
#include "Character/PlayerCharacter/PlayerCharacter_CharacterAction.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Animation/AnimInstance.h"

#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

Test::Metadata::PlayerCharacter::PlayerCharacter()
{
	Param_Name = "PlayerCharacter";
	Param_DisplayName = FText::FromString("Player's Character");
	Param_HP = 5000;
	Param_Class = APlayerCharacter::StaticClass();
	Param_BasicAttackAction = PlayerCharacterAction_BasicAttack();
}

Test::Metadata::CombatantCharacterMetadata UMetadata_PlayerCharacter::CombatantCharacterMetadata()
{
	return Test::Metadata::PlayerCharacter();
}

APlayerCharacter::APlayerCharacter()
{
	GetMesh()->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/ModularRPGHeroesPolyart/Meshes/OneMeshCharacters/CommonerSK.CommonerSK'")).Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetAnimInstanceClass(ConstructorHelpers::FClassFinder<UAnimInstance>(TEXT("/Script/Engine.AnimBlueprint'/Game/Test/CombatantCharacter/PlayerCharacter/ABP_PlayerCharacter.ABP_PlayerCharacter_C'")).Class);

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraSpringArm->SetupAttachment(GetRootComponent());
	CameraSpringArm->TargetArmLength = 400.f;
	CameraSpringArm->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(CameraSpringArm);
	CameraComponent->bUsePawnControlRotation = true;

	DefaultMappingContext = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Test/CombatantCharacter/PlayerCharacter/IMC_PlayerInput.IMC_PlayerInput'")).Object;
	IA_Camera = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Script/EnhancedInput.InputAction'/Game/Test/CombatantCharacter/PlayerCharacter/IA_Camera.IA_Camera'")).Object;
	IA_Move = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Script/EnhancedInput.InputAction'/Game/Test/CombatantCharacter/PlayerCharacter/IA_Move.IA_Move'")).Object;
}

Test::Metadata::CombatantCharacterMetadata APlayerCharacter::CombatantCharacterMetadata()
{
	return Test::Metadata::PlayerCharacter();
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EnhancedInputComponent->BindAction(IA_Camera, ETriggerEvent::Triggered, this, &APlayerCharacter::Camera);

		EnhancedInputComponent->BindAction(IA_Attack, ETriggerEvent::Started, this, &APlayerCharacter::Attack);
	}

	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Cast<APlayerController>(Controller)->GetLocalPlayer())->AddMappingContext(DefaultMappingContext, 0);
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void APlayerCharacter::Camera(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void APlayerCharacter::Attack(const FInputActionValue& Value)
{
	GetBasicAttackAction()->BeginAction();
}