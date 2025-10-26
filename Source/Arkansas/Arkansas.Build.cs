using UnrealBuildTool;

public class Arkansas : ModuleRules {
    public Arkansas(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AkAudio",
            "AnimGraphRuntime",
            "BinkMediaPlayer",
            "CinematicCamera",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            //"GameTelemetry",
            "GameplayCameras",
            "GameplayTags",
            "GameplayTasks",
            "Gauntlet",
            "InputCore",
            "LevelSequence",
            "MediaAssets",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "Niagara",
            "NiagaraAnimNotifies",
            "OEIAimAssist",
            "OEIAnimProxyRuntime",
            "OEIAnimationRuntime",
            "OEICharacterCustomization",
            "OEICinematics",
            "OEICommon",
            "OEICrowdManagerRuntime",
            "OEIFlowCharts",
            "OEIGlobalVariables",
            "OEIMultiSkeletalMesh",
            "OEIMusic",
            "OEIPlatformService",
            "OEIScripting",
            "OEISettings",
            "OEIText",
            "OEITickManager",
            "OEIVoiceOver",
            "OEIWeatherSystemRuntime",
            "OEIWorldScriptActor",
            "OEIWwise",
            "PhysicsCore",
            //"PrefabricatorRuntime",
            "Slate",
            "SlateCore",
            "TemplateSequence",
            "UMG",
            "Launch",
        });

        /*PrivateDependencyModuleNames.AddRange(new string[] {
            "Chaos",
            "GeometryProcessing",
            "GeometryAlgorithms",
            "DynamicMesh",
            "RHI",
            "RenderCore",
        });*/

    }
}
