#include "InteractableAnimProxyActor.h"
#include <AkComponent.h>
#include "InteractableComponent.h"

AInteractableAnimProxyActor::AInteractableAnimProxyActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->AkComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
}


