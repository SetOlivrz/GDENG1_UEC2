// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GDENG1_UEC2 : ModuleRules
{
	public GDENG1_UEC2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
