#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "Blueprint/UserWidget.h"
#include "ButtonBaseContainerWidget.generated.h"

class UButtonBase;
class UImage;
class USizeBox;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UButtonBaseContainerWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TextReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockDisplayBehaviorWhenLocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockDisablesButton;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* TextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* InterestIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LockedIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* ButtonSizeBox;
    
public:
    UButtonBaseContainerWidget();

    UFUNCTION(BlueprintCallable)
    void SetLocked(bool bLocked, bool bForceState);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bEnabled);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnSelectChanged(bool bIsSelected);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnFocusChanged(bool bIsHoveredFocused);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyLockState(bool bIsStateLocked);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsButtonLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsButtonEnabled() const;
    
    UFUNCTION(BlueprintCallable)
    void ActivateInterestIcon(bool bActivate);
    
};

