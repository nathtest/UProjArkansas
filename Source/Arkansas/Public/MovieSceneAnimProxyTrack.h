#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=MovieScene -ObjectName=MovieSceneDeterminismSource -FallbackName=MovieSceneDeterminismSource
#include "MovieSceneNameableTrack.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include <Tracks/MovieSceneEventTrack.h>
#include "MovieSceneAnimProxyTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable)
class ARKANSAS_API UMovieSceneAnimProxyTrack : public UMovieSceneNameableTrack, public IMovieSceneTrackTemplateProducer, public IMovieSceneDeterminismSource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFireEventsWhenForwards: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFireEventsWhenBackwards: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFireEventsAtPosition EventPosition;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
public:
    UMovieSceneAnimProxyTrack();

    // --- Required Overrides ---
    virtual const TArray<UMovieSceneSection*>& GetAllSections() const override;
    virtual void RemoveAllAnimationData() override;
    virtual bool HasSection(const UMovieSceneSection& Section) const override;
    virtual void RemoveSection(UMovieSceneSection& Section) override;
    virtual bool IsEmpty() const override;

    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const override;
    virtual void PopulateDeterminismData(FMovieSceneDeterminismData& OutData, const TRange<FFrameNumber>& Range) const override;


    // Fix for true pure virtual functions not being implemented
};

