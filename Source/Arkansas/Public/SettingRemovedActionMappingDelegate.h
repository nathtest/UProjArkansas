#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InputActionKeyMapping -FallbackName=InputActionKeyMapping
#include "InputCoreTypes.h"
#include "GameFramework/InputSettings.h"
#include "SettingRemovedActionMappingDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSettingRemovedActionMapping, FInputActionKeyMapping, Value);

