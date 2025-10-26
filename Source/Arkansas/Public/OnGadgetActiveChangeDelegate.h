#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnGadgetActiveChangeDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGadgetActiveChange, FGameplayTag, GameplayTag);

