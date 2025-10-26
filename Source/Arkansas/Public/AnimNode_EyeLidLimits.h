#pragma once
#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_EyeLidLimitEntry.h"
#include "AnimNode_EyeLidLimits.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FAnimNode_EyeLidLimits : public FAnimNode_SkeletalControlBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpperLidCorrectAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverlapDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimNode_EyeLidLimitEntry> EyeLidEntries;
    
    FAnimNode_EyeLidLimits();
};

