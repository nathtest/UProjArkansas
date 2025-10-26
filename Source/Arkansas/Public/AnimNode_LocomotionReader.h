#pragma once
#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_LocomotionReader.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FAnimNode_LocomotionReader : public FAnimNode_SkeletalControlBase {
    GENERATED_BODY()
public:
    FAnimNode_LocomotionReader();
};

