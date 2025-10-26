#include "ShipTerminal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "BeaconComponent.h"
#include "InteractableComponent.h"

AShipTerminal::AShipTerminal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SystemMapClass = NULL;
    this->SystemMapCamera = NULL;
    this->bUseCameraFade = false;
    this->EnterFadeToBlackDuration = 0.00f;
    this->EnterFadeFromBlackDuration = 0.00f;
    this->ExitFadeToBlackDuration = 0.00f;
    this->ExitFadeFromBlackDuration = 0.00f;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->BeaconComponent = CreateDefaultSubobject<UBeaconComponent>(TEXT("BeaconComponent"));
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
    this->BeaconComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
}

TArray<EInteractionType> AShipTerminal::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float AShipTerminal::GetArmRotation() {
    return 0.0f;
}

void AShipTerminal::CompleteInteract(const FInteractionDescription& Description) {
}

bool AShipTerminal::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


