#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "TelemetryHelper.generated.h"

UCLASS(Blueprintable)
class GAMETELEMETRY_API UTelemetryHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTelemetryHelper();

};

