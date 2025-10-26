#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_DamageMemory.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_DamageMemory : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> DamageMemoryContext;
    
public:
    UEnvQueryTest_DamageMemory();

};

