#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <VoiceOverComponentSetupData.h>
#include "OwSpeaker.h"
#include "AudioLogSpeaker.generated.h"

class UOwConversationInstance;
class UOwSpeakerInfoComponent;
class USceneComponent;

UCLASS(Blueprintable)
class AAudioLogSpeaker : public AActor, public IOwSpeaker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UOwConversationInstance> CachedConversationInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData VoiceOverSetupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* VoiceOverAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwSpeakerInfoComponent* SpeakerInfoComponent;
    
public:
    AAudioLogSpeaker(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnConversationEnded(UOwConversationInstance* ConversationInstance);
    

    // Fix for true pure virtual functions not being implemented
};

