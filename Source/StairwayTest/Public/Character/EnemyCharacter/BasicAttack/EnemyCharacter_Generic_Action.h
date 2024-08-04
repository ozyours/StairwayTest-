// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterAction/CharacterAction.h"
#include "CharacterAction/CharacterAction_Metadata.h"
#include "EnemyCharacter_Generic_Action.generated.h"

namespace Test::Metadata
{
	struct EnemyCharacter_Generic_Action_BasicAttack_1 : CharacterActionMetadata
	{
		EnemyCharacter_Generic_Action_BasicAttack_1();
	};

	struct EnemyCharacter_Generic_Action_BasicAttack_2 : CharacterActionMetadata
	{
		EnemyCharacter_Generic_Action_BasicAttack_2();
	};

	struct EnemyCharacter_Generic_Action_BasicAttack : CharacterActionMetadata
	{
		EnemyCharacter_Generic_Action_BasicAttack();
	};
};

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 1
// ##############################################################################
// ##############################################################################

// Basic Attack 1
UCLASS()
class STAIRWAYTEST_API UEnemyCharacter_Generic_Action_BasicAttack_1 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack_1(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
	virtual void OnAnimationNotify(const FName& _NotifyName) override;
};

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 2
// ##############################################################################
// ##############################################################################

// Basic Attack 2
UCLASS()
class STAIRWAYTEST_API UEnemyCharacter_Generic_Action_BasicAttack_2 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack_2(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
	virtual void OnAnimationNotify(const FName& _NotifyName) override;
};

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack
// ##############################################################################
// ##############################################################################

// Basic Attack
UCLASS()
class STAIRWAYTEST_API UEnemyCharacter_Generic_Action_BasicAttack : public UChainedCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack(); }

protected:
	virtual TArray<Test::Metadata::CharacterActionMetadata> ChainActions() override;
};
