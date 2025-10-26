#include "RadioPlayer.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIWwise -ObjectName=OEIWwiseEmitterComponent -FallbackName=OEIWwiseEmitterComponent
#include "OEIWwiseEmitterComponent.h"

#include "InteractableComponent.h"
#include "RadioPlayerComponent.h"

ARadioPlayer::ARadioPlayer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->VoiceOverAudioComponent = CreateDefaultSubobject<UAkComponent>(TEXT("VoiceOverFaceFXExternalAudio"));
    this->SpeakerInfoComponent = NULL;
    this->VolumeRTPC = NULL;
    this->DefaultDynamicFxAuxBus = NULL;
    this->RadioPlayerComponent = CreateDefaultSubobject<URadioPlayerComponent>(TEXT("RadioPlayerComponent"));
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->EmitterComponent = CreateDefaultSubobject<UOEIWwiseEmitterComponent>(TEXT("OEIWwiseEmitter"));
    this->EmitterComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
    this->VoiceOverAudioComponent->SetupAttachment(RootComponent);
}

TArray<EInteractionType> ARadioPlayer::GetInteractions(const FInteractionDescription& Description) {
    return TArray<EInteractionType>();
}

float ARadioPlayer::GetInteractHoldTime(const FInteractionDescription& InteractionDescription) {
    return 0.0f;
}

void ARadioPlayer::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool ARadioPlayer::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


