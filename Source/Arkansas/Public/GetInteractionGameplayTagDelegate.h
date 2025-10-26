#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "GetInteractionGameplayTagDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal(FGameplayTag, FGetInteractionGameplayTag);

