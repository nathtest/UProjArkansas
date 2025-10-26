#include "AmbientRetriggerSplineEmitterActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent
#include "Components\SplineComponent.h"

#include "AmbientRetriggerSplineEmitterComponent.h"

AAmbientRetriggerSplineEmitterActor::AAmbientRetriggerSplineEmitterActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
    this->EmitterComponent = CreateDefaultSubobject<UAmbientRetriggerSplineEmitterComponent>(TEXT("SplineEmitterComponent"));
    this->SplineComponent = (USplineComponent*)RootComponent;
    this->EmitterComponent->SetupAttachment(RootComponent);
}


