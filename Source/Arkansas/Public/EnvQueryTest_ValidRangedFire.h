#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderBoolValue -FallbackName=AIDataProviderBoolValue
#include <DataProviders/AIDataProvider.h>
#include "EnvQueryTest_Ranged.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_ValidRangedFire.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_ValidRangedFire : public UEnvQueryTest_Ranged {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> TargetAimLocationsOverrideContext;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderBoolValue FilterVerticalRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MinVerticalRangeDeg;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue MaxVerticalRangeDeg;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue LateralLineOfSightBuffer;
    
public:
    UEnvQueryTest_ValidRangedFire();

};

