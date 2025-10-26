#include "AudioLogSpeaker.h"
#include <AkComponent.h>

AAudioLogSpeaker::AAudioLogSpeaker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UAkComponent>(TEXT("VoiceOverFaceFXExternalAudio"));
    this->VoiceOverAudioComponent = (USceneComponent*)RootComponent;
    this->SpeakerInfoComponent = NULL;
}

void AAudioLogSpeaker::OnConversationEnded(UOwConversationInstance* ConversationInstance) {
}


