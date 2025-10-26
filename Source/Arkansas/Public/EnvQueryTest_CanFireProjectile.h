#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_CanFireProjectile.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_CanFireProjectile : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> Context;
    
public:
    UEnvQueryTest_CanFireProjectile();

};

