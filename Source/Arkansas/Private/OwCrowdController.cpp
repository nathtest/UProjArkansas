#include "OwCrowdController.h"
#include <Navigation/CrowdFollowingComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=CrowdFollowingComponent -FallbackName=CrowdFollowingComponent

AOwCrowdController::AOwCrowdController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent"))) {
}


