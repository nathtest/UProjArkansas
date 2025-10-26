#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EQSSelectorParam.generated.h"

class UAIEQSParameter;

USTRUCT(BlueprintType)
struct ARKANSAS_API FEQSSelectorParam : public FAIDynamicParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UAIEQSParameter> ValueSelector;
    
    FEQSSelectorParam();
};

