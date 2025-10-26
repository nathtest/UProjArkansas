#pragma once
#include "CoreMinimal.h"
#include "ETrackingRegionLockBehavior.generated.h"

UENUM(BlueprintType)
enum class ETrackingRegionLockBehavior : uint8 {
    MaintainCurrentOrientation = 1,
    ResetOrientation = 0,
};

