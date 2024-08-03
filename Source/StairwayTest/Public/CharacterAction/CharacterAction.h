// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterAction.generated.h"

class UCharacterAction;
class ACombatantCharacter;

namespace Test::Metadata
{
	struct CharacterActionMetadata;
}

DECLARE_MULTICAST_DELEGATE_OneParam(FCharacterAction, UCharacterAction*);

/**
 *
 */
UCLASS(Abstract)
class STAIRWAYTEST_API UCharacterAction : public UObject
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata();

	virtual void BeginPlay();
	virtual void EndPlay();
	ACombatantCharacter* GetCombatantCharacterOwner();

protected:
	virtual void Tick(const float _DeltaTime);

private:
	ACombatantCharacter* CombatantCharacterOwner = nullptr;
	FTSTicker::FDelegateHandle DH_Tick;

	// ##############################################################################
	// ##############################################################################
	// ###########		Action Execution
	// ##############################################################################
	// ##############################################################################
public:
	void BeginAction();
	void EndAction();

	FCharacterAction OnBeginAction_Delegate;
	FCharacterAction OnEndAction_Delegate;

protected:
	virtual bool BeginActionRequirements();
	virtual bool EndActionRequirements();
	virtual void OnBeginAction();
	virtual void OnEndAction();

private:
	bool IsExecuting = false;

public:
	bool GetIsExecuting() const { return IsExecuting; }

	// ##############################################################################
	// ##############################################################################
	// ###########		Animation Notify
	// ##############################################################################
	// ##############################################################################

private:
	FDelegateHandle DH_AnimNotify;

protected:
	static constexpr const char* NotifyName_Attack = "Attack";
	static constexpr const char* NotifyName_Finish = "Finish";

	virtual void OnAnimationNotify(const FName& _NotifyName);
};
