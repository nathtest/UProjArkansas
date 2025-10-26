#include "Intercom.h"
#include <AkComponent.h>

AIntercom::AIntercom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->VoiceOverAudioComponent = CreateDefaultSubobject<UAkComponent>(TEXT("VoiceOverFaceFXExternalAudio"));
    this->SpeakerInfoComponent = NULL;
    this->DynamicFxInput = CreateDefaultSubobject<UAkComponent>(TEXT("DynamicFxInputAkComponent"));
    this->DynamicFxOutput = CreateDefaultSubobject<UAkComponent>(TEXT("DynamicFxOutputAkComponent"));
    this->AkComponent->SetupAttachment(RootComponent);
    this->DynamicFxInput->SetupAttachment(RootComponent);
    this->DynamicFxOutput->SetupAttachment(RootComponent);
    this->VoiceOverAudioComponent->SetupAttachment(RootComponent);
}


