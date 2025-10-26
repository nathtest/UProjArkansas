#include "SWITCH.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"

ASWITCH::ASWITCH(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->TravelTriggerComponent = NULL;
    this->CyclingType = CycleBehavior::LinearRepeat;
    this->NumStates = 2;
    this->InitialState = 0;
    this->AnimationProxyData = NULL;
    this->AkComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
}

void ASWITCH::SignalSwitchLeverInteractionComplete() {
}

void ASWITCH::SetCurrentState(int32 NewState, AActor* Initiator) {
}

TArray<EInteractionType> ASWITCH::GetInteractions(const FInteractionDescription& Description) {
    return TArray<EInteractionType>();
}

float ASWITCH::GetInteractHoldTime(const FInteractionDescription& InteractionDescription) {
    return 0.0f;
}

UInteractableComponent* ASWITCH::GetInteractableComponent() {
    return NULL;
}

int32 ASWITCH::GetCurrentState() const {
    return 0;
}

void ASWITCH::CycleNextState(AActor* Initiator) {
}

void ASWITCH::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool ASWITCH::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


