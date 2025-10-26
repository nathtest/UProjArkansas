#include "IndianaTargetPoint.h"
#include "ObsidianIDComponent.h"

AIndianaTargetPoint::AIndianaTargetPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}


