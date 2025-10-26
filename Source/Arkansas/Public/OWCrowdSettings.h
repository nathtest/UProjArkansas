#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include <GameplayTagContainer.h>
#include "CrimeResponseData.h"
#include "Templates/SubclassOf.h"
#include "OWCrowdSettings.generated.h"

class UNavigationQueryFilter;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UOWCrowdSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FCrimeResponseData> StationaryCrimeResponseData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float CrowdMaxSightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float CrowdRadiusToAvoid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float CrowdFieldOfViewDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float CrowdCombatDeescalation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNavigationQueryFilter> CrowdNavigationFilterClass;
    
    UPROPERTY(EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    uint32 MaxDetectionUpdatesPerFrame;
    
    UOWCrowdSettings();

};

