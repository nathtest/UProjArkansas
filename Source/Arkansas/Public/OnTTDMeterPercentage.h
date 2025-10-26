#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EventListener.h"
#include "OnTTDMeterPercentage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOnTTDMeterPercentage : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TTDMeterPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UOnTTDMeterPercentage();

protected:
    UFUNCTION(BlueprintCallable)
    void OnTTDMeterChanged(float PrevValue, float CurrValue);
    
};

