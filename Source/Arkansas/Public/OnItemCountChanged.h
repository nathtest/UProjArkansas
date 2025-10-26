#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <EComparisonOperator.h>
#include "EventListener.h"
#include "ItemStack.h"
#include "OnItemCountChanged.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, EditInlineNew)
class UOnItemCountChanged : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireOldCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OldItemCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator OldItemCountOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireNewCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NewItemCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator NewItemCountOperator;
    
public:
    UOnItemCountChanged();

protected:
    UFUNCTION(BlueprintCallable)
    void OnItemCountChanged(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack, int32 OldCount);
    
};

