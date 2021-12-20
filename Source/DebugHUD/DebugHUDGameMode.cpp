// Copyright Epic Games, Inc. All Rights Reserved.

#include "DebugHUDGameMode.h"
#include "DebugHUDCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADebugHUDGameMode::ADebugHUDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TPS/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
