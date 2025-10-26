#include "OEISplineEmitterActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIWwise -ObjectName=OEIWwiseEmitterComponent -FallbackName=OEIWwiseEmitterComponent
#include "Components\SplineComponent.h"
#include "OEIWwiseEmitterComponent.h"


AOEISplineEmitterActor::AOEISplineEmitterActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    this->AudioEvent = NULL;
    this->VelocityRTPC = NULL;
    this->EmitterComponent = CreateDefaultSubobject<UOEIWwiseEmitterComponent>(TEXT("OEIWwiseEmitterComponentSpline"));
    this->Spline = (USplineComponent*)RootComponent;
    this->bAutoPost = true;
    this->bUseShapeEmitter = false;
    this->MinimumAttenuationRadius = 0.00f;
    this->EmitterComponent->SetupAttachment(RootComponent);
}

void AOEISplineEmitterActor::StopSound() {
}

void AOEISplineEmitterActor::StartSound() {
}


