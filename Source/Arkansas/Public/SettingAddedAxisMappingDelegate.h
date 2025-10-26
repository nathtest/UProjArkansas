#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InputAxisKeyMapping -FallbackName=InputAxisKeyMapping
#include "InputCoreTypes.h"
#include "GameFramework/InputSettings.h"
#include "SettingAddedAxisMappingDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSettingAddedAxisMapping, FInputAxisKeyMapping, Value);

