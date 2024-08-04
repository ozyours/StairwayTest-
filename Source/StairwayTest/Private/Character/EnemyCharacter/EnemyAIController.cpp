// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Team.h"

// Sets default values
AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	BehaviorTree = ConstructorHelpers::FObjectFinder<UBehaviorTree>(TEXT("/Script/AIModule.BehaviorTree'/Game/Test/CombatantCharacter/EnemyCharacter/BT_EnemyAI.BT_EnemyAI'")).Object;

	SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AISenseConfig"));
	auto _sense_filter = FAISenseAffiliationFilter();
	_sense_filter.bDetectEnemies = true;
	_sense_filter.bDetectFriendlies = true;
	_sense_filter.bDetectNeutrals = true;
	SightSense->DetectionByAffiliation = _sense_filter;
	SightSense->SightRadius = 1000.f;
	SightSense->LoseSightRadius = 1500.f;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	AIPerceptionComponent->ConfigureSense(*SightSense);
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetPerceptionInfoUpdate);
}

// Called when the game starts or when spawned
void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UBlackboardComponent* _blackboard_component = nullptr;
	UseBlackboard(LoadObject<UBlackboardData>(nullptr, TEXT("/Script/AIModule.BlackboardData'/Game/Test/CombatantCharacter/EnemyCharacter/BB_EnemyAI.BB_EnemyAI'")), _blackboard_component);
	RunBehaviorTree(LoadObject<UBehaviorTree>(nullptr, TEXT("/Script/AIModule.BehaviorTree'/Game/Test/CombatantCharacter/EnemyCharacter/BT_EnemyAI.BT_EnemyAI'")));

	GetBlackboardComponent()->SetValueAsVector(BBKey_StartLocation, GetPawn()->GetActorLocation());
}

void AEnemyAIController::OnTargetPerceptionInfoUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (auto* _player_character = Cast<APlayerCharacter>(Actor))
	{
		if (Stimulus.IsActive())
			GetBlackboardComponent()->SetValueAsObject(BBKey_PlayerTarget, _player_character);
		else
			GetBlackboardComponent()->SetValueAsObject(BBKey_PlayerTarget, nullptr);
	}
}
