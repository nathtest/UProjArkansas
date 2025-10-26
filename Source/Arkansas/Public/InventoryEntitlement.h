#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ItemDefinitionVariant.h"
#include "InventoryEntitlement.generated.h"

USTRUCT(BlueprintType)
struct FInventoryEntitlement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemDefinitionVariant> Items;
    
    ARKANSAS_API FInventoryEntitlement();
};

