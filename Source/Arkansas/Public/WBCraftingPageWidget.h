#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "BaseWorkbenchActivtyWidget.h"
#include "EArmorModSlot.h"
#include "ECategoryFilterType.h"
#include "EConsumableFilterType.h"
#include "EItemRenderScaleModifier.h"
#include "EModSlot.h"
#include "ERecipeSorting.h"
#include "IndianaUserWidget.h"
#include "Templates/SubclassOf.h"
#include "WBCraftingPageWidget.generated.h"

class UActorRenderWidget;
class UBorder;
class UButtonBase;
class UCraftingEntryWidget;
class UInputLabelGroupWidget;
class UInputLabelWidget;
class UItemRequirementsTooltipWidget;
class UNavigationGroupWidget;
class UPanelWidget;
class UPerkInfoWidget;
class UScrollBox;
class UTextBlockBase;
class UTexture2D;
class UVerticalBox;
class UWidgetAnimation;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UWBCraftingPageWidget : public UIndianaUserWidget, public IBaseWorkbenchActivtyWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECategoryFilterType, FGameplayTag> RecipeTagPerCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubFilterConsumableCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EConsumableFilterType, FGameplayTag> RecipeTagPerConsumable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubFilterWeaponCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSubFilterArmorCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EArmorModSlot> ArmorModSubFilters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultCategoryIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCraftingEntryWidget> CraftingEntryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCraftingFromItemViewerScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireHasItemForModificationHotkey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetFocusAfterItemBecomesUncraftable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxCraftsToRelocatePerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor CraftCommandCraftableColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowCraftCommandWhenCraftingBlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor CraftCommandNotCraftableColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavigationGroupWidget* CategoryNavigationBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavigationGroupWidget* ConsumableNavigationBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavigationGroupWidget* WeaponNavigationBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavigationGroupWidget* ArmorNavigationBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* SortLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* ChangeSortLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ERecipeSorting> SupportedSortingTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERecipeSorting DefaultSortingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> SortingTypeTextReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* EntryScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* FavoritesPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* FavoriteEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* ValidEntriesVBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* InvalidEntriesVBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* InvisibleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* ItemDisplayPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* ItemDisplayCraftCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* CraftCommandBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CraftCommandCraftCountText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkInfoWidget* PerkInfoWithBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemRequirementsTooltipWidget* CraftingContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NoAvailableRecipesTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* PassTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* FailTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* CraftingRecipePanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorRenderWidget* CraftedItemRender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepTooltipAndRenderOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* InputLabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* OnCannotCraftAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* OnCraftSuccessAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetConsumableNavBarToZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetWeaponNavBarToZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetArmorNavBarToZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EItemRenderScaleModifier, float> ScaleModifierValues;
    
public:
    UWBCraftingPageWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateArmorerProgress(int32 CurrentDTBonus, float ProgressToNextDTBonus);
    
    UFUNCTION(BlueprintCallable)
    void UpdateArmorerPreview(int32 PotentialDTBonus, float PotentialProgressToNextDTBonus);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnWeaponNavigationComplete(EModSlot CurrentWeaponMod);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnRecipeHighlighted(UCraftingEntryWidget* HighlightedRecipe);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnCraftComplete(bool bIsCraftSuccessful);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnConsumableNavigationComplete(EConsumableFilterType CurrentConsumable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnCategoryNavigationComplete(ECategoryFilterType CurrentCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnArmorNavigationComplete(EArmorModSlot CurrentArmorMod);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnActivityActiveStatusChange(bool bIsActivityActive);
    

    // Fix for true pure virtual functions not being implemented
};

