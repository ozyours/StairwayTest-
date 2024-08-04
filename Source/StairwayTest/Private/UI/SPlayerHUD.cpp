// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SPlayerHUD.h"

#include "SlateOptMacros.h"
#include "Character/StatsComponent.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"
#include "Widgets/Layout/SConstraintCanvas.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SPlayerHUD::Construct(const FArguments& InArgs)
{
	PlayerCharacter = InArgs._PlayerCharacter;
	check(PlayerCharacter);

	ChildSlot
	[
		SNew(SConstraintCanvas)

		+ SConstraintCanvas::Slot().Anchors(FAnchors(0.039509, 0.9, 0.279241, 0.930555))
		[
			SNew(SBorder).BorderImage(&SlateBrush).BorderBackgroundColor(FLinearColor::Black)
			[
				SNew(SImage).Image(&SlateBrush).ColorAndOpacity(FLinearColor::Red)
				.RenderTransformPivot(FVector2D(0.f, 0.5f))
				.RenderTransform_Lambda([this]()
				{
					return
						FSlateRenderTransform(TScale2<float>(static_cast<float>(PlayerCharacter->GetStatsComponent()->GetCurrentHP()) / PlayerCharacter->GetStatsComponent()->GetHP(),
						                                     1));
				})
			]
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
