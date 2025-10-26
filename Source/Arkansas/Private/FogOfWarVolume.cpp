#include "FogOfWarVolume.h"
#include "ObsidianIDComponent.h"

AFogOfWarVolume::AFogOfWarVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bGenerateOverlapEventsDuringLevelStreaming = true;
    this->bShouldSaveGameState = true;
    this->bStartActivated = false;
    this->bActivateOnPlayerEnter = false;
    this->bReveal = true;
    this->bUseSphereBounds = false;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}

void AFogOfWarVolume::UpdateFogOfWar() {
}


