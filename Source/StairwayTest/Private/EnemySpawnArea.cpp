// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawnArea.h"

#include "Character/StatsComponent.h"
#include "Character/EnemyCharacter/EnemyCharacter.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AEnemySpawnArea::AEnemySpawnArea()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

#if WITH_EDITOR
	auto* _sprite = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("RootSprite"));
	_sprite->SetupAttachment(GetRootComponent());
	_sprite->SetRelativeLocation(FVector(0.5f));
	_sprite->SetSprite(ConstructorHelpers::FObjectFinder<UTexture2D>(TEXT("/Script/Engine.Texture2D'/Engine/EditorResources/Ai_Spawnpoint.Ai_Spawnpoint'")).Object);
#endif

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(GetRootComponent());

	RespawnText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RespawnText"));
	RespawnText->SetupAttachment(GetRootComponent());
	RespawnText->SetRelativeLocation(FVector(0, 0, 400.f));
	RespawnText->SetWorldSize(128.f);
	RespawnText->SetText(FText::FromString("Ready"));
}

void AEnemySpawnArea::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	BoxComponent->SetBoxExtent(BoxExtent);
	BoxComponent->SetRelativeLocation(FVector(0, 0, BoxExtent.Z));
}

void AEnemySpawnArea::BeginPlay()
{
	Super::BeginPlay();
	SpawnCharacters();
}

// ##############################################################################
// ##############################################################################
// ###########		Spawning
// ##############################################################################
// ##############################################################################

FVector AEnemySpawnArea::RandomizeSpawnLocation() const
{
	const auto _x = FMath::RandRange(-BoxExtent.X, BoxExtent.X);
	const auto _y = FMath::RandRange(-BoxExtent.Y, BoxExtent.Y);
	return FVector(GetActorLocation() + FVector(_x, _y, 0));
}

void AEnemySpawnArea::SpawnCharacters()
{
	RespawnText->SetText(FText::FromString("Ready"));

	TArray<TSubclassOf<UCombatantCharacterMetadata>> _classes;
	TArray<uint32> _count;

	EnemyMetadata.GetKeys(_classes);
	EnemyMetadata.GenerateValueArray(_count);

	for (int i = 0; i < _classes.Num(); i++)
	{
		auto _class = _classes[i];
		for (uint32 j = 0; j < _count[i]; j++)
		{
			auto* _character = ACombatantCharacter::Spawn(GetWorld(), _class, RandomizeSpawnLocation(), FRotator(0, FMath::RandRange(0, 360), 0));
			SpawnedCharacters.Add(_character->GetStatsComponent());

			auto _delegate_handle = _character->GetStatsComponent()->OnEliminated_Delegate.AddUObject(this, &AEnemySpawnArea::OnSpawnedCharacterEliminated);
			DH_SpawnedCharacters.Add(_delegate_handle);
		}
	}
}

void AEnemySpawnArea::OnSpawnedCharacterEliminated(UStatsComponent* _stats_component)
{
	const auto _index = SpawnedCharacters.Find(_stats_component);
	if (_index >= 0)
	{
		SpawnedCharacters[_index]->OnEliminated_Delegate.Remove(DH_SpawnedCharacters[_index]);
		SpawnedCharacters.RemoveAt(_index);
		DH_SpawnedCharacters.RemoveAt(_index);
	}

	if (SpawnedCharacters.Num() == 0)
	{
		RespawnText->SetText(FText::FromString("Respawning"));
		if (!GetWorld()->GetTimerManager().IsTimerActive(TH_Respawn))
		{
			GetWorld()->GetTimerManager().SetTimer(TH_Respawn, [this]()
			{
				SpawnCharacters();
			}, RespawnTimer, false);
		}
	}
}
