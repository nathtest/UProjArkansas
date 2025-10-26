#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_Cover.generated.h"

class UEnvQueryContext;

UCLASS(Abstract, Blueprintable)
class UEnvQueryTest_Cover : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> EnemyContext;
    
public:
    UEnvQueryTest_Cover();

};

