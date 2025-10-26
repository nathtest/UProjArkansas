#include "ExtendableLadder.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InstancedStaticMeshComponent -FallbackName=InstancedStaticMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent
#include "Components\SplineComponent.h"
#include "Components\StaticMeshComponent.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components\InstancedStaticMeshComponent.h"


AExtendableLadder::AExtendableLadder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NavLinks.AddDefaulted(1);
    this->RungInstancedMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("LadderRungs"));
    this->RungInteractionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RungInteractionMesh"));
    this->TopInteractionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopperInteractionMesh"));
    this->LadderTopperMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LadderTopper"));
    this->LadderBottomMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LadderBottomBase"));
    this->PlayerTopExitMontage = NULL;
    this->HeightSplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Adjustable Height Spline"));
    this->LadderRungHeight = 0.00f;
    this->bExitTopInCrouchNavArea = false;
    this->bExitBottomInCrouchNavArea = false;
    this->SplineDistanceFromLadder = 57.50f;
    this->ThirdPersonClimbDownDistanceFromLadder = 40.00f;
    this->ThirdPersonClimbUpDistanceFromLadder = 50.00f;
    //this->HeightSplineComponent->SetupAttachment(InteractableComponent);
    //this->LadderBottomMeshComponent->SetupAttachment(InteractableComponent);
    //this->LadderTopperMeshComponent->SetupAttachment(InteractableComponent);
    //this->RungInstancedMeshComponent->SetupAttachment(InteractableComponent);
    //this->RungInteractionMeshComponent->SetupAttachment(InteractableComponent);
    //this->TopInteractionMeshComponent->SetupAttachment(InteractableComponent);
}


