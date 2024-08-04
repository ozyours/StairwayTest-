// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/Warrior/EnemyCharacter_Warrior.h"

#include "Character/PlayerCharacter/PlayerCharacter_Action.h"

Test::Metadata::EnemyCharacter_Warrior::EnemyCharacter_Warrior()
{
	Param_PlayerTeam = false;
	Param_Name = "EnemyWarrior";
	Param_DisplayName = FText::FromString("Enemy Warrior");
	Param_HP = 2000;
	Param_Class = AEnemyCharacter_Warrior::StaticClass();
	Param_AssetPath = "/Script/Engine.Blueprint'/Game/Test/CombatantCharacter/EnemyCharacter/BP_EnemyCharacter_Warrior.BP_EnemyCharacter_Warrior_C'";
	Param_BasicAttackAction = PlayerCharacter_Action_BasicAttack();
}

Test::Metadata::CombatantCharacterMetadata UMetadata_EnemyCharacter_Warrior::CombatantCharacterMetadata()
{
	return Test::Metadata::EnemyCharacter_Warrior();
}

// Sets default values
AEnemyCharacter_Warrior::AEnemyCharacter_Warrior()
{
	GetMesh()->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/ModularRPGHeroesPolyart/Meshes/OneMeshCharacters/WarriorSK.WarriorSK'")).Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -95));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetAnimInstanceClass(ConstructorHelpers::FClassFinder<UAnimInstance>(TEXT("/Script/Engine.AnimBlueprint'/Game/Test/CombatantCharacter/EnemyCharacter/ABP_EnemyCharacter_Warrior.ABP_EnemyCharacter_Warrior_C'")).Class);

	RightWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightWeapon"));
	RightWeapon->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/ModularRPGHeroesPolyart/Meshes/Weapons/Sword04SM.Sword04SM'")).Object);
	RightWeapon->SetupAttachment(GetMesh(), "hand_rSocket");
	RightWeapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

Test::Metadata::CombatantCharacterMetadata AEnemyCharacter_Warrior::CombatantCharacterMetadata()
{
	return Test::Metadata::EnemyCharacter_Warrior();
}
