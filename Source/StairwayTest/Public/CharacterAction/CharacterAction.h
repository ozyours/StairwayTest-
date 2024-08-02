// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterAction.generated.h"

namespace Test::Metadata
{
	struct CharacterActionMetadata;
}

class UCharacterAction;

DECLARE_DELEGATE_OneParam(FCharacterAction, UCharacterAction*);

/**
 * 
 */
UCLASS(Abstract)
class STAIRWAYTEST_API UCharacterAction : public UObject
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata();
	void BeginAction();
	void EndAction();

	FCharacterAction OnBeginAction_Delegate;
	FCharacterAction OnEndAction_Delegate;

protected:
	virtual void OnBeginAction();
	virtual void OnEndAction();

private:
	bool IsCasting = false;
};
