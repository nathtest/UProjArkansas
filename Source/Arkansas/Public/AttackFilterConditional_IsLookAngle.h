#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "AttackFilterConditional.h"
#include "AttackFilterConditional_IsLookAngle.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAttackFilterConditional_IsLookAngle : public UAttackFilterConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Angle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UAttackFilterConditional_IsLookAngle();

};

