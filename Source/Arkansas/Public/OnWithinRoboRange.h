#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "FactionListener.h"
#include "OnWithinRoboRange.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOnWithinRoboRange : public UFactionListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumDetectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UOnWithinRoboRange();

protected:
    UFUNCTION(BlueprintCallable)
    void OnRoboWithinRangeStateChanged(int32 PrevRoboCount, int32 CurrRoboCount);
    
};

