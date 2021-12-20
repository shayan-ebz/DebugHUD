// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DebugHUD_Parent.h"
#include "TPS_DebugHUD.generated.h"

/**
 * 
 */
UCLASS()
class DEBUGHUD_API ATPS_DebugHUD : public ADebugHUD_Parent
{
	GENERATED_BODY()

protected:

	// Ticks every frame and draws the data onto the screen by calling parent functions.
	virtual void DrawHUD() override;
	
};
