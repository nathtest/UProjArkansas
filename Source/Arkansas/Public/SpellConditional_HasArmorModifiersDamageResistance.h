#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "SpellConditional.h"
#include "SpellConditional_HasArmorModifiersDamageResistance.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_HasArmorModifiersDamageResistance : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    USpellConditional_HasArmorModifiersDamageResistance();

};

