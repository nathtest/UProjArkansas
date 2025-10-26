#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=FloatRange -FallbackName=FloatRange
#include "OEICineFPVPresentationMode.h"

#include "EPresentationModeCameraFadeState.h"
#include "EPresentationModeZoomReferenceMode.h"
#include "PresentationModeFadeSettings.h"
#include "ScaledFieldOfViewRange.h"
#include "OwFPVPresentationMode.generated.h"

class AActor;
class AIndianaCharacter;
class AIndianaPlayerCharacter;
class APlayerController;
class AStageMarkActor;
class UPresentationModeCameraFadeInstance;

UCLASS(Blueprintable)
class ARKANSAS_API UOwFPVPresentationMode : public UOEICineFPVPresentationMode {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFadeInOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeToBlackTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeFromBlackTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPresentationModeFadeSettings StartFadeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPresentationModeFadeSettings EndFadeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysUseDoubleSpeakerFraming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableZoom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPresentationModeZoomReferenceMode ZoomReferenceMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumDistanceToZoom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatRange AcceptableStageMarkDistanceRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScaledFieldOfViewRange ScaledFOVRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDesiredZoomFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredZoomFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SimulatedDistanceToSpeakerWhenZooming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCinematicShotEnabledByDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPresentationModeCameraFadeInstance* ConversationFadeInstance;
    
public:
    UOwFPVPresentationMode();

    UFUNCTION(BlueprintCallable)
    static void SetPresentationModeBaseCameraShakeEnabled(const AIndianaPlayerCharacter* Player, bool bEnabled, float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    static void SetFPVPresentationModeCinematicShotEnabled(const AIndianaPlayerCharacter* Player, bool bEnabled, float BlendTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnViewTargetChanged(APlayerController* PlayerController, AActor* OldViewTarget, AActor* NewViewTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnSpeakerTeleportedToStageMark(AIndianaCharacter* SpeakerCharacter, AStageMarkActor* StageMark);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnFadeInstanceStateChanged(UPresentationModeCameraFadeInstance* FadeInstance, EPresentationModeCameraFadeState NewState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnConversationCameraSwayUserSettingChanged(bool bCameraSwayEnabled);
    
};

