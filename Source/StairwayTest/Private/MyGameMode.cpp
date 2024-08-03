// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = ConstructorHelpers::FClassFinder<AActor>(TEXT("/Script/Engine.Blueprint'/Game/Test/CombatantCharacter/PlayerCharacter/BP_PlayerCharacter.BP_PlayerCharacter_C'")).Class;
}
