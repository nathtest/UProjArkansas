#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <GlobalVariableReference.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIPlatformService -ObjectName=EOEIPlatformServiceLoginResult -FallbackName=EOEIPlatformServiceLoginResult
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIPlatformService -ObjectName=EOEIPlatformServiceProvider -FallbackName=EOEIPlatformServiceProvider
#include <LocString.h>
#include "IndianaInterfaceUserWidget.h"
#include "OnCreditsStartRequestedDelegate.h"
#include "OnCreditsStopRequestedDelegate.h"
#include "Templates/SubclassOf.h"
#include "MainMenuWidget.generated.h"

class UActiveUserDisplayWidget;
class UButtonBase;
class UConversationAsset;
class UCreditsWidget;
class UInputLabelGroupWidget;
class ULevelOptionsWidget;
class UMainMenuLevelsData;
class UMainOptionsWidget;
class UOwConversationInstance;
class UPanelWidget;
class USettingsMenuWidget;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UMainMenuWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCreditsStartRequested OnCreditsStartRequestedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCreditsStopRequested OnCreditsStopRequestedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConversationAsset* MainMenuConversationAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLaunchMainMenuConversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockConversationActiveOnceStarted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference CreditsMusicGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OnCreditsStartGlobalVariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UButtonBase> ButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuWidget> SettingsMenuClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMainMenuLevelsData* MainMenuLevelsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* InvisibleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* ContentPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* CrossPlatformUserPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* PressKeyPromptPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* XboxTextblockContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* PressKeyPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* VersionTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCreditsWidget* CreditsWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULevelOptionsWidget* DeliverablesOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULevelOptionsWidget* ExtraOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMainOptionsWidget* MainOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActiveUserDisplayWidget* UsernameWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* CrossPlatformLabels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SaveTargetSettingTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TransferSavesString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TransferSavesSettingReminderString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EOEIPlatformServiceLoginResult, FLocString> LoginResultDisplayStrings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOEIPlatformServiceLoginResult OverrideLoginResult_DEBUG;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UOwConversationInstance* ActiveMainMenuConversation;
    
public:
    UMainMenuWidget();

    UFUNCTION(BlueprintCallable)
    void SetMainMenuLevelInitialized(bool bLevelInitialized);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PrepareForFadeIn();
    
    UFUNCTION(BlueprintCallable)
    void OpenMainScreen();
    
    UFUNCTION(BlueprintCallable)
    void OpenExtrasScreen();
    
    UFUNCTION(BlueprintCallable)
    void OpenDeliverablesScreen();
    
public:
    UFUNCTION(BlueprintCallable)
    void OpenCredits();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartShowMainOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartHideAnyTextPrompt();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartConversationRequested();
    
    UFUNCTION(BlueprintCallable)
    void OnShowMainOptionsComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnShowMainOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowLogo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowInterface(bool bShouldChangeLogo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowAnyTextPrompt();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRestartMainMenuStateRequested();
    
    UFUNCTION(BlueprintCallable)
    void OnQueryLatestSaveFinished(const FString& LatestSaveName);
    
    UFUNCTION(BlueprintCallable)
    void OnPlatformLoginComplete(EOEIPlatformServiceLoginResult Result, FText Error, EOEIPlatformServiceProvider Provider);
    
    UFUNCTION(BlueprintCallable)
    void OnLoginStatusChanged(bool bOldAvailability, bool bNewAvailability, EOEIPlatformServiceProvider Provider);
    
    UFUNCTION(BlueprintCallable)
    void OnLoadUserGameSettingsComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnHideMainOptionsStart();
    
    UFUNCTION(BlueprintCallable)
    void OnHideMainOptionsComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideLogo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideInterface();
    
    UFUNCTION(BlueprintCallable)
    void OnFakePlatformLoginComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnExternalMenuOpened();
    
    UFUNCTION(BlueprintCallable)
    void OnExternalMenuClosed(bool bForced);
    
    UFUNCTION(BlueprintCallable)
    void OnDefaultPlatformServiceLoginComplete(EOEIPlatformServiceLoginResult Result, FText ErrorText, EOEIPlatformServiceProvider Provider);
    
    UFUNCTION(BlueprintCallable)
    void OnCreditsInterfaceOpened();
    
    UFUNCTION(BlueprintCallable)
    void OnCreditsInterfaceClosed(bool bForced);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationStartReady(int32 StartNode);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationEnd(UOwConversationInstance* ConversationInstance);
    
    UFUNCTION(BlueprintCallable)
    void OnAnyTextPromptHideComplete();
    
};

