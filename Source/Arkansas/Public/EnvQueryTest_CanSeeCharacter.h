#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIDataProviderBoolValue -FallbackName=AIDataProviderBoolValue
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_CanSeeCharacter.generated.h"

class UEnvQueryContext;

UCLASS(Blueprintable)
class UEnvQueryTest_CanSeeCharacter : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> EnemyContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnvQueryContext> ObserverContext;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderBoolValue CheckWeaponLoS;
    
public:
    UEnvQueryTest_CanSeeCharacter();

};

