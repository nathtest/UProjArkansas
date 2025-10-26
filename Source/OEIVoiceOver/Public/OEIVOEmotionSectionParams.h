#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <Channels/MovieSceneFloatChannel.h>
#include "OEIVOEmotionSectionParams.generated.h"

USTRUCT(BlueprintType)
struct FOEIVOEmotionSectionParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Emotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weight;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel KeyedWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Persist;
    
    OEIVOICEOVER_API FOEIVOEmotionSectionParams();
};

