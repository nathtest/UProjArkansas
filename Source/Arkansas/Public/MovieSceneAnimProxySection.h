#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "MovieSceneAnimProxySectionData.h"
#include "MovieSceneAnimProxySection.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UMovieSceneAnimProxySection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneAnimProxySectionData EventData;
    
    UMovieSceneAnimProxySection();

};

