#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "AttackFilterConditional.h"
#include "AttackFilterConditional_IsAttackRange.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAttackFilterConditional_IsAttackRange : public UAttackFilterConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UAttackFilterConditional_IsAttackRange();

};

