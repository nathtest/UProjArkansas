#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <VoiceOverComponentSetupData.h>
#include "OwSpeaker.h"
#include "BroadcastActor.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class ARKANSAS_API ABroadcastActor : public AActor, public IOwSpeaker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData VoiceOverSetupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* VoiceOverAudioComponent;
    
public:
    ABroadcastActor(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

