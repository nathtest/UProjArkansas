#include "RadioPlayerBR.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "OEIWwiseAmbientEmitterComponent.h"
#include "InteractableComponent.h"

ARadioPlayerBR::ARadioPlayerBR(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->AmbientEmitterComponent = CreateDefaultSubobject<UOEIWwiseAmbientEmitterComponent>(TEXT("OEIWwiseEmitterComponent"));
    this->StartingStation = NULL;
    this->InteractableComponent->SetupAttachment(RootComponent);
}

TArray<EInteractionType> ARadioPlayerBR::GetInteractions(const FInteractionDescription& Description) {
    return TArray<EInteractionType>();
}

float ARadioPlayerBR::GetInteractHoldTime(const FInteractionDescription& InteractionDescription) {
    return 0.0f;
}

void ARadioPlayerBR::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool ARadioPlayerBR::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


