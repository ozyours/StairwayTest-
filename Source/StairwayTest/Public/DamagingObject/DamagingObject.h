// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamagingObject.generated.h"

UCLASS()
class STAIRWAYTEST_API ADamagingObject : public AActor
{
	GENERATED_BODY()

public:
	ADamagingObject();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
