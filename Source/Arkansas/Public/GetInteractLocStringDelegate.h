#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "GetInteractLocStringDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal(FLocString, FGetInteractLocString);

