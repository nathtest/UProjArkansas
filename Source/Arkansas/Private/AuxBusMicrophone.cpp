#include "AuxBusMicrophone.h"
#include <AkComponent.h>

AAuxBusMicrophone::AAuxBusMicrophone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpeakerActor = NULL;
    this->DynamicFxAuxBus = NULL;
    this->bEnabled = true;
    this->MicrophoneRoutingAuxBus = NULL;
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("AkComponent"));
}

void AAuxBusMicrophone::EnableMicrophone() {
}

void AAuxBusMicrophone::DisableMicrophone() {
}


