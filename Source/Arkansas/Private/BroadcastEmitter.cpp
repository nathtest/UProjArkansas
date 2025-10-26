#include "BroadcastEmitter.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"

ABroadcastEmitter::ABroadcastEmitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("AkComponent"));
    this->StartingStation = NULL;
    this->CurrentStation = NULL;
    this->AuxBusOverride = NULL;
    this->AkComponent->SetupAttachment(RootComponent);
}

void ABroadcastEmitter::SetStation(UBroadcastStationAsset* Station) {
}

UAkComponent* ABroadcastEmitter::GetAkComponent() {
    return NULL;
}

void ABroadcastEmitter::EnableEmitter(bool bIsEnabled) {
}


