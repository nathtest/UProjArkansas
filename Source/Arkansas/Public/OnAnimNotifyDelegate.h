#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnAnimNotifyDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimNotify, FGameplayTag, Event);

