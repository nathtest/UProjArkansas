#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_HardPoint.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_HardPoint : public UEnvQueryTest {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> HardPointContext;
    
public:
    UEnvQueryTest_HardPoint();

};

