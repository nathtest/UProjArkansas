#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "WaitData.generated.h"

USTRUCT(BlueprintType)
struct FWaitData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StepValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString LocString;
    
    ARKANSAS_API FWaitData();
};

