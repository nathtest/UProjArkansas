#include "MovieSceneAnimProxyTrack.h"
#include "Evaluation/MovieSceneEvalTemplate.h"


UMovieSceneAnimProxyTrack::UMovieSceneAnimProxyTrack() {
    this->bFireEventsWhenForwards = true;
    this->bFireEventsWhenBackwards = true;
    this->EventPosition = EFireEventsAtPosition::AtEndOfEvaluation;
}

const TArray<UMovieSceneSection*>& UMovieSceneAnimProxyTrack::GetAllSections() const
{
    return Sections;
}

void UMovieSceneAnimProxyTrack::RemoveAllAnimationData()
{
}

bool UMovieSceneAnimProxyTrack::HasSection(const UMovieSceneSection& Section) const
{
    return false;
}

void UMovieSceneAnimProxyTrack::RemoveSection(UMovieSceneSection& Section)
{
}

bool UMovieSceneAnimProxyTrack::IsEmpty() const
{
    return false;
}

FMovieSceneEvalTemplatePtr UMovieSceneAnimProxyTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
    return FMovieSceneEvalTemplatePtr();
}

void UMovieSceneAnimProxyTrack::PopulateDeterminismData(FMovieSceneDeterminismData& OutData, const TRange<FFrameNumber>& Range) const
{
}


