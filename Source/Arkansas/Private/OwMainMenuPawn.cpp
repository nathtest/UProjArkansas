#include "OwMainMenuPawn.h"
#include "ObsidianIDComponent.h"
#include "OwPlayerSpeakerInfoComponent.h"

AOwMainMenuPawn::AOwMainMenuPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpeakerInfoComponent = CreateDefaultSubobject<UOwPlayerSpeakerInfoComponent>(TEXT("OwSpeakerInfo"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}


