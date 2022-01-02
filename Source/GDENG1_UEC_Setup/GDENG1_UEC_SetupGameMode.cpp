// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDENG1_UEC_SetupGameMode.h"
#include "GDENG1_UEC_SetupHUD.h"
#include "GDENG1_UEC_SetupCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGDENG1_UEC_SetupGameMode::AGDENG1_UEC_SetupGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGDENG1_UEC_SetupHUD::StaticClass();
}
