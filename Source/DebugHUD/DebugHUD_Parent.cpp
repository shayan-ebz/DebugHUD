// Fill out your copyright notice in the Description page of Project Settings.

#include "DebugHUD_Parent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Public/CanvasItem.h"
#include "Engine/Canvas.h"


ADebugHUD_Parent::ADebugHUD_Parent()
{
	// find the Roboto font and use it as the main font.
	ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Engine/EngineFonts/Roboto"));

	RenderedFont = Font.Object;
}

void ADebugHUD_Parent::DrawHUD()
{
	// if we don't set the value of X and Y every frame they will be increased every frame and the statistics will move out the screen very fast.
	X = Y = 50.f;
}

void ADebugHUD_Parent::AddText(const TCHAR* entityName, const FText& entityValue)
{
	RenderTypesIntoDisplay(entityName, entityValue);
}

void ADebugHUD_Parent::AddFloat(const TCHAR* entityName, float entityValue)
{
	RenderTypesIntoDisplay(entityName, FText::AsNumber(entityValue)); //FText::AsNumber() casts the float into FText Type
}

void ADebugHUD_Parent::AddInt(const TCHAR* entityName, int32 entityValue)
{
	RenderTypesIntoDisplay(entityName, FText::AsNumber(entityValue)); // same casting happens but for int32.
}

void ADebugHUD_Parent::AddBool(const TCHAR* entityName, bool entityValue)
{
	if (entityValue == true)
	{
		RenderTypesIntoDisplay(entityName, FText::FromString(TEXT("true")), FColor::Green);
	}
	else
	{
		RenderTypesIntoDisplay(entityName, FText::FromString(TEXT("false")), FColor::Red);
	}
}

void ADebugHUD_Parent::RenderTypesIntoDisplay(const TCHAR* entityName, const FText& entityValue, const FLinearColor& color)
{
	// draw the name of this entity (first column)
	FCanvasTextItem column1(FVector2D(X, Y), FText::FromString(entityName), RenderedFont, color);
	column1.EnableShadow(FColor::Black);
	Canvas->DrawItem(column1);

	// draw the valu of the entity in fromt of it (with the offset in the X direction)
	FCanvasTextItem column2(FVector2D(X + HorizontalOffset, Y), entityValue, RenderedFont, color);
	column2.EnableShadow(FColor::Black);
	Canvas->DrawItem(column2);

	// add a vertical offset for the next line
	Y += LineHeight;
}
