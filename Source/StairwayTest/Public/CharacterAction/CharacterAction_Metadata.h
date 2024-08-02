#pragma once

#include "CoreMinimal.h"
#include "CharacterAction.h"

namespace Test::Metadata
{
	// Character action metadata
	struct CharacterActionMetadata
	{
		FName Param_Name = "CharacterActionName";
		FText Param_DisplayName = FText::FromString("Character Action Name");
		TSubclassOf<UCharacterAction> Param_Class = UCharacterAction::StaticClass();
	};
}
