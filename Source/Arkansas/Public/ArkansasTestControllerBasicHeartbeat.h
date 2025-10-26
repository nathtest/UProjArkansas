#pragma once
#include "CoreMinimal.h"
#include "GauntletTestController.h"

#include "ArkansasTestControllerBasicHeartbeat.generated.h"

UCLASS(Blueprintable)
class UArkansasTestControllerBasicHeartbeat : public UGauntletTestController {
    GENERATED_BODY()
public:
    UArkansasTestControllerBasicHeartbeat(const FObjectInitializer& ObjectInitializer);

};

