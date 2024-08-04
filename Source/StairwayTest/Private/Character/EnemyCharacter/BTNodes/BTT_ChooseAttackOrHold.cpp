// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BTNodes/BTT_ChooseAttackOrHold.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/EnemyCharacter/EnemyAIController.h"

EBTNodeResult::Type UBTT_ChooseAttackOrHold::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner()))
	{
		const auto _roll_result = FMath::RandRange(0, 100);
		if (_roll_result <= 60)
			_ai_controller->GetBlackboardComponent()->SetValueAsBool(AEnemyAIController::BBKey_DecideToAttack, true);
		else
			_ai_controller->GetBlackboardComponent()->SetValueAsBool(AEnemyAIController::BBKey_DecideToAttack, false);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
