#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EItemDisplayRule.h"
#include "IndianaUserWidget.h"
#include "InventoryPageWidget.generated.h"

class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UInventoryPageWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayRepairAllEquippedButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableHoverTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemDisplayRule ItemDisplayRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportsSwapping;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* HeaderTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* ComparisonTextBlock;
    
public:
    UInventoryPageWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void SendFocusToItemViewer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemCompare(bool bCompared);
    
};

