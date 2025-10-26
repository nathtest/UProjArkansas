#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=Margin -FallbackName=Margin
#include "EVendorPages.h"
#include "IndianaInterfaceUserWidget.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "VendorWidget.generated.h"

class UAmmoDisplayWidget;
class UCartInfoWidget;
class UFlaw;
class UImage;
class UInputLabelGroupWidget;
class UInputLabelWidget;
class UInventoryComponent;
class UItemInspectorWidget;
class UItemToolTipWidget;
class UItemViewerButtonWidget;
class UItemViewerNavigationWidget;
class UItemViewerWidget;
class UNavigationGroupWidget;
class UPanelWidget;
class UPerk;
class UPerkInfoWidget;
class UPlayerStatsWidget;
class UScrollBox;
class UScrollingWidgetGroup;
class UStackSplittingWidget;
class UTextBlockBase;
class UTexture2D;
class UWidget;
class UWidgetAnimation;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UVendorWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StackSplittingViewerOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RestrictedLockedTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RestrictedUnlockedTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyShowEncounterFactionsIfEncountered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> HideFactionModifierList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FactionDiscountIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FactionSurchargeIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> ConsumerismFlaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerk> RestrictedAccessPerk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerk> TenetTransgressorPerk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin PositionRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin PositionLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UItemViewerButtonWidget* HoveredItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UScrollingWidgetGroup* ScrollingWidgetGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* TooltipContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemToolTipWidget* ItemToolTipWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemToolTipWidget* CompareTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* CartInfoContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCartInfoWidget* CartInfoWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* CartDisplaySwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* BuyCartDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* CantAffordFullStackDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* CantAffordDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* BuyDiscountSurchargeTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* FactionDiscountDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* FactionLogo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* FactionDiscountTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* FactionIndicatorSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* WholesaleSpenderInfo_Buy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* WholesaleSpenderInfo_Sell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* WholesaleSpenderActiveIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* DiscountFadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* ConsumerismBuyInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* HermitFlawInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* WastefulFlawInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* RestrictedAccessDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* RestrictedAccessAvailableDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* RestrictedAccessPerkInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* SellCartDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* SellDiscountSurchargeTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* ConsumerismSellInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* KleptomaniaFlawInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* PalmGreaserPerkInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* SnobbishFlawInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* TenetTransgressorPerkInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* NoSellCartDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* FinalPriceDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* BasePriceTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* FinalPriceTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* PageScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavigationGroupWidget* NavigationGroupWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmmoDisplayWidget* AmmoDisplayWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerStatsWidget* PlayerStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* VendorNameTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* FactionNameTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* ExitLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* LabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemViewerWidget* VendorViewer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemViewerNavigationWidget* VendorSubNavigationWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemViewerWidget* PlayerSellViewer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemViewerNavigationWidget* PlayerSellSubNavigationWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStackSplittingWidget> StackSplittingClass;
    
public:
    UVendorWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateWholesaleSpenderProgress(const int32 BitsGained);
    
    UFUNCTION(BlueprintCallable)
    void UpdateWholesaleSpenderPreview(const int32 PreviewBits);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSubnavigationActivation();
    
    UFUNCTION(BlueprintCallable)
    void OnStoreItemRemoved(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnStoreItemAdded(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnStoreCountChanged(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowBasePriceChanged(bool bShowBasePrice);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetCurrentPage(EVendorPages Page, bool bAnimate);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerItemRemoved(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerItemAdded(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerCountChanged(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPerkAnimationComplete();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemInspectorClosed(UItemInspectorWidget* ItemInspectorWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAnimationSoldJunk();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAnimationSoldItem();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAnimationBoughtItem();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FadeInFactionImage();
    
    UFUNCTION(BlueprintCallable)
    void CompleteWholesaleSpender();
    
};

