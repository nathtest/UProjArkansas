#include "ArkansasTestControllerPSOCollection.h"

UArkansasTestControllerPSOCollection::UArkansasTestControllerPSOCollection(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->WorldsToProcess.AddDefaulted(28);
    this->MapCollectionLoadRadius = 25000.00f;
    this->MaxBoundsWarning = 400000.00f;
    this->BoundsIterationLimit = 500000.00f;
    this->LocationFrameWaitCount = 10;
    this->MapCollectionVFXAdvanceTimePerTick = 2.50f;
    this->ProcessingFrameWaitCount = 10;
    this->DynamicCollectionNiagaraSystemAdvanceAmount = 2.00f;
    this->UIStepWaitTimeSeconds = 1.00f;
    this->SpawnedUIImage = NULL;
}


