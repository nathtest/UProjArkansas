#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "OEIVOEmotionSectionParams.h"
#include "OEIVOEmotionExpressionSectionTemplate.generated.h"

USTRUCT(BlueprintType)
struct FOEIVOEmotionExpressionSectionTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOEIVOEmotionSectionParams Params;
    
    OEIVOICEOVER_API FOEIVOEmotionExpressionSectionTemplate();
};

