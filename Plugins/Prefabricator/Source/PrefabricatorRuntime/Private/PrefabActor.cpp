#include "PrefabActor.h"
#include "PrefabComponent.h"

APrefabActor::APrefabActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRelevantForLevelBounds = false;
    this->RootComponent = CreateDefaultSubobject<UPrefabComponent>(TEXT("PrefabComponent"));
    this->PrefabComponent = (UPrefabComponent*)RootComponent;
}

bool APrefabActor::SavePrefab() {
    return false;
}

void APrefabActor::LoadPrefab() {
}

bool APrefabActor::IsPrefabOutdated() {
    return false;
}

UPrefabricatorAsset* APrefabActor::GetPrefabAsset() const {
    return NULL;
}


