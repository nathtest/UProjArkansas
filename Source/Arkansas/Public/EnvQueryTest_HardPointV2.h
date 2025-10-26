#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_HardPointV2.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_HardPointV2 : public UEnvQueryTest {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> Context;
    
public:
    UEnvQueryTest_HardPointV2();

};

