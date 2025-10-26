#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "SpellConditional.h"
#include "SpellConditional_TTDMeter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_TTDMeter : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    USpellConditional_TTDMeter();

};

