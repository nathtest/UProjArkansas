#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EventListener.h"
#include "ItemStack.h"
#include "OnItemConsumed.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, EditInlineNew)
class UOnItemConsumed : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNourishmentConsume;
    
public:
    UOnItemConsumed();

protected:
    UFUNCTION(BlueprintCallable)
    void OnItemConsumed(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
};

