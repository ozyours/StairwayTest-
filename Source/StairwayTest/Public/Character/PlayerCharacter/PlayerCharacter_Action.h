#pragma once

#include "CharacterAction/CharacterAction.h"
#include "CharacterAction/CharacterAction_Metadata.h"
#include "PlayerCharacter_Action.generated.h"

namespace Test::Metadata
{
	struct PlayerCharacter_Action_BasicAttack_1 : CharacterActionMetadata
	{
		PlayerCharacter_Action_BasicAttack_1();
	};

	struct PlayerCharacter_Action_BasicAttack_2 : CharacterActionMetadata
	{
		PlayerCharacter_Action_BasicAttack_2();
	};

	struct PlayerCharacter_Action_BasicAttack_3 : CharacterActionMetadata
	{
		PlayerCharacter_Action_BasicAttack_3();
	};

	struct PlayerCharacter_Action_BasicAttack : CharacterActionMetadata
	{
		PlayerCharacter_Action_BasicAttack();
	};
};


// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 1
// ##############################################################################
// ##############################################################################

// Basic Attack 1
UCLASS()
class UPlayerCharacter_Action_BasicAttack_1 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacter_Action_BasicAttack_1(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
	virtual void OnAnimationNotify(const FName& _NotifyName) override;
};

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 2
// ##############################################################################
// ##############################################################################

// Basic Attack 2
UCLASS()
class UPlayerCharacter_Action_BasicAttack_2 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacter_Action_BasicAttack_2(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
	virtual void OnAnimationNotify(const FName& _NotifyName) override;
};

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack 3
// ##############################################################################
// ##############################################################################

// Basic Attack 3
UCLASS()
class UPlayerCharacter_Action_BasicAttack_3 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacter_Action_BasicAttack_3(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
	virtual void OnAnimationNotify(const FName& _NotifyName) override;
};

// ##############################################################################
// ##############################################################################
// ###########		Basic Attack
// ##############################################################################
// ##############################################################################

// Basic Attack
UCLASS()
class UPlayerCharacter_Action_BasicAttack : public UChainedCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacter_Action_BasicAttack(); }

protected:
	virtual TArray<Test::Metadata::CharacterActionMetadata> ChainActions() override;
};
