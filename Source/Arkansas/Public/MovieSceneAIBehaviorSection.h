#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "MovieSceneAIBehaviorSectionData.h"
#include "MovieSceneAIBehaviorSection.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UMovieSceneAIBehaviorSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneAIBehaviorSectionData EventData;
    
    UMovieSceneAIBehaviorSection();

};

