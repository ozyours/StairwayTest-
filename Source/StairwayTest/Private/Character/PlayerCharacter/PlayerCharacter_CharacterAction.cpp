#include "Character/PlayerCharacter/PlayerCharacter_CharacterAction.h"

#include "Character/CombatantCharacter.h"
#include "Character/CombatantCharacterAnimation.h"

Test::Metadata::PlayerCharacterAction_BasicAttack_1::PlayerCharacterAction_BasicAttack_1()
{
	Param_Name = "PlayerBasicAttack1";
	Param_DisplayName = FText::FromString("Basic Attack 1");
	Param_Class = UCharacterAction_PlayerBasicAttack_1::StaticClass();
}

Test::Metadata::PlayerCharacterAction_BasicAttack_2::PlayerCharacterAction_BasicAttack_2()
{
	Param_Name = "PlayerBasicAttack2";
	Param_DisplayName = FText::FromString("Basic Attack 2");
	Param_Class = UCharacterAction_PlayerBasicAttack_2::StaticClass();
}

Test::Metadata::PlayerCharacterAction_BasicAttack_3::PlayerCharacterAction_BasicAttack_3()
{
	Param_Name = "PlayerBasicAttack3";
	Param_DisplayName = FText::FromString("Basic Attack 3");
	Param_Class = UCharacterAction_PlayerBasicAttack_3::StaticClass();
}

Test::Metadata::PlayerCharacterAction_BasicAttack::PlayerCharacterAction_BasicAttack()
{
	Param_Name = "PlayerBasicAttack";
	Param_DisplayName = FText::FromString("Basic Attack");
	Param_Class = UCharacterAction_PlayerBasicAttack::StaticClass();
}

void UCharacterAction_PlayerBasicAttack_1::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 0;
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAction_PlayerBasicAttack_1::OnBeginAction"));
}

void UCharacterAction_PlayerBasicAttack_1::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAction_PlayerBasicAttack_1::OnEndAction"));
}

void UCharacterAction_PlayerBasicAttack_1::OnAnimationNotify(const FName& _NotifyName)
{
	if (_NotifyName == NotifyName_Attack)
	{
	}
	else if (_NotifyName == NotifyName_Finish)
	{
		EndAction();
	}
}

void UCharacterAction_PlayerBasicAttack_2::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 1;
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAction_PlayerBasicAttack_2::OnBeginAction"));
}

void UCharacterAction_PlayerBasicAttack_2::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAction_PlayerBasicAttack_2::OnEndAction"));
}

void UCharacterAction_PlayerBasicAttack_2::OnAnimationNotify(const FName& _NotifyName)
{
	if (_NotifyName == NotifyName_Attack)
	{
	}
	else if (_NotifyName == NotifyName_Finish)
	{
		EndAction();
	}
}

void UCharacterAction_PlayerBasicAttack_3::OnBeginAction()
{
	Super::OnBeginAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = 2;
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAction_PlayerBasicAttack_3::OnBeginAction"));
}

void UCharacterAction_PlayerBasicAttack_3::OnEndAction()
{
	Super::OnEndAction();
	Cast<UCombatantCharacterAnimation>(GetCombatantCharacterOwner()->GetMesh()->GetAnimInstance())->BasicAttackIndex = -1;
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAction_PlayerBasicAttack_3::OnEndAction"));
}

void UCharacterAction_PlayerBasicAttack_3::OnAnimationNotify(const FName& _NotifyName)
{
	if (_NotifyName == NotifyName_Attack)
	{
	}
	else if (_NotifyName == NotifyName_Finish)
	{
		EndAction();
	}
}

TArray<Test::Metadata::CharacterActionMetadata> UCharacterAction_PlayerBasicAttack::ChainActions()
{
	return {
		Test::Metadata::PlayerCharacterAction_BasicAttack_1(),
		Test::Metadata::PlayerCharacterAction_BasicAttack_2(),
		Test::Metadata::PlayerCharacterAction_BasicAttack_3(),
	};
}
