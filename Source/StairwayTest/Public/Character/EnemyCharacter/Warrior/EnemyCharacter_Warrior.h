// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CombatantCharacter_MetadataObject.h"
#include "Character/EnemyCharacter/EnemyCharacter.h"
#include "EnemyCharacter_Warrior.generated.h"


// Define and declare the metadata
namespace Test::Metadata
{
	struct EnemyCharacter_Warrior : CombatantCharacterMetadata
	{
		EnemyCharacter_Warrior();
	};
}

// Define and declare the object metadata
UCLASS()
class STAIRWAYTEST_API UMetadata_EnemyCharacter_Warrior : public UCombatantCharacterMetadata
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata() override;
};

UCLASS()
class STAIRWAYTEST_API AEnemyCharacter_Warrior : public AEnemyCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter_Warrior();
	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata() override;
};
