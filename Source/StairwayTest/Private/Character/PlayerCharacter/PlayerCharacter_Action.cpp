#include "Character/PlayerCharacter/PlayerCharacter_Action.h"

#include "Character/CombatantCharacter.h"
#include "Character/CombatantCharacterAnimation.h"
#include "Character/PlayerCharacter/PlayerCharacter_Attack.h"

Test::Metadata::PlayerCharacter_Action_BasicAttack_1::PlayerCharacter_Action_BasicAttack_1()
{
	Param_Name = "PlayerBasicAttack1";
	Param_DisplayName = FText::FromString("Basic Attack 1");
	Param_Class = UPlayerCharacter_Action_BasicAttack_1::StaticClass();
}

Test::Metadata::PlayerCharacter_Action_BasicAttack_2::PlayerCharacter_Action_BasicAttack_2()
{
	Param_Name = "PlayerBasicAttack2";
	Param_DisplayName = FText::FromString("Basic Attack 2");
	Param_Class = UPlayerCharacter_Action_BasicAttack_2::StaticClass();
}

Test::Metadata::PlayerCharacter_Action_BasicAttack_3::PlayerCharacter_Action_BasicAttack_3()
{
	Param_Name = "PlayerBasicAttack3";
	Param_DisplayName = FText::FromString("Basic Attack 3");
	Param_Class = UPlayerCharacter_Action_BasicAttack_3::StaticClass();
}

Test::Metadata::PlayerCharacter_Action_BasicAttack::PlayerCharacter_Action_BasicAttack()
{
	Param_Name = "PlayerBasicAttack";
	Param_DisplayName = FText::FromString("Basic Attack");
	Param_Class = UPlayerCharacter_Action_BasicAttack::StaticClass();
}

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 1
// ##############################################################################
// ##############################################################################

void UPlayerCharacter_Action_BasicAttack_1::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 0;
}

void UPlayerCharacter_Action_BasicAttack_1::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
}

void UPlayerCharacter_Action_BasicAttack_1::OnAnimationNotify(const FName& _NotifyName)
{
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

void UPlayerCharacter_Action_BasicAttack_2::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 1;
}

void UPlayerCharacter_Action_BasicAttack_2::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
}

void UPlayerCharacter_Action_BasicAttack_2::OnAnimationNotify(const FName& _NotifyName)
{
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
// ###########		Basic Attack 3
// ##############################################################################
// ##############################################################################

void UPlayerCharacter_Action_BasicAttack_3::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 2;
}

void UPlayerCharacter_Action_BasicAttack_3::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
}

void UPlayerCharacter_Action_BasicAttack_3::OnAnimationNotify(const FName& _NotifyName)
{
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
// ###########		Basic Attack
// ##############################################################################
// ##############################################################################

TArray<Test::Metadata::CharacterActionMetadata> UPlayerCharacter_Action_BasicAttack::ChainActions()
{
	return {
		Test::Metadata::PlayerCharacter_Action_BasicAttack_1(),
		Test::Metadata::PlayerCharacter_Action_BasicAttack_2(),
		Test::Metadata::PlayerCharacter_Action_BasicAttack_3(),
	};
}
