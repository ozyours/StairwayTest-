// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BTNodes/BTT_DoAttack.h"

#include "Character/EnemyCharacter/EnemyAIController.h"
#include "Character/EnemyCharacter/EnemyCharacter.h"
#include "CharacterAction/ChainedCharacterAction.h"

EBTNodeResult::Type UBTT_DoAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner()))
	{
		Cast<AEnemyCharacter>(_ai_controller->GetPawn())->GetBasicAttackAction()->BeginAction();
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
