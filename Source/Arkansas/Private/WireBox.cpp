#include "WireBox.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AWireBox::AWireBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->FxSystemEnabled = NULL;
    this->FxSystemDisabled = NULL;
    this->AkComponent->SetupAttachment(RootComponent);
}

void AWireBox::UpdateParticles(bool bHasPower) {
}

bool AWireBox::HasPower() const {
    return false;
}


