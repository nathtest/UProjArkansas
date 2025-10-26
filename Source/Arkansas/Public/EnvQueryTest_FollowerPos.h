#pragma once
#include "CoreMinimal.h"
#include <DataProviders/AIDataProvider.h>
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_FollowerPos.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_FollowerPos : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> OriginContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> ForwardContext;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue IdealAngleProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MinAngleProvider;
    
public:
    UEnvQueryTest_FollowerPos();

};

