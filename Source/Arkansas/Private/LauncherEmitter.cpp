#include "LauncherEmitter.h"
#include "ObsidianIDComponent.h"
#include "EquipmentComponent.h"
#include "InteractLookAtTriggerComponent.h"
#include "InteractableComponent.h"
#include "InventoryComponent.h"
#include "LauncherEmitterComponent.h"

ALauncherEmitter::ALauncherEmitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShouldSaveGameState = true;
    this->EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>(TEXT("EquipmentComponent"));
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->InteractLookAtTriggerComponent = CreateDefaultSubobject<UInteractLookAtTriggerComponent>(TEXT("InteractLookAtTrigger"));
    this->LauncherEmitterComponent = CreateDefaultSubobject<ULauncherEmitterComponent>(TEXT("LauncherEmitterComponent"));
    this->ObsidianIDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
    this->FiringAngle = 0.00f;
    this->InitialProjectileVelocity = 0.00f;
}

void ALauncherEmitter::StopFiring() {
}

void ALauncherEmitter::SetProjectileVelocity(float Velocity) {
}

void ALauncherEmitter::OnObservationRevealed() {
}

bool ALauncherEmitter::IsDisarmed() const {
    return false;
}

bool ALauncherEmitter::Fire() {
    return false;
}

void ALauncherEmitter::EndPrimaryTrigger() {
}

void ALauncherEmitter::Disarm() {
}

void ALauncherEmitter::BeginPrimaryTrigger() {
}


