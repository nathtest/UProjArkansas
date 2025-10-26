#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <VoiceOverComponentSetupData.h>
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "MapFloorTrackedActor.h"
#include "OwSpeaker.h"
#include "RadioPlayer.generated.h"

class AIndianaCharacter;
class UAkAuxBus;
class UAkRtpc;
class UInteractableComponent;
class UOEIWwiseEmitterComponent;
class UObsidianIDComponent;
class UOwSpeakerInfoComponent;
class URadioPlayerComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ARKANSAS_API ARadioPlayer : public AActor, public IMapFloorTrackedActor, public IOwSpeaker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData VoiceOverSetupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* VoiceOverAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwSpeakerInfoComponent* SpeakerInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* VolumeRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAuxBus* DefaultDynamicFxAuxBus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioPlayerComponent* RadioPlayerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOEIWwiseEmitterComponent* EmitterComponent;
    
public:
    ARadioPlayer(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

    // Fix for true pure virtual functions not being implemented
};

