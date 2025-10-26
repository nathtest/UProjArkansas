#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CanAbortActiveBehaviorClass.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CanAbortActiveBehaviorClass : public UBTDecorator {
    GENERATED_BODY()
public:
    UBTDecorator_CanAbortActiveBehaviorClass();

};

