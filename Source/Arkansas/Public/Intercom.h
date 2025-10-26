#pragma once
#include "CoreMinimal.h"
#include <VoiceOverComponentSetupData.h>
#include "InteractableActor.h"
#include "OwSpeaker.h"
#include "Intercom.generated.h"

class UAkAuxBus;
class UAkComponent;
class UOwSpeakerInfoComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AIntercom : public AInteractableActor, public IOwSpeaker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData VoiceOverSetupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* VoiceOverAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwSpeakerInfoComponent* SpeakerInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* DynamicFxInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* DynamicFxOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAkAuxBus> AuxBus;
    
public:
    AIntercom(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

