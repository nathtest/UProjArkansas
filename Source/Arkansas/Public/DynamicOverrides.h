#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "DynamicOverrides.generated.h"

USTRUCT(BlueprintType)
struct FDynamicOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AutoSprintName;
    
    ARKANSAS_API FDynamicOverrides();
};

