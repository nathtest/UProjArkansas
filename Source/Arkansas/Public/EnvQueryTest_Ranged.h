#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"

#include "Templates/SubclassOf.h"
#include "EnvQueryTest_Ranged.generated.h"

class UEnvQueryContext;

UCLASS(Abstract, Blueprintable)
class UEnvQueryTest_Ranged : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> TargetContext;
    
public:
    UEnvQueryTest_Ranged();

};

