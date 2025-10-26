#pragma once
#include "CoreMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"

#include "OwRotatingMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UOwRotatingMovementComponent : public URotatingMovementComponent {
    GENERATED_BODY()
public:
    UOwRotatingMovementComponent(const FObjectInitializer& ObjectInitializer);

};

