// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDENG1_UEC2GameMode.h"
#include "GDENG1_UEC2HUD.h"
#include "GDENG1_UEC2Character.h"
#include "UObject/ConstructorHelpers.h"

AGDENG1_UEC2GameMode::AGDENG1_UEC2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGDENG1_UEC2HUD::StaticClass();
}
