#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnHackingCompletedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHackingCompleted, FGameplayTag, HackTag);

