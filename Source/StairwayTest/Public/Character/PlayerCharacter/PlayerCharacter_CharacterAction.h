#pragma once

#include "CharacterAction/CharacterAction.h"
#include "CharacterAction/CharacterAction_Metadata.h"
#include "PlayerCharacter_CharacterAction.generated.h"

namespace Test::Metadata
{
	struct PlayerCharacterAction_BasicAttack_1 : CharacterActionMetadata
	{
		PlayerCharacterAction_BasicAttack_1();
	};

	struct PlayerCharacterAction_BasicAttack_2 : CharacterActionMetadata
	{
		PlayerCharacterAction_BasicAttack_2();
	};

	struct PlayerCharacterAction_BasicAttack_3 : CharacterActionMetadata
	{
		PlayerCharacterAction_BasicAttack_3();
	};

	struct PlayerCharacterAction_BasicAttack : CharacterActionMetadata
	{
		PlayerCharacterAction_BasicAttack();
	};
};

UCLASS()
class UCharacterAction_PlayerBasicAttack_1 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacterAction_BasicAttack_1(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
};

UCLASS()
class UCharacterAction_PlayerBasicAttack_2 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacterAction_BasicAttack_2(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
};

UCLASS()
class UCharacterAction_PlayerBasicAttack_3 : public UCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacterAction_BasicAttack_3(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;
};

UCLASS()
class UCharacterAction_PlayerBasicAttack : public UChainedCharacterAction
{
	GENERATED_BODY()

public:
	virtual Test::Metadata::CharacterActionMetadata CharacterActionMetadata() override { return Test::Metadata::PlayerCharacterAction_BasicAttack(); }

protected:
	virtual void OnBeginAction() override;
	virtual void OnEndAction() override;

	virtual TArray<Test::Metadata::CharacterActionMetadata> ChainActions() override;
};
