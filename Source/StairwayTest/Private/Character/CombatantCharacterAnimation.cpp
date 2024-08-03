// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/CombatantCharacterAnimation.h"

#include "Character/CombatantCharacter.h"
#include "CharacterAction/ChainedCharacterAction.h"
#include "GameFramework/PawnMovementComponent.h"

void UCombatantCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (const auto* _combatant_character = Cast<ACombatantCharacter>(TryGetPawnOwner()))
	{
		// Update is running
		{
			const auto* _movement_component = _combatant_character->GetMovementComponent();
			if (_movement_component->Velocity.Length() > 1 && !_movement_component->IsFalling())
			{
				IsRunning = true;
			}
			else
			{
				IsRunning = false;
			}
		}

		// Update basic attack
		if (_combatant_character->GetBasicAttackAction())
		{
			BasicAttackIndex = _combatant_character->GetBasicAttackAction()->GetChainIndex() - 1;
		}
	}
}