#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SpeakerPlaybackStartedDynamicDelegateDelegate.h"

#include "VoiceOverComponentSetupData.h"
#include "VoiceOverData.h"
#include "VoiceOverLoadFinishedDynamicDelegateDelegate.h"
#include "OEIVoiceOverComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class OEIVOICEOVER_API UOEIVoiceOverComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* AudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorComponent* FacialAnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData SetupData;
    
public:
    UOEIVoiceOverComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void Stop(float FadeOutDuration) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void Resume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void Prepare(const FVoiceOverData& Data, const FVoiceOverLoadFinishedDynamicDelegate& LoadingFinished) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void Play(const FVoiceOverData& Data, float StartTime, const FSpeakerPlaybackStartedDynamicDelegate& PlaybackStarted) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void Pause() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void CancelPrepared() const;
    
};

