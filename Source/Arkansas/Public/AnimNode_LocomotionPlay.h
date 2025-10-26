#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNode_SequencePlayer.h"

#include "AnimNode_LocomotionPlay.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FAnimNode_LocomotionPlay : public FAnimNode_SequencePlayer {
    GENERATED_BODY()
public:
    FAnimNode_LocomotionPlay();
};

