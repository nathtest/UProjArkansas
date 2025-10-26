#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BT_Con_MechIsDead.generated.h"

UCLASS(Blueprintable)
class UBT_Con_MechIsDead : public UBTDecorator {
    GENERATED_BODY()
public:
    UBT_Con_MechIsDead();

};

