// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DebugHUD_Parent.generated.h"

/**
 * 
 */
UCLASS()
class DEBUGHUD_API ADebugHUD_Parent : public AHUD
{
	GENERATED_BODY()

/////////////////////////////////////////////// data members
protected:

	// font used to render the debug information.
	UPROPERTY(Transient)
	UFont* RenderedFont = nullptr;

private:

	// current X coordinate in pixels
	float X = 50.0f;

	// current Y coordinate in pixels
	float Y = 50.0f;

	// vertical space between debug lines in pixels
	float LineHeight = 20.0f;

	// horizontal offset to render the statistic values in pixels
	float HorizontalOffset = 150.0f;

/////////////////////////////////////////////// methods
public:
	
	// sets the default values for the data members such as the font.
	ADebugHUD_Parent();

protected:
	
	// Draws the HUD every frame.
	virtual void DrawHUD() override;

	// helper functions to add different types of entities into the screen by calling RenderTypesIntoDisplay.
	void AddText(const TCHAR* entityName, const FText& entityValue);
	void AddFloat(const TCHAR* entityName, float entityValue);
	void AddInt(const TCHAR* entityName, int32 entityValue);
	void AddBool(const TCHAR* entityName, bool entityValue);


private:

	// renders the entity name and its value onto the screen.
	void RenderTypesIntoDisplay(const TCHAR* entityName, const FText& entityValue, const FLinearColor& color = FColor::White);
};
