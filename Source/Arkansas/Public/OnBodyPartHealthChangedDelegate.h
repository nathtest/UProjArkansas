#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnBodyPartHealthChangedDelegate.generated.h"

class UHealthComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnBodyPartHealthChanged, UHealthComponent*, HealthComponent, FGameplayTag, BodyPart, float, OldHealthNormalized, float, NewHealthNormalized);

