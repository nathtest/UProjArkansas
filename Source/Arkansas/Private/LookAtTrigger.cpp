#include "LookAtTrigger.h"
#include "Components\CapsuleComponent.h"

#include "ObsidianIDComponent.h"

ALookAtTrigger::ALookAtTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TriggerVolume"));
    this->bShouldSaveGameState = true;
    this->RequiresLoS = true;
    this->MaximumTriggerDistance = 0.00f;
    this->HoldTimeToActivate = 0.00f;
    this->bShowProgressBar = false;
    this->bInvisibleTrigger = false;
    this->CapsuleComponent = (UCapsuleComponent*)RootComponent;
    this->ObsidianIDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}

void ALookAtTrigger::OnNoLongerTargeted() {
}

void ALookAtTrigger::OnNewTarget(bool bHasLoS, float Distance) {
}



