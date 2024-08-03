// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/Knight/EnemyCharacter_Knight.h"

#include "Character/EnemyCharacter/Knight/EnemyCharacter_Knight_Action.h"

Test::Metadata::EnemyCharacter_Knight::EnemyCharacter_Knight()
{
	Param_PlayerTeam = false;
	Param_Name = "EnemyKnight";
	Param_DisplayName = FText::FromString("Enemy Knight");
	Param_HP = 2000;
	Param_Class = AEnemyCharacter_Knight::StaticClass();
	Param_BasicAttackAction = EnemyCharacter_Knight_Action_BasicAttack();
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
}

Test::Metadata::CombatantCharacterMetadata AEnemyCharacter_Knight::CombatantCharacterMetadata()
{
	return Test::Metadata::EnemyCharacter_Knight();
}
