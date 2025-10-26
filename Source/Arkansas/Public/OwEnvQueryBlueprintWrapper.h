#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryInstanceBlueprintWrapper.h"
#include "OwEnvQueryBlueprintWrapper.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UOwEnvQueryBlueprintWrapper : public UEnvQueryInstanceBlueprintWrapper {
    GENERATED_BODY()
public:
    UOwEnvQueryBlueprintWrapper(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void AbortInstance();
    
};

