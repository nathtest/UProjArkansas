#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "MovieSceneCineActorSectionParams.h"
#include "MovieSceneCineActorSection.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UMovieSceneCineActorSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneCineActorSectionParams Params;
    
    UMovieSceneCineActorSection();

};

