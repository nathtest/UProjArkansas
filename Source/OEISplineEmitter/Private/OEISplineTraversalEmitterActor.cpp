#include "OEISplineTraversalEmitterActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent
#include "Components\SplineComponent.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=OEIWwise -ObjectName=OEIWwiseEmitterComponent -FallbackName=OEIWwiseEmitterComponent
#include "OEIWwiseEmitterComponent.h"

AOEISplineTraversalEmitterActor::AOEISplineTraversalEmitterActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    this->AudioEvent = NULL;
    this->VelocityRTPC = NULL;
    this->EmitterSpeed = 0.00f;
    this->EmitterComponent = CreateDefaultSubobject<UOEIWwiseEmitterComponent>(TEXT("OEIWwiseEmitterComponentSpline"));
    this->Spline = (USplineComponent*)RootComponent;
    this->MinimumAttenuationRadius = 0.00f;
    this->EmitterComponent->SetupAttachment(RootComponent);
}


