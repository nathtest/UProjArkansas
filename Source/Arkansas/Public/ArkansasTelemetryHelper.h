#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=GameTelemetry -ObjectName=TelemetryHelper -FallbackName=TelemetryHelper
#include "ArkansasTelemetryHelper.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UArkansasTelemetryHelper : public UObject /*UTelemetryHelper*/ {
    GENERATED_BODY()
public:
    UArkansasTelemetryHelper();

};

