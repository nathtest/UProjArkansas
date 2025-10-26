#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnInteractionAnimProxySkippedDelegate.generated.h"

class AIndianaPlayerCharacter;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInteractionAnimProxySkipped, AIndianaPlayerCharacter*, PlayerCharacter, const FGameplayTag&, SkippedAnimProxyKey);

