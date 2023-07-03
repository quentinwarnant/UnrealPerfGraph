using System.IO;
using UnrealBuildTool;

public class UnrealPerfGraph : ModuleRules
{
    public UnrealPerfGraph(ReadOnlyTargetRules Target) : base(Target)
    {

        PublicIncludePaths.AddRange(
            new string[] {
               // Path.Combine(ModuleDirectory, "Public"),
                Path.Combine(PluginDirectory, "Source/Thirdparty/ImGui/imgui"),
                Path.Combine(PluginDirectory, "Source/Thirdparty/ImGui/implot"),
            }
		);

        // PublicDependencyModuleNames.Add("Core");
        // PrivateDependencyModuleNames.Add("RenderCore");
        // PrivateDependencyModuleNames.Add("Projects");

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "RenderCore",
                "InputCore",
                "ApplicationCore",
                "RHI",
                // "Slate",
                // "SlateCore",
            }
        );




        if (Target.Configuration == UnrealTargetConfiguration.Shipping || Target.Configuration == UnrealTargetConfiguration.Test)
        {
            PublicAdditionalLibraries.Add(
                Path.Combine(PluginDirectory, "Binaries/Win64/ImGui.lib")
        );
        }
        else
        {
            PublicAdditionalLibraries.Add(
                Path.Combine(PluginDirectory, "Binaries/Win64/ImGui_Debug.lib")
            );
        }


        PublicDefinitions.Add("WITH_IMGUI=1");
    }
}
