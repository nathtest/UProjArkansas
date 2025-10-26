#include "OwSequenceCameraShakePattern.h"

UOwSequenceCameraShakePattern::UOwSequenceCameraShakePattern(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->bLoopSequence = true;
    this->bApplyAsAbsolute = false;
}


