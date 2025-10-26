#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EDisablePriority.h"
#include "DisablePriorityMapElement.generated.h"

USTRUCT(BlueprintType)
struct FDisablePriorityMapElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DisableType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDisablePriority Priority;
    
    ARKANSAS_API FDisablePriorityMapElement();
};

