// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GDENG1_UEC_Setup : ModuleRules
{
	public GDENG1_UEC_Setup(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
