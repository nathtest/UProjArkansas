#include "ScalingOverrideBox.h"
#include "Components/BoxComponent.h"

AScalingOverrideBox::AScalingOverrideBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    this->MinEffectiveLevel = 0;
    this->MaxEffectiveLevel = 0;
    this->bApplyLevelModifier = false;
    this->FlatLevelModifier = 0;
    this->BoxShape = (UBoxComponent*)RootComponent;
}


