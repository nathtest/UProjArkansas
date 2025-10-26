#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=EEnvQueryStatus -FallbackName=EEnvQueryStatus
#include "EnvironmentQuery\EnvQueryTypes.h"

#include "OnAsyncEQSResultDelegate.generated.h"

class UEnvQueryInstanceBlueprintWrapper;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAsyncEQSResult, UEnvQueryInstanceBlueprintWrapper*, QueryInstance, TEnumAsByte<EEnvQueryStatus::Type>, QueryStatus);

