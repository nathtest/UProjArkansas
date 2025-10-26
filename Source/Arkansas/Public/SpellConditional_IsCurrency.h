#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "SpellConditional.h"
#include "SpellConditional_IsCurrency.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_IsCurrency : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
public:
    USpellConditional_IsCurrency();

};

