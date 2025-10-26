#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "SpellConditional.h"
#include "SpellConditional_DistanceBetweenCasterAndTarget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_DistanceBetweenCasterAndTarget : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
public:
    USpellConditional_DistanceBetweenCasterAndTarget();

};

