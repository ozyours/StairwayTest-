// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAction/CharacterAction.h"

#include "CharacterAction/CharacterAction_Metadata.h"

Test::Metadata::CharacterActionMetadata UCharacterAction::CharacterActionMetadata()
{
	unimplemented();
	return Test::Metadata::CharacterActionMetadata();
}

void UCharacterAction::BeginAction()
{
	if (IsCasting)
		return;

	IsCasting = true;
	OnBeginAction();
}

void UCharacterAction::EndAction()
{
	if (!IsCasting)
		return;

	IsCasting = false;
	OnEndAction();
}

void UCharacterAction::OnBeginAction()
{
	OnBeginAction_Delegate.ExecuteIfBound(this);
}

void UCharacterAction::OnEndAction()
{
	OnEndAction_Delegate.ExecuteIfBound(this);
}
