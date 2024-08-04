// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BTNodes/BTT_GeneratePatrolDestination.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/EnemyCharacter/EnemyAIController.h"
#include "Character/EnemyCharacter/EnemyCharacter.h"
#include "Navigation/PathFollowingComponent.h"

EBTNodeResult::Type UBTT_GeneratePatrolDestination::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner()))
	{
		const auto _start_location = _ai_controller->GetBlackboardComponent()->GetValueAsVector(AEnemyAIController::BBKey_StartLocation);
		const auto _x = FMath::RandRange(-1000, 1000);
		const auto _y = FMath::RandRange(-1000, 1000);

		const auto _location = _start_location + FVector(_x, _y, 0);
		_ai_controller->GetBlackboardComponent()->SetValueAsVector(AEnemyAIController::BBKey_MoveDestinationLocation, _location);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
