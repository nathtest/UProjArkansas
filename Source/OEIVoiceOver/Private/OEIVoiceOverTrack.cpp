#include "OEIVoiceOverTrack.h"
#include "Evaluation/MovieSceneEvalTemplate.h"

UOEIVoiceOverTrack::UOEIVoiceOverTrack() {
}

const TArray<UMovieSceneSection*>& UOEIVoiceOverTrack::GetAllSections() const
{
	return AnimationSections;
}

void UOEIVoiceOverTrack::RemoveAllAnimationData()
{
}

bool UOEIVoiceOverTrack::HasSection(const UMovieSceneSection& Section) const
{
	return false;
}

void UOEIVoiceOverTrack::RemoveSection(UMovieSceneSection& Section)
{
}

bool UOEIVoiceOverTrack::IsEmpty() const
{
	return false;
}

FMovieSceneEvalTemplatePtr UOEIVoiceOverTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
	return FMovieSceneEvalTemplatePtr();
}


