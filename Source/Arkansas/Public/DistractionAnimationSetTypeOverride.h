#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "DistractionAnimationSet.h"
#include "DistractionAnimationSetTypeOverride.generated.h"

USTRUCT(BlueprintType)
struct FDistractionAnimationSetTypeOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer DistractionTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDistractionAnimationSet AnimationSet;
    
    ARKANSAS_API FDistractionAnimationSetTypeOverride();
};

