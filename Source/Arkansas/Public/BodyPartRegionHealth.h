#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "BodyPartRegionHealth.generated.h"

USTRUCT(BlueprintType)
struct FBodyPartRegionHealth {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag BodyPart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxNormalizedHealth;
    
    ARKANSAS_API FBodyPartRegionHealth();
};

