#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "ARCC_CreationEntryItem.generated.h"

class UButtonBase;
class UImage;
class UPanelWidget;
class UTextBlockBase;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UARCC_CreationEntryItem : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LockedOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTemporaryDefaultString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DefaultItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DefaultItemNameAsString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> DefaultItemIcon;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* MainButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CreationItemIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* SelectedItemPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* LockedItemPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CreationItemNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CreationItemFlavorText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CreationItemDetailText;
    
public:
    UARCC_CreationEntryItem();

    UFUNCTION(BlueprintCallable)
    void SetItemSelected(bool bIsSelected);
    
    UFUNCTION(BlueprintCallable)
    void SetItemLocked(bool bIsLocked);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnSelectChanged(bool bIsSelected);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnLockedChanged(bool bIsLocked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnFocusChanged(bool bIsHoveredFocused);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnFlavorTextSet(const FString& DescriptionText);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnEntryItemSet(bool bIsSelected, bool bIsLocked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnDetailTextSet(const FString& DescriptionText);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSelected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
};

