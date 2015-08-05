// Some copyright should be here...

using UnrealBuildTool;

public class NoisePlugin : ModuleRules
{
	public NoisePlugin(TargetInfo Target)
	{
		PublicIncludePaths.AddRange(
			new string[] {
				"NoisePlugin/Public"
				
				// ... add public include paths required here ...
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"NoisePlugin/Private",
				
				// ... add other private include paths required here ...
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", "CoreUObject", "Engine"
				
				// ... add other public dependencies that you statically link with here ...
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate", "SlateCore"
				// ... add private dependencies that you statically link with here ...	
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}
