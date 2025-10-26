#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <BodyIdle.h>
#include "FilteredBodyIdle.h"
#include "EmotionBodyEntry.generated.h"

class UBodyIdleAsset;

USTRUCT(BlueprintType)
struct FEmotionBodyEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag EntryTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EntryNameLegacy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBodyIdle BodyIdles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBodyIdle DialogIdles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyIdleAsset* BodyIdlesAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyIdleAsset* DialogIdlesAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFilteredBodyIdle> RandomIdleStates;
    
    ARKANSAS_API FEmotionBodyEntry();
};

