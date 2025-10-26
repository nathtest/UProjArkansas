#pragma once
#include "CoreMinimal.h"
#include "GauntletTestController.h"
#include "ArkansasTestControllerMemoryReport.generated.h"

UCLASS(Blueprintable)
class UArkansasTestControllerMemoryReport : public UGauntletTestController {
    GENERATED_BODY()
public:
    UArkansasTestControllerMemoryReport(const FObjectInitializer& ObjectInitializer);

};

