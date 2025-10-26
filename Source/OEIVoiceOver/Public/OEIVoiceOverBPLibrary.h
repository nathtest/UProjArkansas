#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "SpeakerPlaybackStartedDynamicDelegateDelegate.h"
#include "VoiceOverData.h"
#include "OEIVoiceOverBPLibrary.generated.h"

class AActor;

UCLASS(Blueprintable)
class UOEIVoiceOverBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UOEIVoiceOverBPLibrary();

    UFUNCTION(BlueprintCallable)
    static bool StopVoiceOver(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool ResumeVoiceOver(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayVoiceOver(AActor* Actor, const FVoiceOverData& Data, float StartTime, const FSpeakerPlaybackStartedDynamicDelegate& PlaybackStarted);
    
    UFUNCTION(BlueprintCallable)
    static bool PauseVoiceOver(AActor* Actor);
    
};

