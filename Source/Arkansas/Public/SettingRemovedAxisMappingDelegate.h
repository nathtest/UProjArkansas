#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InputAxisKeyMapping -FallbackName=InputAxisKeyMapping
#include "GameFramework\PlayerInput.h"


#include "SettingRemovedAxisMappingDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSettingRemovedAxisMapping, FInputAxisKeyMapping, Value);

