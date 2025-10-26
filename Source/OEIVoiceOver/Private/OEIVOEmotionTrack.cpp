#include "OEIVOEmotionTrack.h"
#include "Evaluation/MovieSceneEvalTemplate.h"

UOEIVOEmotionTrack::UOEIVOEmotionTrack() {
}

const TArray<UMovieSceneSection*>& UOEIVOEmotionTrack::GetAllSections() const
{
    return Sections;
}

void UOEIVOEmotionTrack::RemoveAllAnimationData()
{
}

bool UOEIVOEmotionTrack::HasSection(const UMovieSceneSection& Section) const
{
    return false;
}

void UOEIVOEmotionTrack::RemoveSection(UMovieSceneSection& Section)
{
}

bool UOEIVOEmotionTrack::IsEmpty() const
{
    return false;
}

FMovieSceneEvalTemplatePtr UOEIVOEmotionTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
    return FMovieSceneEvalTemplatePtr();
}


