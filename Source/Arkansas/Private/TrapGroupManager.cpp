#include "TrapGroupManager.h"
#include "ObsidianIDComponent.h"

ATrapGroupManager::ATrapGroupManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActivationType = ETrapGroupActivation::OneShot;
    this->bRandomOrder = false;
    this->bSharedDisarming = false;
    this->bIgnoreFirstPreDelay = true;
    this->bRestartOnTrigger = false;
    this->bDisableTrapsAtStart = false;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}

void ATrapGroupManager::DisarmTrap() {
}

void ATrapGroupManager::DeactivateTrap() {
}

void ATrapGroupManager::ArmTrap() {
}


