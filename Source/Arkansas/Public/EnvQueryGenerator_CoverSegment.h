#pragma once
#include "CoreMinimal.h"
#include <DataProviders/AIDataProvider.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderIntValue -FallbackName=AIDataProviderIntValue
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryGenerator_CoverSegment.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable, EditInlineNew)
class UEnvQueryGenerator_CoverSegment : public UEnvQueryGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue SearchRadius;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderIntValue CoverTypesProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> SearchCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseOctree;
    
    UEnvQueryGenerator_CoverSegment();

};

