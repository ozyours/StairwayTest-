// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/Knight/EnemyCharacter_Knight.h"

#include "Character/PlayerCharacter/PlayerCharacter_Action.h"

Test::Metadata::EnemyCharacter_Knight::EnemyCharacter_Knight()
{
	Param_PlayerTeam = false;
	Param_Name = "EnemyKnight";
	Param_DisplayName = FText::FromString("Enemy Knight");
	Param_HP = 2000;
	Param_Class = AEnemyCharacter_Knight::StaticClass();
	Param_AssetPath = "/Script/Engine.Blueprint'/Game/Test/CombatantCharacter/EnemyCharacter/BP_EnemyCharacter_Knight.BP_EnemyCharacter_Knight_C'";
	Param_BasicAttackAction = PlayerCharacter_Action_BasicAttack();
}

Test::Metadata::CombatantCharacterMetadata UMetadata_EnemyCharacter_Knight::CombatantCharacterMetadata()
{
	return Test::Metadata::EnemyCharacter_Knight();
}

AEnemyCharacter_Knight::AEnemyCharacter_Knight()
{
	GetMesh()->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/ModularRPGHeroesPolyart/Meshes/OneMeshCharacters/KnightSK.KnightSK'")).Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -95));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetAnimInstanceClass(ConstructorHelpers::FClassFinder<UAnimInstance>(TEXT("/Script/Engine.AnimBlueprint'/Game/Test/CombatantCharacter/EnemyCharacter/ABP_EnemyCharacter_Knight.ABP_EnemyCharacter_Knight_C'")).Class);

	LeftWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftWeapon"));
	LeftWeapon->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/ModularRPGHeroesPolyart/Meshes/Weapons/Shield05SM.Shield05SM'")).Object);
	LeftWeapon->SetupAttachment(GetMesh(), "hand_lSocket");
	LeftWeapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);

	RightWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightWeapon"));
	RightWeapon->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/ModularRPGHeroesPolyart/Meshes/Weapons/Sword02SM.Sword02SM'")).Object);
	RightWeapon->SetupAttachment(GetMesh(), "hand_rSocket");
	RightWeapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

Test::Metadata::CombatantCharacterMetadata AEnemyCharacter_Knight::CombatantCharacterMetadata()
{
	return Test::Metadata::EnemyCharacter_Knight();
}
