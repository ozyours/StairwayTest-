// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/Warrior/EnemyCharacter_Warrior_Action.h"

Test::Metadata::EnemyCharacter_Warrior_Action_BasicAttack_1::EnemyCharacter_Warrior_Action_BasicAttack_1()
{
	Param_Name = "EnemyWarriorBasicAttack1";
	Param_DisplayName = FText::FromString("Basic Attack 1");
	Param_Class = UEnemyCharacter_Warrior_Action_BasicAttack_1::StaticClass();
}

Test::Metadata::EnemyCharacter_Warrior_Action_BasicAttack_2::EnemyCharacter_Warrior_Action_BasicAttack_2()
{
	Param_Name = "EnemyWarriorBasicAttack2";
	Param_DisplayName = FText::FromString("Basic Attack 2");
	Param_Class = UEnemyCharacter_Warrior_Action_BasicAttack_2::StaticClass();
}

Test::Metadata::EnemyCharacter_Warrior_Action_BasicAttack::EnemyCharacter_Warrior_Action_BasicAttack()
{
	Param_Name = "EnemyWarriorBasicAttack";
	Param_DisplayName = FText::FromString("Basic Attack");
	Param_Class = UEnemyCharacter_Warrior_Action_BasicAttack::StaticClass();
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 1
// ##############################################################################
// ##############################################################################

void UEnemyCharacter_Warrior_Action_BasicAttack_1::OnBeginAction()
{
	Super::OnBeginAction();
}

void UEnemyCharacter_Warrior_Action_BasicAttack_1::OnEndAction()
{
	Super::OnEndAction();
}

void UEnemyCharacter_Warrior_Action_BasicAttack_1::OnAnimationNotify(const FName& _NotifyName)
{
	Super::OnAnimationNotify(_NotifyName);
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 2
// ##############################################################################
// ##############################################################################

void UEnemyCharacter_Warrior_Action_BasicAttack_2::OnBeginAction()
{
	Super::OnBeginAction();
}

void UEnemyCharacter_Warrior_Action_BasicAttack_2::OnEndAction()
{
	Super::OnEndAction();
}

void UEnemyCharacter_Warrior_Action_BasicAttack_2::OnAnimationNotify(const FName& _NotifyName)
{
	Super::OnAnimationNotify(_NotifyName);
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack
// ##############################################################################
// ##############################################################################

TArray<Test::Metadata::CharacterActionMetadata> UEnemyCharacter_Warrior_Action_BasicAttack::ChainActions()
{
	return
	{
		Test::Metadata::EnemyCharacter_Warrior_Action_BasicAttack_1(),
		Test::Metadata::EnemyCharacter_Warrior_Action_BasicAttack_2(),
	};
}
