// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CombatantCharacter_MetadataObject.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnArea.generated.h"

class UTextRenderComponent;
class UBoxComponent;

UCLASS()
class STAIRWAYTEST_API AEnemySpawnArea : public AActor
{
	GENERATED_BODY()

public:
	AEnemySpawnArea();

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

	// ##############################################################################
	// ##############################################################################
	// ###########		Component
	// ##############################################################################
	// ##############################################################################

private:
	UPROPERTY()
	USceneComponent* Root;
	UPROPERTY()
	UBoxComponent* BoxComponent;
	UPROPERTY()
	UTextRenderComponent* RespawnText;

	UPROPERTY(EditAnywhere, Category = "EnemySpawnArea")
	FVector BoxExtent = FVector(100.f);

	UPROPERTY(EditAnywhere, Category = "EnemySpawnArea")
	TMap<TSubclassOf<UCombatantCharacterMetadata>, uint32> EnemyMetadata;

	// ##############################################################################
	// ##############################################################################
	// ###########		Spawning
	// ##############################################################################
	// ##############################################################################

private:
	FVector RandomizeSpawnLocation() const;
	TArray<UStatsComponent*> SpawnedCharacters;
	TArray<FDelegateHandle> DH_SpawnedCharacters;
	void SpawnCharacters();
	void OnSpawnedCharacterEliminated(UStatsComponent* _stats_component);
	// Respawn timer after all spawned characters are eliminated (in seconds)
	static constexpr float RespawnTimer = 8.f;
	FTimerHandle TH_Respawn;
};
