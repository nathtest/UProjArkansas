#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderBoolValue -FallbackName=AIDataProviderBoolValue
#include <DataProviders/AIDataProvider.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderIntValue -FallbackName=AIDataProviderIntValue
#include "EnvQueryTest_Ranged.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_PreferredRanged.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_PreferredRanged : public UEnvQueryTest_Ranged {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MinPreferredRangeProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxPreferredRangeProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue RepositionTypeProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderBoolValue PrefersStationaryProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderIntValue DirectionGroupCountProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderIntValue DirectionGroupPreferredRangeCountProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue ElevationDeltaGroupThresholdProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> TargetLocationOverrideContext;
    
public:
    UEnvQueryTest_PreferredRanged();

};

