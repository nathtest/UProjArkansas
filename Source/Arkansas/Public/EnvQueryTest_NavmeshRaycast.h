#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_NavmeshRaycast.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_NavmeshRaycast : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> DestinationContext;
    
public:
    UEnvQueryTest_NavmeshRaycast();

};

