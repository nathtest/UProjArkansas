#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EWindowMode -FallbackName=EWindowMode
#include "GameFrameWork\GameUserSettings.h"
#include "InputCoreTypes.h"
#include "GameFramework/InputSettings.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InputActionKeyMapping -FallbackName=InputActionKeyMapping
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InputAxisKeyMapping -FallbackName=InputAxisKeyMapping
#include "ECompanionHelmetVisibility.h"
#include "EControlInputPreference.h"
#include "EFPSLimit.h"
#include "EFSR3QualityMode.h"
#include "EFrameGenerationMethod.h"
#include "EHUDWidgetVisibilityMode.h"
#include "ELanguageMode.h"
#include "ELatencyReductionMethod.h"
#include "EMotionSicknessMode.h"
#include "EOWDLSSFrameGenerationMode.h"
#include "EOWDLSSMode.h"
#include "EOWNvidiaReflexMode.h"
#include "EOWXeSSQualityMode.h"
#include "EResolutionQualityPreset.h"
#include "EReticleMode.h"
#include "ESuperSampler.h"
#include "EVisualMode.h"
#include "EWeaponTooltipStatMode.h"
#include "IndianaGameUserSettings.generated.h"

UCLASS(Blueprintable, Config=Engine)
class ARKANSAS_API UIndianaGameUserSettings : public UGameUserSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SettingsDefaultVersion;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MasterSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EffectsSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MusicSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UISoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VoiceSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bXAxisInverted;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bControllerXAxisInverted;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bYAxisInverted;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bControllerYAxisInverted;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bControllerAutoSprintEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bControllerAdaptiveTriggersEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bControllerLightBarEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EControlInputPreference InputPreferenceADS;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EControlInputPreference InputPreferenceCrouch;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EControlInputPreference InputPreferenceSprint;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseADSSensitivityValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadialSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerADSSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bControllerRumbleEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerLeftInnerDeadZone;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerLeftOuterDeadZone;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerRightInnerDeadZone;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerRightOuterDeadZone;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECompanionHelmetVisibility CompanionHelmetVisibility;
    
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GamepadLayout;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StickLayout;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> AddedActionKeyBinds;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> RemovedActionKeyBinds;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputAxisKeyMapping> AddedAxisKeyBinds;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputAxisKeyMapping> RemovedAxisKeyBinds;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionKeyMapping> CustomGamepadBindings;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPseudoGodMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGodMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLastConfirmedVSync;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MotionBlurScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedMotionBlurScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LastGraphicsQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVisualMode VisualMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVisualMode VisualModeXSS;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVRREnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GammaLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedGammaLevel;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFPSLimit FPSLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFPSLimit LastConfirmedFPSLimit;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESuperSampler UpscalingMethod;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFSR3QualityMode FSR3QualityMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FSR3Sharpness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOWXeSSQualityMode XeSSQualityMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOWDLSSMode DLSSQualityMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOWDLSSFrameGenerationMode DLSSFrameGenerationMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOWNvidiaReflexMode NvidiaReflexMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELatencyReductionMethod LatencyReductionMethod;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFrameGenerationMethod FrameGenerationMethod;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Resolution3D;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResolutionQualityPreset ResolutionQualityPreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResolutionQualityPreset LastConfirmedResolutionQualityPreset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustomFieldOfView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedCustomFieldOfView;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NewDefaultVerticalFOV;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultHorizontalFOV;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumVerticalFOV;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumVerticalFOV;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChromaticAberration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLastChromaticAberration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHardwareRayTracing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LastConfirmedHardwareRayTracing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LastConfirmedUseHDRDisplayOutput;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HDRMaxBrightness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedHDRMaxBrightness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HDRContrast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedHDRContrast;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HDRShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedHDRShadows;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HDRUIBrightness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedHDRUIBrightness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HDRUIContrast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastConfirmedHDRUIContrast;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CrowdDensityLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LastConfirmedCrowdDensityLevel;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode ConversationSubtitleVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBarkSubtitlesVisible;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubtitleShowSpeakerName;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubtitleShowFontOutline;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubtitleShowDropShadow;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubtitleTextColorIndex;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubtitleBGColorIndex;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SubtitleBGOpacity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SubtitleTextOpacity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubtitleFontModifier;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCinematicSubtitlesVisible;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConversationResponseVisibleDuringVO;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoesConversationAdvanceNeedInput;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTutorialsEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELanguageMode LanguageMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideNativeLanguage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowFloatingDamageText;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponTooltipStatMode WeaponTooltipStatMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHUDVisible;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowWaypointMarkers;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInteractionOutlines;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EReticleMode ReticleMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowReticleFeedback;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOffsetReticle;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOffsetReticleConsole;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode QuestUpdateVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode PlayerStatusVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode CompanionAbilityUIVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode EquipmentDisplayVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode HeldWeaponDisplayTextVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowLevelUpReminders;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode TTDReticleMeterVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDWidthScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDHeightScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDHealthScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDCompanionScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDCompassScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDQuestTrackerScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDNotificationsScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDCommandsScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HUDAmmoReadoutScalingValue;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowPlayerHelmet;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCinematicKillCam;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeadbobbing;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMotionSicknessMode MotionSicknessMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bViewBaseItemStats;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode CompanionOutlineVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHUDWidgetVisibilityMode MinimapVisibility;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMinimapRotationLock;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowMinimapPlayerFOV;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowMinimapThreatIndicators;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFreshUserSettings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFirstTimeFrontEndFlow;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneTimeSaveCompressionCompleted;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimAssistMagnetismStrength;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimAssistAdhesionStrength;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimAssistFrictionStrength;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimAssistSnappingStrength;
    
    UIndianaGameUserSettings();

    UFUNCTION(BlueprintCallable)
    void SetYAxisInverted(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetXeSSQualityMode(EOWXeSSQualityMode InQualityMode);
    
    UFUNCTION(BlueprintCallable)
    void SetXAxisInverted(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponTooltipStatMode(EWeaponTooltipStatMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetVSyncWrapper(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetVRREnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetVoiceSoundVolume(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetVisualMode(EVisualMode Value, bool bFromUI);
    
    UFUNCTION(BlueprintCallable)
    void SetViewBaseStats(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetUseHDRDisplayOutput(bool UseHDRDisplayOutputIn);
    
    UFUNCTION(BlueprintCallable)
    void SetUpscalingMethod(ESuperSampler InUpscalingMethod);
    
    UFUNCTION(BlueprintCallable)
    void SetUISoundVolume(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTutorialsEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetTempShowMinimap(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetSubtitleTextOpacity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetSubtitleTextColorIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetSubtitleFontSizeModifier(int32 ModifierIn);
    
    UFUNCTION(BlueprintCallable)
    void SetSubtitleBGOpacity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetSubtitleBGColorIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetShowWaypointMarkers(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowTTDReticleMeter(EHUDWidgetVisibilityMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetShowSubtitleSpeakerName(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetShowSubtitleFontOutline(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetShowSubtitleDropShadow(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetShowReticleFeedback(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowPlayerHelmet(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowMinimapVisibility(EHUDWidgetVisibilityMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetShowMinimapThreatIndicators(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetShowMinimapPlayerFOV(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetShowLevelUpReminders(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowInteractionOutlines(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowFloatingDamageText(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetRadialSensitivity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetQuestUpdateVisibility(EHUDWidgetVisibilityMode bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetPseudoGodMode(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerStatusBarVisibility(EHUDWidgetVisibilityMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetOffsetReticle(bool bUseOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetNvidiaReflexMode(EOWNvidiaReflexMode InReflectMode);
    
    UFUNCTION(BlueprintCallable)
    void SetMusicSoundVolume(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetMouseADSSensitivity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetMotionSicknessMode(EMotionSicknessMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetMotionBlurScale(float NewMotionBlurScale);
    
    UFUNCTION(BlueprintCallable)
    void SetMinimapRotationLock(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetMasterSoundVolume(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetLatencyReductionMethod(ELatencyReductionMethod InLatencyReductionMethod);
    
    UFUNCTION(BlueprintCallable)
    void SetLanguageMode(ELanguageMode LanguageModeIn, bool bPending);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFreshUserSettings(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFirstTimeFrontEndFlow(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetInputPreferenceSprint(EControlInputPreference InputPreference);
    
    UFUNCTION(BlueprintCallable)
    void SetInputPreferenceCrouch(EControlInputPreference InputPreference);
    
    UFUNCTION(BlueprintCallable)
    void SetInputPreferenceADS(EControlInputPreference InputPreference);
    
    UFUNCTION(BlueprintCallable)
    void SetInfiniteAmmo(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetHUDVisibility(bool bVisibilityIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHUDScaling(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetHUDCommandsScaling(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetHeldWeaponDisplayTextVisibility(EHUDWidgetVisibilityMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHDRUIContrast(float HDRContrastIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHDRUIBrightness(float HDRUIBrightnessIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHDRShadows(float HDRShadowsIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHDRMaxBrightness(float HDRMaxBrightnessIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHDRContrast(float HDRContrastIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHardwareRayTracing(bool bUseHardwareRayTracing);
    
    UFUNCTION(BlueprintCallable)
    void SetGraphicsQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetGodMode(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetGammaLevel(float GammaLevelIn);
    
    UFUNCTION(BlueprintCallable)
    void SetFullscreenModeThenBroadcast(TEnumAsByte<EWindowMode::Type> Value);
    
    UFUNCTION(BlueprintCallable)
    void SetFSR3Sharpness(float InSharpness);
    
    UFUNCTION(BlueprintCallable)
    void SetFSR3QualityMode(EFSR3QualityMode InQualityMode);
    
    UFUNCTION(BlueprintCallable)
    void SetFrameGenerationMethod(EFrameGenerationMethod InFrameGenerationMethod);
    
    UFUNCTION(BlueprintCallable)
    void SetFPSLimit(EFPSLimit FPSLimitIn);
    
    UFUNCTION(BlueprintCallable)
    void SetFOV(float FOVIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEquipmentDisplayVisibility(EHUDWidgetVisibilityMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEffectsSoundVolume(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetDoesConversationAdvanceNeedInput(bool bDoesConversationAdvanceNeedInputIn);
    
    UFUNCTION(BlueprintCallable)
    void SetDLSSQualityMode(EOWDLSSMode InQualityMode);
    
    UFUNCTION(BlueprintCallable)
    void SetDLSSFrameGenerationMode(EOWDLSSFrameGenerationMode InGenMode);
    
    UFUNCTION(BlueprintCallable)
    void SetCrowDensityLevel(int32 InCrowdDensityLevel);
    
    UFUNCTION(BlueprintCallable)
    void SetConversationSubtitleVisibility(EHUDWidgetVisibilityMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetConversationResponseVisibleDuringVO(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerYAxisInverted(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerXAxisInverted(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerSensitivity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerRumbleEnabled(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerRightOuterDeadZone(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerRightInnerDeadZone(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerLightBarEnabled(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerLeftOuterDeadZone(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerLeftInnerDeadZone(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerAutoSprintEnabled(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerADSSensitivity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerAdaptiveTriggersEnabled(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void SetCompanionOutlineMode(EHUDWidgetVisibilityMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetCompanionHelmetVisibility(ECompanionHelmetVisibility HelmetVisibility);
    
    UFUNCTION(BlueprintCallable)
    void SetCompanionAbilityUIVisibility(EHUDWidgetVisibilityMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetCinematicSubtitlesVisible(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetCinematicKillCam(bool bEnabledIn);
    
    UFUNCTION(BlueprintCallable)
    void SetChromaticAberration(bool bUseChromaticAberration);
    
    UFUNCTION(BlueprintCallable)
    void SetBarkSubtitleMode(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetAxisKeyBinds(TArray<FInputAxisKeyMapping> OldValues, TArray<FInputAxisKeyMapping> NewValues);
    
    UFUNCTION(BlueprintCallable)
    void SetAntiAliasingMethod(int32 Method);
    
    UFUNCTION(BlueprintCallable)
    void SetAimingReticleMode(EReticleMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetAimAssistSnappingStrength(float StrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void SetAimAssistMagnetismStrength(float StrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void SetAimAssistFrictionStrength(float StrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void SetAimAssistAdhesionStrength(float StrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void SetActionKeyBinds(TArray<FInputActionKeyMapping> OldValues, TArray<FInputActionKeyMapping> NewValues);
    
    UFUNCTION(BlueprintCallable)
    void Set3DResolutionPreset(EResolutionQualityPreset ResolutionPreset);
    
    UFUNCTION(BlueprintCallable)
    void Set3DResolution(float ResolutionIn);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllKeyBinds();
    
    UFUNCTION(BlueprintCallable)
    void OnDetectGraphics();
    
    UFUNCTION(BlueprintCallable)
    bool IsVisLogRunning();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConversationResponseVisibleDuringVO() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetYAxisInverted();
    
    UFUNCTION(BlueprintCallable)
    EOWXeSSQualityMode GetXeSSQualityMode() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetXAxisInverted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWeaponTooltipStatMode GetWeaponTooltipStatMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVSyncWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVRREnabled() const;
    
    UFUNCTION(BlueprintCallable)
    float GetVoiceSoundVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EVisualMode GetVisualMode() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetViewBaseStats();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVerticalFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseHDRDisplayOutput() const;
    
    UFUNCTION(BlueprintCallable)
    ESuperSampler GetUpscaleMethod() const;
    
    UFUNCTION(BlueprintCallable)
    float GetUISoundVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTutorialsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTempShowMinimap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSubtitleTextOpacity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSubtitleTextColorIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSubtitleFontSizeModifier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSubtitleBGOpacity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSubtitleBGColorIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowWaypointMarkers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetShowTTDReticleMeter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowSubtitleSpeakerName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowSubtitleFontOutline() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowSubtitleDropShadow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowReticleFeedback() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowPlayerHelmet() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetShowMinimapVisibility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowMinimapThreatIndicators() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowMinimapPlayerFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowLevelUpReminders() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowInteractionOutlines() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowFloatingDamageText() const;
    
    UFUNCTION(BlueprintCallable)
    float GetRadialSensitivity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetQuestUpdateVisibility() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetPseudoGodMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetPlayerStatusBarVisibility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetOffsetReticle() const;
    
    UFUNCTION(BlueprintCallable)
    EOWNvidiaReflexMode GetNvidiaReflexMode() const;
    
    UFUNCTION(BlueprintCallable)
    float GetMusicSoundVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMouseADSSensitivity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMotionSicknessMode GetMotionSicknessMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMotionBlurScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMinimapRotationLock() const;
    
    UFUNCTION(BlueprintCallable)
    float GetMasterSoundVolume();
    
    UFUNCTION(BlueprintCallable)
    ELatencyReductionMethod GetLatencyReductionMethod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELanguageMode GetLanguageMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsFreshUserSettings() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsFirstTimeFrontEndFlow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EControlInputPreference GetInputPreferenceSprint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EControlInputPreference GetInputPreferenceCrouch() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EControlInputPreference GetInputPreferenceADS() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetInfiniteAmmo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHUDVisibility() const;
    
    UFUNCTION(BlueprintCallable)
    float GetHUDScaling();
    
    UFUNCTION(BlueprintCallable)
    float GetHUDCommandsScaling();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHorizontalFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetHeldWeaponDisplayTextVisibility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHDRUIContrast() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHDRUIBrightness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHDRShadows() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHDRMaxBrightness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHDRContrast() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHardwareRayTracing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetGraphicsQuality() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetGodMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGammaLevel() const;
    
    UFUNCTION(BlueprintCallable)
    float GetFSR3Sharpness() const;
    
    UFUNCTION(BlueprintCallable)
    EFSR3QualityMode GetFSR3QualityMode() const;
    
    UFUNCTION(BlueprintCallable)
    EFrameGenerationMethod GetFrameGenerationMethod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFPSLimit GetFPSLimit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetEquipmentDisplayVisibility() const;
    
    UFUNCTION(BlueprintCallable)
    float GetEffectsSoundVolume();
    
    UFUNCTION(BlueprintCallable)
    EOWDLSSMode GetDLSSQualityMode() const;
    
    UFUNCTION(BlueprintCallable)
    EOWDLSSFrameGenerationMode GetDLSSFrameGenerationMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDefaultVerticalFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDefaultHorizontalFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCrowdDensityLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetConversationSubtitleVisibility() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetControllerYAxisInverted();
    
    UFUNCTION(BlueprintCallable)
    bool GetControllerXAxisInverted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetControllerSensitivity() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetControllerRumbleEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetControllerRightOuterDeadZone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetControllerRightInnerDeadZone() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetControllerLightBarEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetControllerLeftOuterDeadZone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetControllerLeftInnerDeadZone() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetControllerAutoSprintEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetControllerADSSensitivity() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetControllerAdaptiveTriggersEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetCompanionOutlineVisibility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECompanionHelmetVisibility GetCompanionHelmetVisibility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHUDWidgetVisibilityMode GetCompanionAbilityUIVisibility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCinematicSubtitlesVisible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCinematicKillCam() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetChromaticAberration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetBarkSubtitlesVisible() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FInputAxisKeyMapping> GetAxisKeyBinds(FName AxisName, float Scale);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAntiAliasingMethod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EReticleMode GetAimingReticleMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAimAssistSnappingStrength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAimAssistMagnetismStrength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAimAssistFrictionStrength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAimAssistAdhesionStrength() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FInputActionKeyMapping> GetActionKeyBinds(FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    EResolutionQualityPreset Get3DResolutionPreset() const;
    
    UFUNCTION(BlueprintCallable)
    float Get3DResolution() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableVisLog(bool Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesConversationAdvanceNeedInput() const;
    
    UFUNCTION(BlueprintCallable)
    void ApplyUpscalingMethod();
    
    UFUNCTION(BlueprintCallable)
    void ApplyTSRScreenPercentage();
    
};

