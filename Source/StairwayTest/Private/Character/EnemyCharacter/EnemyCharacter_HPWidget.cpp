// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/EnemyCharacter/EnemyCharacter_HPWidget.h"

#include "SlateOptMacros.h"
#include "Character/StatsComponent.h"
#include "Character/EnemyCharacter/EnemyCharacter.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SEnemyCharacter_HPWidget::Construct(const FArguments& InArgs)
{
	EnemyCharacter = InArgs._EnemyCharacter;
	check(EnemyCharacter);

	ChildSlot
	[
		SNew(SBorder).BorderImage(&SlateBrush).BorderBackgroundColor(FLinearColor::Black)
		[
			SNew(SImage).Image(&SlateBrush).ColorAndOpacity(FLinearColor::Red)
			.RenderTransformPivot(FVector2D(0.f, 0.5f))
			.RenderTransform_Lambda([this]()
			{
				return
					FSlateRenderTransform(TScale2<float>(static_cast<float>(EnemyCharacter->GetStatsComponent()->GetCurrentHP()) / EnemyCharacter->GetStatsComponent()->GetHP(),
					                                     1));
			})
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
