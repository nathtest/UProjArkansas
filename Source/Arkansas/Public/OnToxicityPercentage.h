#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EventListener.h"
#include "OnToxicityPercentage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOnToxicityPercentage : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToxicityPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UOnToxicityPercentage();

protected:
    UFUNCTION(BlueprintCallable)
    void OnToxicityChanged(float PrevNormTox, float CurrNormTox);
    
};

