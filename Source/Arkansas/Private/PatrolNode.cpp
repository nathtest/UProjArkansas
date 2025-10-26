#include "PatrolNode.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"

APatrolNode::APatrolNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    this->NextPatrolNode = NULL;
    this->bOrientOnArrival = false;
    this->Action = NULL;
    this->MovementType = EPatrolMovementType::Walk;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->bCreatedByTool = false;
    this->bCanStopOnNoneAction = true;
    this->AISettings = NULL;
}

void APatrolNode::TriggerPatrolNodeReached(AIndianaCharacter* Character) {
}

EAIMovementState APatrolNode::K2_GetMovementTypeAsState() const {
    return EAIMovementState::Walk;
}

bool APatrolNode::K2_GetCreatedByTool() const {
    return false;
}


