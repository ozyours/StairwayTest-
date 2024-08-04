// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class APlayerCharacter;

/**
 * 
 */
class STAIRWAYTEST_API SPlayerHUD : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlayerHUD)
		{
		}

		SLATE_ARGUMENT_DEFAULT(APlayerCharacter*, PlayerCharacter) = nullptr;

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	APlayerCharacter* PlayerCharacter = nullptr;
	FSlateBrush SlateBrush;
};
