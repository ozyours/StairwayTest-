// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BTNodes/BTS_FocusPlayerTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/EnemyCharacter/EnemyAIController.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

UBTS_FocusPlayerTarget::UBTS_FocusPlayerTarget()
{
	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = true;
}

void UBTS_FocusPlayerTarget::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner()))
	{
		if (auto* _player_character = Cast<APlayerCharacter>(_ai_controller->GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::BBKey_PlayerTarget)))
		{
			_ai_controller->SetFocus(_player_character);
		}
	}
}

void UBTS_FocusPlayerTarget::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner()))
	{
		_ai_controller->ClearFocus(EAIFocusPriority::Default);
	}
}
