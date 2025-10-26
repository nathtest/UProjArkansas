#include "PrefabGroup.h"
#include "PrefabGroupComponent.h"

APrefabGroup::APrefabGroup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRelevantForLevelBounds = false;
    this->RootComponent = CreateDefaultSubobject<UPrefabGroupComponent>(TEXT("RootComponent"));
}


