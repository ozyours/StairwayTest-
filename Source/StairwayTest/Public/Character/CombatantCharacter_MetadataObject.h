#pragma once

#include "CoreMinimal.h"
#include "CombatantCharacter_Metadata.h"
#include "CombatantCharacter_MetadataObject.generated.h"

// Object based character metadata
// For linking the metadata with the editor
UCLASS(Abstract)
class UCombatantCharacterMetadata : public UObject
{
	GENERATED_BODY()

public:
	UCombatantCharacterMetadata();

	virtual Test::Metadata::CombatantCharacterMetadata CombatantCharacterMetadata();
};