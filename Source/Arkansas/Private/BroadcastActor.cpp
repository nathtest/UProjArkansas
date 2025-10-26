#include "BroadcastActor.h"
#include <AkComponent.h>

ABroadcastActor::ABroadcastActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UAkComponent>(TEXT("VoiceOverFaceFXExternalAudio"));
    this->VoiceOverAudioComponent = (USceneComponent*)RootComponent;
}


