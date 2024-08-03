// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/Knight/EnemyCharacter_Knight_Action.h"

Test::Metadata::EnemyCharacter_Knight_Action_BasicAttack_1::EnemyCharacter_Knight_Action_BasicAttack_1()
{
	Param_Name = "EnemyKnightBasicAttack1";
	Param_DisplayName = FText::FromString("Basic Attack 1");
	Param_Class = UEnemyCharacter_Knight_Action_BasicAttack_1::StaticClass();
}

Test::Metadata::EnemyCharacter_Knight_Action_BasicAttack_2::EnemyCharacter_Knight_Action_BasicAttack_2()
{
	Param_Name = "EnemyKnightBasicAttack2";
	Param_DisplayName = FText::FromString("Basic Attack 2");
	Param_Class = UEnemyCharacter_Knight_Action_BasicAttack_2::StaticClass();
}

Test::Metadata::EnemyCharacter_Knight_Action_BasicAttack::EnemyCharacter_Knight_Action_BasicAttack()
{
	Param_Name = "EnemyKnightBasicAttack";
	Param_DisplayName = FText::FromString("Basic Attack");
	Param_Class = UEnemyCharacter_Knight_Action_BasicAttack::StaticClass();
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 1
// ##############################################################################
// ##############################################################################

void UEnemyCharacter_Knight_Action_BasicAttack_1::OnBeginAction()
{
	Super::OnBeginAction();
}

void UEnemyCharacter_Knight_Action_BasicAttack_1::OnEndAction()
{
	Super::OnEndAction();
}

void UEnemyCharacter_Knight_Action_BasicAttack_1::OnAnimationNotify(const FName& _NotifyName)
{
	Super::OnAnimationNotify(_NotifyName);
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 2
// ##############################################################################
// ##############################################################################

void UEnemyCharacter_Knight_Action_BasicAttack_2::OnBeginAction()
{
	Super::OnBeginAction();
}

void UEnemyCharacter_Knight_Action_BasicAttack_2::OnEndAction()
{
	Super::OnEndAction();
}

void UEnemyCharacter_Knight_Action_BasicAttack_2::OnAnimationNotify(const FName& _NotifyName)
{
	Super::OnAnimationNotify(_NotifyName);
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack
// ##############################################################################
// ##############################################################################

TArray<Test::Metadata::CharacterActionMetadata> UEnemyCharacter_Knight_Action_BasicAttack::ChainActions()
{
	return
	{
		Test::Metadata::EnemyCharacter_Knight_Action_BasicAttack_1(),
		Test::Metadata::EnemyCharacter_Knight_Action_BasicAttack_2(),
	};
}
