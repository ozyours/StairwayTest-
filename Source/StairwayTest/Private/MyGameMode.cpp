// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
}