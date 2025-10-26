#include "NoMansLand.h"
#include "Components/BoxComponent.h"
#include "NoMansLandComponent.h"

ANoMansLand::ANoMansLand(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UNoMansLandComponent>(TEXT("SceneComp"));
    this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
    this->bEnable = true;
    this->BoxComponent->SetupAttachment(RootComponent);
}


