#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <AnimationProxyPositionalData.h>
#include <BodyIdle.h>
#include "SubStateData.h"
#include "AnimProxySet.generated.h"

class UBodyIdleAsset;

USTRUCT(BlueprintType)
struct FAnimProxySet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationProxyPositionalData> PositionalData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodyIdle DefaultBodyIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyIdleAsset* DefaultIdleAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FSubStateData> SubAnimationStates;
    
    ARKANSAS_API FAnimProxySet();
};

