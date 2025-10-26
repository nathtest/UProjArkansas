#include "ShipLocation.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "BeaconComponent.h"
#include "InteractableComponent.h"
#include "OwNavModifierComponent.h"
#include "TravelTriggerComponent.h"

AShipLocation::AShipLocation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->BeaconComponent = CreateDefaultSubobject<UBeaconComponent>(TEXT("BeaconComponent"));
    this->NavModifierComponent = CreateDefaultSubobject<UOwNavModifierComponent>(TEXT("NavModifier"));
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
    this->ShipDestinationTravelTrigger = CreateDefaultSubobject<UTravelTriggerComponent>(TEXT("TravelTrigger"));
    this->TravelSound = NULL;
    this->ShipLocationData = NULL;
    this->bHideWhenShipIsNotAtLocation = true;
    this->BeaconComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
}

void AShipLocation::ShipLocationDeactivated_Implementation() {
}

void AShipLocation::ShipLocationActivated_Implementation() {
}

void AShipLocation::OnShipLocationChanged(const UShipDestinationData* NewLocation) {
}

TArray<EInteractionType> AShipLocation::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float AShipLocation::GetInteractHoldTime(const FInteractionDescription& Description) {
    return 0.0f;
}

void AShipLocation::CompleteInteract(const FInteractionDescription& Description) {
}

bool AShipLocation::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


