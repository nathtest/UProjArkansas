#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryGenerator_FeetLocation.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable, EditInlineNew)
class UEnvQueryGenerator_FeetLocation : public UEnvQueryGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> QueryContext;
    
public:
    UEnvQueryGenerator_FeetLocation();

};

