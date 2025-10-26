#include "Ladder.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent
#include "Components\SplineComponent.h"

#include "InteractableComponent.h"
#include "MotionWarpPointComponent.h"
#include "OwAnimationProxyComponent.h"

ALadder::ALadder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->NavLinks.AddDefaulted(1);
    this->TopFurnitureComponentOffsetSpacing = 6.00f;
    this->BottomFurnitureComponentOffsetSpacing = 2.00f;
    this->MaxInteractionAngle = 80.00f;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Ladder Spline"));
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->TopMotionWarpSceneComponent = CreateDefaultSubobject<UMotionWarpPointComponent>(TEXT("TopMotionWarpSceneComponent"));
    this->BottomMotionWarpSceneComponent = CreateDefaultSubobject<UMotionWarpPointComponent>(TEXT("BottomMotionWarpSceneComponent"));
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->AnimProxyComponent = CreateDefaultSubobject<UOwAnimationProxyComponent>(TEXT("AnimationProxyComponent"));
    this->TraverseUpLoopMontage = NULL;
    this->TraverseDownLoopMontage = NULL;
    this->TraverseUpLoopCount = 0.00f;
    this->TraverseDownLoopCount = 0.00f;
    this->AkComponent->SetupAttachment(RootComponent);
    this->AnimProxyComponent->SetupAttachment(RootComponent);
    this->BottomMotionWarpSceneComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
    this->SplineComponent->SetupAttachment(RootComponent);
    this->TopMotionWarpSceneComponent->SetupAttachment(RootComponent);
}

TArray<EInteractionType> ALadder::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float ALadder::GetInteractHoldTime(const FInteractionDescription& Description) {
    return 0.0f;
}

void ALadder::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool ALadder::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


