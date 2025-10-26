#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <FacialIdle.h>
#include "EmotionFacialEntry.generated.h"

USTRUCT(BlueprintType)
struct FEmotionFacialEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag EntryTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialIdle FacialIdles;
    
    ARKANSAS_API FEmotionFacialEntry();
};

