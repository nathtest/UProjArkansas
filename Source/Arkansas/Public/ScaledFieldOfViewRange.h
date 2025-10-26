#pragma once
#include "CoreMinimal.h"
#include <EOEIFieldOfViewAxis.h>
#include "ScaledFieldOfViewRange.generated.h"

USTRUCT(BlueprintType)
struct FScaledFieldOfViewRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnforceMinFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnforceMaxFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOEIFieldOfViewAxis Axis;
    
    ARKANSAS_API FScaledFieldOfViewRange();
};

