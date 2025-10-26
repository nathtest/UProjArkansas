#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderBoolValue -FallbackName=AIDataProviderBoolValue
#include <DataProviders/AIDataProvider.h>
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_OccupiedSpaceV2.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_OccupiedSpaceV2 : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue Radius;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderBoolValue LineOfSight;
    
public:
    UEnvQueryTest_OccupiedSpaceV2();

};

