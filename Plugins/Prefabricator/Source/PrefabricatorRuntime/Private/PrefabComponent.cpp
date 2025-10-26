#include "PrefabComponent.h"

UPrefabComponent::UPrefabComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mobility = EComponentMobility::Static;
}


