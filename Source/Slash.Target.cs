// @Slash

using UnrealBuildTool;
using System.Collections.Generic;

public class SlashTarget : TargetRules
{
	public SlashTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Slash" } );
	}
}
