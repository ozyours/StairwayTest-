#include "Character/CombatantCharacter_Metadata.h"

bool Test::Metadata::CombatantCharacterMetadata::operator==(const CombatantCharacterMetadata& Other) const
{
	return Param_Name == Other.Param_Name &&
		Param_DisplayName.EqualTo(Other.Param_DisplayName) &&
		Param_Class == Other.Param_Class;
}
