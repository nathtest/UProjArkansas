#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=SpeakerInfo -FallbackName=SpeakerInfo
#include "SpeakerInfo.h"

#include "OwCrowdAppearanceEntry.generated.h"

class UPoseAsset;

USTRUCT(BlueprintType)
struct FOwCrowdAppearanceEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpeakerInfo> SpeakerInfos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UPoseAsset> FacePoseAsset;
    
    ARKANSAS_API FOwCrowdAppearanceEntry();
};

