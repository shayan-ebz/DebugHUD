// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS_DebugHUD.h"
#include "DebugHUDCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ATPS_DebugHUD::DrawHUD()
{
	Super::DrawHUD();

	auto PlayerCharacter = Cast<ADebugHUDCharacter>(GetOwningPawn());
	if (!ensure(PlayerCharacter))
	{
		// early return using asserts when cast for getting the player character fails
		return;
	}

	AddFloat(L"Speed", PlayerCharacter->GetVelocity().Size());
	AddBool(L"IsInTheAir", PlayerCharacter->GetCharacterMovement()->IsFalling());

}