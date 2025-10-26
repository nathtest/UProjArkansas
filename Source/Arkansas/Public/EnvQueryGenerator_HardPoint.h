#pragma once
#include "CoreMinimal.h"
#include <DataProviders/AIDataProvider.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderIntValue -FallbackName=AIDataProviderIntValue
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryGenerator_HardPoint.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable, EditInlineNew)
class UEnvQueryGenerator_HardPoint : public UEnvQueryGenerator_ProjectedPoints {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> SampleOriginContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> HardPointContext;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue FarGridSize;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderIntValue FarGridSampleCount;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderIntValue NearDimensionCount;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue NearSpaceBetween;
    
public:
    UEnvQueryGenerator_HardPoint();

};

