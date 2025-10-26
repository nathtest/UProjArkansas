#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_TurretControl.generated.h"

UCLASS(Blueprintable)
class UBTService_TurretControl : public UBTService {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTurretEnable;
    
public:
    UBTService_TurretControl();

};

