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
		CharacterActionMetadata Param_BasicAttackAction;

		uint64 Param_HP = 1000;
	};
}
