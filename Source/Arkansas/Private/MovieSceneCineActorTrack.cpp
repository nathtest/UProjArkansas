#include "MovieSceneCineActorTrack.h"
#include "Evaluation/MovieSceneEvalTemplate.h"

UMovieSceneCineActorTrack::UMovieSceneCineActorTrack() {
}

const TArray<UMovieSceneSection*>& UMovieSceneCineActorTrack::GetAllSections() const
{
    return Sections;
}

void UMovieSceneCineActorTrack::RemoveAllAnimationData()
{
}

bool UMovieSceneCineActorTrack::HasSection(const UMovieSceneSection& Section) const
{
    return false;
}

void UMovieSceneCineActorTrack::RemoveSection(UMovieSceneSection& Section)
{
}

bool UMovieSceneCineActorTrack::IsEmpty() const
{
    return false;
}

FMovieSceneEvalTemplatePtr UMovieSceneCineActorTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
    return FMovieSceneEvalTemplatePtr();
}


