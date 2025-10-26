#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnGadgetDeactivateVisualsDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGadgetDeactivateVisuals, FGameplayTag, GameplayTag);

