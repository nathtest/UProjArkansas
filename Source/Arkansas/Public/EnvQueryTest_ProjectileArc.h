#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderBoolValue -FallbackName=AIDataProviderBoolValue
#include <DataProviders/AIDataProvider.h>
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_ProjectileArc.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_ProjectileArc : public UEnvQueryTest {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue PreferredAngle;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderBoolValue CheckCollision;
    
public:
    UEnvQueryTest_ProjectileArc();

};

