// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BasicAttack/EnemyCharacter_Generic_Action.h"

#include "Character/CombatantCharacter.h"
#include "Character/CombatantCharacterAnimation.h"
#include "Character/PlayerCharacter/PlayerCharacter_Attack.h"

Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack_1::EnemyCharacter_Generic_Action_BasicAttack_1()
{
	Param_Name = "EnemyCharacterBasicAttack1";
	Param_DisplayName = FText::FromString("Basic Attack 1");
	Param_Class = UEnemyCharacter_Generic_Action_BasicAttack_1::StaticClass();
}

Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack_2::EnemyCharacter_Generic_Action_BasicAttack_2()
{
	Param_Name = "EnemyCharacterBasicAttack2";
	Param_DisplayName = FText::FromString("Basic Attack 2");
	Param_Class = UEnemyCharacter_Generic_Action_BasicAttack_2::StaticClass();
}

Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack::EnemyCharacter_Generic_Action_BasicAttack()
{
	Param_Name = "EnemyCharacterBasicAttack";
	Param_DisplayName = FText::FromString("Basic Attack");
	Param_Class = UEnemyCharacter_Generic_Action_BasicAttack::StaticClass();
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 1
// ##############################################################################
// ##############################################################################

void UEnemyCharacter_Generic_Action_BasicAttack_1::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 0;
}

void UEnemyCharacter_Generic_Action_BasicAttack_1::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
}

void UEnemyCharacter_Generic_Action_BasicAttack_1::OnAnimationNotify(const FName& _NotifyName)
{
	Super::OnAnimationNotify(_NotifyName);
	if (_NotifyName == NotifyName_Attack)
	{
		const auto _location = GetCombatantCharacterOwner()->GetActorLocation();
		const auto _direction = GetCombatantCharacterOwner()->GetActorForwardVector();
		auto* _attack = GetWorld()->SpawnActor<APlayerCharacter_Attack_BasicAttack>(_location + _direction * 100.f, _direction.Rotation());
		_attack->Activate(GetCombatantCharacterOwner()->GetStatsComponent());
	}
	else if (_NotifyName == NotifyName_Finish)
	{
		EndAction();
	}
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 2
// ##############################################################################
// ##############################################################################

void UEnemyCharacter_Generic_Action_BasicAttack_2::OnBeginAction()
{
	Super::OnBeginAction();
}

void UEnemyCharacter_Generic_Action_BasicAttack_2::OnEndAction()
{
	Super::OnEndAction();
}

void UEnemyCharacter_Generic_Action_BasicAttack_2::OnAnimationNotify(const FName& _NotifyName)
{
	Super::OnAnimationNotify(_NotifyName);
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack
// ##############################################################################
// ##############################################################################

TArray<Test::Metadata::CharacterActionMetadata> UEnemyCharacter_Generic_Action_BasicAttack::ChainActions()
{
	return
	{
		Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack_1(),
		Test::Metadata::EnemyCharacter_Generic_Action_BasicAttack_2(),
	};
}
