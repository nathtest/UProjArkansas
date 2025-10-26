#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EPerkSorting.h"
#include "IndianaUserWidget.h"
#include "OnScrollingPerkAttentionDelegate.h"
#include "OnScrollingPerkAttentionLostDelegate.h"
#include "OnScrollingPerkEntryClickedDelegate.h"
#include "Templates/SubclassOf.h"
#include "ScrollingPerksListWidget.generated.h"

class UImage;
class UInputLabelWidget;
class UPanelWidget;
class UPerk;
class UScrollBox;
class UScrollingPerksListEntry;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UScrollingPerksListWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UScrollingPerksListEntry> PerkEntryWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EPerkSorting> SupportedSortingTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerkSorting DefaultSortingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> SortingTypeTextReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldSortFavoritePerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldSortAvailablePerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldSortUnavailablePerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPerksToRelocatePerFrame;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnScrollingPerkAttention OnScrollingPerkAttention;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnScrollingPerkAttentionLost OnScrollingPerkAttentionLost;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnScrollingPerkEntryClicked OnScrollingPerkEntryClicked;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UScrollingPerksListEntry* LastAttentionPerkEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* PerksScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* FavoriteDisplayPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* FavoritePerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* AvailablePerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* UnavailablePerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* SortDirectionImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* SortLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* ChangeSortLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* FavoriteCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* AvailableCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* UnavailableCount;
    
public:
    UScrollingPerksListWidget();

private:
    UFUNCTION(BlueprintCallable)
    void HandleOnPerkTransaction(UScrollingPerksListEntry* TransactingPerkEntry, bool bIsPending, bool bIsAcquired);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnPerkClicked(UScrollingPerksListEntry* ClickedPerkEntry);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnPerkAuxClicked(UScrollingPerksListEntry* ClickedPerkEntry);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnPerkAttentionLost(TSubclassOf<UPerk> LastPerkClass);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnPerkAttention(UScrollingPerksListEntry* AttentionPerkEntry);
    
};

