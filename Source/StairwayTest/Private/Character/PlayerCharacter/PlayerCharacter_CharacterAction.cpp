#include "Character/PlayerCharacter/PlayerCharacter_CharacterAction.h"

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
}

void UCharacterAction_PlayerBasicAttack_1::OnEndAction()
{
	Super::OnEndAction();
}

void UCharacterAction_PlayerBasicAttack_2::OnBeginAction()
{
	Super::OnBeginAction();
}

void UCharacterAction_PlayerBasicAttack_2::OnEndAction()
{
	Super::OnEndAction();
}

void UCharacterAction_PlayerBasicAttack_3::OnBeginAction()
{
	Super::OnBeginAction();
}

void UCharacterAction_PlayerBasicAttack_3::OnEndAction()
{
	Super::OnEndAction();
}

void UCharacterAction_PlayerBasicAttack::OnBeginAction()
{
	Super::OnBeginAction();
}

void UCharacterAction_PlayerBasicAttack::OnEndAction()
{
	Super::OnEndAction();
}