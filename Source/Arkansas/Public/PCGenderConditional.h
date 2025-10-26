#pragma once
#include "CoreMinimal.h"
#include <EOEIGender.h>
#include "EEqualityComparison.h"
#include "PCGenderConditional.generated.h"

USTRUCT(BlueprintType)
struct FPCGenderConditional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEqualityComparison Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOEIGender ComparisonGender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefault;
    
    ARKANSAS_API FPCGenderConditional();
};

