#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "OwCrowdController.generated.h"

UCLASS(Blueprintable)
class AOwCrowdController : public AAIController {
    GENERATED_BODY()
public:
    AOwCrowdController(const FObjectInitializer& ObjectInitializer);

};

