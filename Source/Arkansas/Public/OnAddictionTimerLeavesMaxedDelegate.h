#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnAddictionTimerLeavesMaxedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddictionTimerLeavesMaxed, FGameplayTag, TimerTag);

