#pragma once
#include "CoreMinimal.h"
#include <DataProviders/AIDataProvider.h>
#include "EnvironmentQuery/Tests/EnvQueryTest_Pathfinding.h"
#include "EnvQueryTest_OwPathfinding.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_OwPathfinding : public UEnvQueryTest_Pathfinding {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NavigationFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyCostLimit;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue CostLimit;
    
public:
    UEnvQueryTest_OwPathfinding();

};

