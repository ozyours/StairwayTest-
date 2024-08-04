// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/BTNodes/BTS_AIPerceptionService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/EnemyCharacter/EnemyAIController.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"
#include "Perception/AIPerceptionComponent.h"

void UBTS_AIPerceptionService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto* _ai_controller = Cast<AEnemyAIController>(OwnerComp.GetOwner());

	if (auto* _player_character = Cast<APlayerCharacter>(_ai_controller->GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::BBKey_PlayerTarget)))
	{
		if (FVector::Distance(_player_character->GetActorLocation(), _ai_controller->GetPawn()->GetActorLocation()) <= 3000.f)
		{
			_ai_controller->GetBlackboardComponent()->SetValueAsBool(AEnemyAIController::BBKey_IsTargetValid, true);
		}
		else
		{
			_ai_controller->GetBlackboardComponent()->SetValueAsBool(AEnemyAIController::BBKey_IsTargetValid, false);
		}
	}
	else
	{
		_ai_controller->GetBlackboardComponent()->SetValueAsBool(AEnemyAIController::BBKey_IsTargetValid, false);
	}
}
