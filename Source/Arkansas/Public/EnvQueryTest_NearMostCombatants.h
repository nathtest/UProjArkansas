#pragma once
#include "CoreMinimal.h"
#include <DataProviders/AIDataProvider.h>
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_NearMostCombatants.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_NearMostCombatants : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxCombatantDistance;
    
public:
    UEnvQueryTest_NearMostCombatants();

};

