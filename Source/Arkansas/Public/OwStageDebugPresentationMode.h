#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICinematics -ObjectName=OEICinePresentationMode -FallbackName=OEICinePresentationMode
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICinematics -ObjectName=OEICinematicShotController -FallbackName=OEICinematicShotController
#include "OEICinePresentationMode.h"
#include "OEICinematicShotController.h"

#include "OwStageDebugPresentationMode.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UOwStageDebugPresentationMode : public UOEICinePresentationMode, public IOEICinematicShotController {
    GENERATED_BODY()
public:
    UOwStageDebugPresentationMode();


    // Fix for true pure virtual functions not being implemented
};

