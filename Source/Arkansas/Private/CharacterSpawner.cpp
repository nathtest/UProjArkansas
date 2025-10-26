#include "CharacterSpawner.h"
#include "ObsidianIDComponent.h"
#include "CharacterSpawnerVizComponent.h"

ACharacterSpawner::ACharacterSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UCharacterSpawnerVizComponent>(TEXT("RootComponent"));
    this->bShouldSaveGameState = true;
    this->MaximumSimultaneousAnimations = 0;
    this->SpawnCap = 0;
    this->MaximumDelayInSeconds = 1.00f;
    this->NumNPCsSpawned = 0;
    this->bActorsKillableDuringSpawn = false;
    this->bAllowStrafing = false;
    this->bDontDisableCollisionAtExitPoint = false;
    this->bCorrectStartTransformWithCapsuleHalfHeight = false;
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
}

void ACharacterSpawner::TEMP_ActivateActor(AActor* Actor) {
}

bool ACharacterSpawner::HasReachedNPCSpawnCap() const {
    return false;
}


