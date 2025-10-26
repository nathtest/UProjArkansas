#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "Templates/SubclassOf.h"
#include "SettingsMenuInputKeySelector.generated.h"

class UButtonBase;
class UImage;
class UKeybindDialogBoxWidget;
class UTextBlockBase;

UCLASS(Blueprintable, EditInlineNew)
class USettingsMenuInputKeySelector : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString NoKeySpecifiedText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* KeyInputTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* InputIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UKeybindDialogBoxWidget> KeybindDialogBoxClass;
    
public:
    USettingsMenuInputKeySelector();

protected:
    UFUNCTION(BlueprintCallable)
    void OnRightClicked();
    
    UFUNCTION(BlueprintCallable)
    void OnClicked();
    
};

