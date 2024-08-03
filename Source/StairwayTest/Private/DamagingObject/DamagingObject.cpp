// Fill out your copyright notice in the Description page of Project Settings.

#include "DamagingObject/DamagingObject.h"

ADamagingObject::ADamagingObject()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADamagingObject::BeginPlay()
{
	Super::BeginPlay();
}

void ADamagingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
