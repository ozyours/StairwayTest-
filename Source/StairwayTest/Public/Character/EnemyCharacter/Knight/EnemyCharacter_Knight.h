// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CombatantCharacter_MetadataObject.h"
#include "Character/EnemyCharacter/EnemyCharacter.h"
#include "EnemyCharacter_Knight.generated.h"

// Define and declare the metadata
namespace Test::Metadata
{
	struct EnemyCharacter_Knight : CombatantCharacterMetadata
	{
		EnemyCharacter_Knight();
	};
}

// Define and declare the object metadata
UCLASS()
class STAIRWAYTEST_API UMetadata_EnemyCharacter_Knight : public UCombatantCharacterMetadata
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata() override;
};

UCLASS()
class STAIRWAYTEST_API AEnemyCharacter_Knight : public AEnemyCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter_Knight();
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata() override;
};
