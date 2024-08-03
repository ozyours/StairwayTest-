// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class AEnemyCharacter;

/**
 * 
 */
class STAIRWAYTEST_API SEnemyCharacter_HPWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SEnemyCharacter_HPWidget)
		{
		}

		SLATE_ARGUMENT_DEFAULT(AEnemyCharacter*, EnemyCharacter) = nullptr;
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	AEnemyCharacter* EnemyCharacter = nullptr;
	FSlateBrush SlateBrush;
};
