#pragma once
#include "CoreMinimal.h"
#include <GlobalVariableReference.h>
#include "GlobalVariablePair.generated.h"

USTRUCT(BlueprintType)
struct FGlobalVariablePair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    ARKANSAS_API FGlobalVariablePair();
};

