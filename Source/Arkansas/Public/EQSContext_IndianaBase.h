#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"

#include "EQSContext_IndianaBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UEQSContext_IndianaBase : public UEnvQueryContext {
    GENERATED_BODY()
public:
    UEQSContext_IndianaBase();

};

