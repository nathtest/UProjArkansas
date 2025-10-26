#include "AIGroupBehavior_SequencerBase.h"
#include "LevelSequencePlayer.h"

UAIGroupBehavior_SequencerBase::UAIGroupBehavior_SequencerBase() {
    this->bEnableContinuousCooking = false;
    this->LevelSequenceAsset = NULL;
    this->SequencePlayer = CreateDefaultSubobject<ULevelSequencePlayer>(TEXT("AnimationPlayer"));
    this->bEnableAutoRole = false;
}

void UAIGroupBehavior_SequencerBase::StopSequence() {
}

void UAIGroupBehavior_SequencerBase::StartSequence() {
}



void UAIGroupBehavior_SequencerBase::Internal_OnSequenceStop() {
}

void UAIGroupBehavior_SequencerBase::Internal_OnSequenceFinished() {
}

ULevelSequencePlayer* UAIGroupBehavior_SequencerBase::GetSequencePlayer() const {
    return NULL;
}

bool UAIGroupBehavior_SequencerBase::RetrieveBindingOverrides(const FGuid& InBindingId, FMovieSceneSequenceID InSequenceID, TArray<UObject*, TInlineAllocator<1>>& OutObjects) const
{
    return false;
}

UObject* UAIGroupBehavior_SequencerBase::GetInstanceData() const
{
    return nullptr;
}


