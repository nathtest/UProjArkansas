#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "BTDecorator_OwConditionalBase.h"
#include "ETargetInfoRelativeLocation.h"
#include "BTDecorator_TargetDistanceCheck.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_TargetDistanceCheck : public UBTDecorator_OwConditionalBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETargetInfoRelativeLocation LocationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
public:
    UBTDecorator_TargetDistanceCheck();

};

