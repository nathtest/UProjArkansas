#include "ShipDoor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "BeaconComponent.h"
#include "InteractableComponent.h"

AShipDoor::AShipDoor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->CompanionSelectionClass = NULL;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->TravelSound = NULL;
    this->BeaconComponent = CreateDefaultSubobject<UBeaconComponent>(TEXT("BeaconComponent"));
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
    this->BeaconComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
}

void AShipDoor::InitiateFastTravelFromCompanionSelect() {
}

TArray<EInteractionType> AShipDoor::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float AShipDoor::GetInteractHoldTime(const FInteractionDescription& Description) {
    return 0.0f;
}

void AShipDoor::CompleteInteract(const FInteractionDescription& Description) {
}

bool AShipDoor::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


