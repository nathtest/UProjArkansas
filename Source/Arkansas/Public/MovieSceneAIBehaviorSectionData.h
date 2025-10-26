#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=FrameNumber -FallbackName=FrameNumber
#include "Channels\MovieSceneChannel.h"
#include "MovieSceneAIBehaviorPayload.h"
#include "MovieSceneAIBehaviorSectionData.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FMovieSceneAIBehaviorSectionData : public FMovieSceneChannel {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFrameNumber> Times;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieSceneAIBehaviorPayload> KeyValues;
    
public:
    FMovieSceneAIBehaviorSectionData();
};

