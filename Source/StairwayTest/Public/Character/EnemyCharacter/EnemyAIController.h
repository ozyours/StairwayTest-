// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UAISenseConfig_Team;
class UAISenseConfig_Sight;
class UAIPerceptionComponent;

UCLASS()
class STAIRWAYTEST_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY()
	UBehaviorTree* BehaviorTree = nullptr;

	UPROPERTY(VisibleAnywhere)
	UAIPerceptionComponent* AIPerceptionComponent;

	UPROPERTY()
	UAISenseConfig_Sight* SightSense;

	UFUNCTION()
	void OnTargetPerceptionInfoUpdate(AActor* Actor, struct FAIStimulus Stimulus);

public:
	static constexpr const char* BBKey_PlayerTarget = "PlayerTarget";
	static constexpr const char* BBKey_IsTargetValid = "IsTargetValid";
	static constexpr const char* BBKey_StartLocation = "StartLocation";
	static constexpr const char* BBKey_MoveDestinationLocation = "MoveDestinationLocation";
	static constexpr const char* BBKey_DecideToAttack = "DecideToAttack";
};
