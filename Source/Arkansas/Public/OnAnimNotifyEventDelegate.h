#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnAnimNotifyEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimNotifyEvent, FGameplayTag, Event);

