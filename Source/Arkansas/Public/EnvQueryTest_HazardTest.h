#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_HazardTest.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_HazardTest : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> HazardContext;
    
public:
    UEnvQueryTest_HazardTest();

};

