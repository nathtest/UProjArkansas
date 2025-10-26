#include "PlayerHeadsetSpeaker.h"
#include <AkComponent.h>
#include "OwSpeakerInfoComponent.h"

APlayerHeadsetSpeaker::APlayerHeadsetSpeaker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UAkComponent>(TEXT("VoiceOverFaceFXExternalAudio"));
    this->VoiceOverAudioComponent = (USceneComponent*)RootComponent;
    this->SpeakerInfoComponent = CreateDefaultSubobject<UOwSpeakerInfoComponent>(TEXT("SpeakerInfo"));
}


