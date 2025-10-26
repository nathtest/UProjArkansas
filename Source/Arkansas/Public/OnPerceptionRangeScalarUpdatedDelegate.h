#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnPerceptionRangeScalarUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerceptionRangeScalarUpdated, const FGameplayTagContainer&, CreatureType);

