#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "OEIVOEmotionSectionParams.h"
#include "OEIVOEmotionSectionTemplate.generated.h"

USTRUCT(BlueprintType)
struct FOEIVOEmotionSectionTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOEIVOEmotionSectionParams Params;
    
    OEIVOICEOVER_API FOEIVOEmotionSectionTemplate();
};

