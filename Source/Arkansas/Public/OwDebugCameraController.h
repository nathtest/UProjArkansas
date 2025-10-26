#pragma once
#include "CoreMinimal.h"
#include "Engine\DebugCameraController.h"

#include "OwDebugCameraController.generated.h"

UCLASS(Blueprintable)
class AOwDebugCameraController : public ADebugCameraController {
    GENERATED_BODY()
public:
    AOwDebugCameraController(const FObjectInitializer& ObjectInitializer);

};

