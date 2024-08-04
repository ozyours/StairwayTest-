// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BTNodes/BTT_GenerateStrafeLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/EnemyCharacter/EnemyAIController.h"

EBTNodeResult::Type UBTT_GenerateStrafeLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner()))
	{
		const auto _start_location = _ai_controller->GetPawn()->GetActorLocation();
		constexpr float _range = 500.f;
		const auto _x = FMath::RandRange(-_range, _range);
		const auto _y = FMath::RandRange(-_range, _range);

		const auto _location = _start_location + FVector(_x, _y, 0);
		_ai_controller->GetBlackboardComponent()->SetValueAsVector(AEnemyAIController::BBKey_MoveDestinationLocation, _location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
