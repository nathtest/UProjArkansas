#include "MovieSceneAIBehaviorTrack.h"
#include "Evaluation/MovieSceneEvalTemplate.h"

UMovieSceneAIBehaviorTrack::UMovieSceneAIBehaviorTrack() {
    this->bFireEventsWhenForwards = true;
    this->bFireEventsWhenBackwards = true;
    this->EventPosition = EFireEventsAtPosition::AtEndOfEvaluation;
}

const TArray<UMovieSceneSection*>& UMovieSceneAIBehaviorTrack::GetAllSections() const
{
    return Sections;
}

void UMovieSceneAIBehaviorTrack::RemoveAllAnimationData()
{
}

bool UMovieSceneAIBehaviorTrack::HasSection(const UMovieSceneSection& Section) const
{
    return false;
}

void UMovieSceneAIBehaviorTrack::RemoveSection(UMovieSceneSection& Section)
{
}

bool UMovieSceneAIBehaviorTrack::IsEmpty() const
{
    return false;
}

FMovieSceneEvalTemplatePtr UMovieSceneAIBehaviorTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
    return FMovieSceneEvalTemplatePtr();
}

void UMovieSceneAIBehaviorTrack::PopulateDeterminismData(FMovieSceneDeterminismData& OutData, const TRange<FFrameNumber>& Range) const
{
}


