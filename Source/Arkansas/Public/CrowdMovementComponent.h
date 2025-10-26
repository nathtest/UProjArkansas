#pragma once
#include "CoreMinimal.h"
#include "AnimationProxyCharacterMovement.h"
#include "OWRVOAvoidanceInterface.h"
#include "CrowdMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrowdMovementComponent : public UAnimationProxyCharacterMovement, public IOWRVOAvoidanceInterface {
    GENERATED_BODY()
public:
    UCrowdMovementComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

