#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderBoolValue -FallbackName=AIDataProviderBoolValue
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_OccupiedEnvironmentNodes.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_OccupiedEnvironmentNodes : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderBoolValue IgnoreNodesOccupiedByQueryOwner;
    
public:
    UEnvQueryTest_OccupiedEnvironmentNodes();

};

