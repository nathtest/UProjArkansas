#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Slate -ObjectName=InputChord -FallbackName=InputChord
#include "IndianaUserWidget.h"
#include "Templates/SubclassOf.h"
#include "SettingsMenuKeyRebindWidget.generated.h"

class UBindingConflictDialogWidget;
class UButtonBase;
class UKeyBindsMenuWidget;
class USettingsMenuInputKeySelector;
class USettingsMenuWidget;
class UTextBlockBase;
class UUserSettingKeyBinding;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class USettingsMenuKeyRebindWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreModifierKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBindingConflictDialogWidget> RebindConflictDialogClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* SettingName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USettingsMenuInputKeySelector* PrimaryKeySelector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USettingsMenuInputKeySelector* SecondaryKeySelector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* GameplayButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* EssentialWarningDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UUserSettingKeyBinding* UserSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USettingsMenuWidget* SettingsMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UKeyBindsMenuWidget* ParentWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLocString SettingNameString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsSelecting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SelectionIndex;
    
public:
    USettingsMenuKeyRebindWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSecondaryIsSelectingKeyChanged(bool bIsSelectingKey);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimaryIsSelectingKeyChanged(bool bIsSelectingKey);
    
    UFUNCTION(BlueprintCallable)
    void OnKeySelected(FInputChord InputChord);
    
    UFUNCTION(BlueprintCallable)
    void OnContainerClicked();
    
    UFUNCTION(BlueprintCallable)
    void OnBack();
    
};

