#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "OwBehaviorTreeServiceInterface.h"
#include "BTService_OwBase.generated.h"

UCLASS(Abstract, Blueprintable)
class UBTService_OwBase : public UBTService, public IOwBehaviorTreeServiceInterface {
    GENERATED_BODY()
public:
    UBTService_OwBase();


    // Fix for true pure virtual functions not being implemented
};

