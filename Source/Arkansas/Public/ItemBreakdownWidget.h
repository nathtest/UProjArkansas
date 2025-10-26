#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "BaseInventoryItemManagement.h"
#include "BaseWorkbenchActivtyWidget.h"
#include "CraftingMaterial.h"
#include "EMaterialSorting.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "ItemBreakdownWidget.generated.h"

class UBreakdownDialogBoxWidget;
class UBreakdownGainContainerWidget;
class UBreakdownGainEntryWidget;
class UCraftingEntryWidget;
class UCraftingMaterialItem;
class UImage;
class UInputLabelGroupWidget;
class UInputLabelWidget;
class UInventoryComponent;
class UItemToolTipWidget;
class UPanelWidget;
class UPerkInfoWidget;
class UScrollBox;
class UStackSplittingWidget;
class UWidget;
class UWidgetAnimation;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UItemBreakdownWidget : public UBaseInventoryItemManagement, public IBaseWorkbenchActivtyWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EMaterialSorting> SupportedSortingTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> SortingTypeTextReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSorting DefaultSortingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStackSplittingWidget> BreakdownSplittingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBreakdownDialogBoxWidget> BreakdownDialogueClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString WarningTextReference;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCraftingEntryWidget> MaterialEntryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReapplyFilterOnPageChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideIrrelevantMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* MaterialEntryPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* MaterialEntryScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* MaterialFilterSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* EmptyFilterDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBreakdownGainEntryWidget* ActiveMaterialFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* InputLabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBreakdownGainContainerWidget* BreakdownGainContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemToolTipWidget* StaticTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* SortDirectionImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* SortLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* ChangeSortLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* BreakdownKitInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* HermitFlawInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* SalvagingInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* ShowBreakdownResults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCraftingMaterial> MaterialItemsList;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCraftingEntryWidget* PreviousWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCraftingEntryWidget* SelectedWidget;
    
public:
    UItemBreakdownWidget();

    UFUNCTION(BlueprintCallable)
    void SendFocusToMaterialList();
    
    UFUNCTION(BlueprintCallable)
    void SendFocusToItemViewer();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnItemCountChanged(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnCraftingMaterialUnselected(UCraftingMaterialItem* UnselectedMaterial);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnCraftingMaterialSelected(UCraftingMaterialItem* SelectedMaterial);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnCraftingMaterialHighlighted(UCraftingMaterialItem* HighlightedMaterial);
    
    UFUNCTION(BlueprintCallable)
    void BreakdownAnimationFinished();
    

    // Fix for true pure virtual functions not being implemented
};

