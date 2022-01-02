// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GDENG1_UEC_SetupHUD.generated.h"

UCLASS()
class AGDENG1_UEC_SetupHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGDENG1_UEC_SetupHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

