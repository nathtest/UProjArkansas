#pragma once
#include "CoreMinimal.h"
#include <DataProviders/AIDataProvider.h>
#include "EnvQueryTest_Cover.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_PreferredCover.generated.h"

class UEnvQueryContext;
class UNavigationQueryFilter;

UCLASS(Blueprintable)
class UEnvQueryTest_PreferredCover : public UEnvQueryTest_Cover {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNavigationQueryFilter> FilterClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MinPreferredLinearDistanceFromTargetToCoverProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxPreferredLinearDistanceFromTargetToCoverProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MinPreferredPathingDistanceFromQuerierToCoverProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxPreferredPathingDistanceFromQuerierToCoverProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue PathingDistanceBoostForDyanmicCoverProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> EnemyLocationOverrideContext;
    
public:
    UEnvQueryTest_PreferredCover();

};

