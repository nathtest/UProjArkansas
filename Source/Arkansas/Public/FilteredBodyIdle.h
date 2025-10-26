#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <BodyIdle.h>
#include "FilteredBodyIdle.generated.h"

class UBodyIdleAsset;

USTRUCT(BlueprintType)
struct FFilteredBodyIdle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBodyIdle BodyIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyIdleAsset* BodyIdleAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChanceToPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer IgnoreFilters;
    
    ARKANSAS_API FFilteredBodyIdle();
};

