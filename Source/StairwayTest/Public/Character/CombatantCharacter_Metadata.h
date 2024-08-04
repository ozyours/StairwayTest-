#pragma once

#include "CoreMinimal.h"
#include "CombatantCharacter.h"
#include "CharacterAction/CharacterAction_Metadata.h"

namespace Test::Metadata
{
	// Character metadata
	// Contain any information of the character
	struct CombatantCharacterMetadata
	{
		FName Param_Name = "CharacterName";
		FText Param_DisplayName = FText::FromString("Character Display Name");
		TSubclassOf<ACombatantCharacter> Param_Class = ACombatantCharacter::StaticClass();
		FString Param_AssetPath;
		CharacterActionMetadata Param_BasicAttackAction;

		bool Param_PlayerTeam = true;
		uint64 Param_HP = 1000;
		uint64 Param_Attack = 100;

		bool operator==(const CombatantCharacterMetadata& Other) const;
	};
}
