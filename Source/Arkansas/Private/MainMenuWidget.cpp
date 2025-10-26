#include "MainMenuWidget.h"
#include "EOEIPlatformServiceLoginResult.h"

UMainMenuWidget::UMainMenuWidget() {
    this->MainMenuConversationAsset = NULL;
    this->bLaunchMainMenuConversation = false;
    this->bLockConversationActiveOnceStarted = false;
    this->OnCreditsStartGlobalVariableValue = 0;
    this->ButtonClass = NULL;
    this->SettingsMenuClass = NULL;
    this->MainMenuLevelsData = NULL;
    this->InvisibleButton = NULL;
    this->ContentPanel = NULL;
    this->CrossPlatformUserPanel = NULL;
    this->PressKeyPromptPanel = NULL;
    this->XboxTextblockContainer = NULL;
    this->PressKeyPrompt = NULL;
    this->VersionTextBlock = NULL;
    this->CreditsWidget = NULL;
    this->DeliverablesOptions = NULL;
    this->ExtraOptions = NULL;
    this->MainOptions = NULL;
    this->UsernameWidget = NULL;
    this->CrossPlatformLabels = NULL;
    this->OverrideLoginResult_DEBUG = EOEIPlatformServiceLoginResult::Success;
    this->ActiveMainMenuConversation = NULL;
}

void UMainMenuWidget::SetMainMenuLevelInitialized(bool bLevelInitialized) {
}


void UMainMenuWidget::OpenMainScreen() {
}

void UMainMenuWidget::OpenExtrasScreen() {
}

void UMainMenuWidget::OpenDeliverablesScreen() {
}

void UMainMenuWidget::OpenCredits() {
}




void UMainMenuWidget::OnShowMainOptionsComplete() {
}

void UMainMenuWidget::OnShowMainOptions() {
}





void UMainMenuWidget::OnQueryLatestSaveFinished(const FString& LatestSaveName) {
}

void UMainMenuWidget::OnPlatformLoginComplete(EOEIPlatformServiceLoginResult Result, FText Error, EOEIPlatformServiceProvider Provider) {
}

void UMainMenuWidget::OnLoginStatusChanged(bool bOldAvailability, bool bNewAvailability, EOEIPlatformServiceProvider Provider) {
}

void UMainMenuWidget::OnLoadUserGameSettingsComplete() {
}

void UMainMenuWidget::OnHideMainOptionsStart() {
}

void UMainMenuWidget::OnHideMainOptionsComplete() {
}



void UMainMenuWidget::OnFakePlatformLoginComplete() {
}

void UMainMenuWidget::OnExternalMenuOpened() {
}

void UMainMenuWidget::OnExternalMenuClosed(bool bForced) {
}

void UMainMenuWidget::OnDefaultPlatformServiceLoginComplete(EOEIPlatformServiceLoginResult Result, FText ErrorText, EOEIPlatformServiceProvider Provider) {
}

void UMainMenuWidget::OnCreditsInterfaceOpened() {
}

void UMainMenuWidget::OnCreditsInterfaceClosed(bool bForced) {
}

void UMainMenuWidget::OnConversationStartReady(int32 StartNode) {
}

void UMainMenuWidget::OnConversationEnd(UOwConversationInstance* ConversationInstance) {
}

void UMainMenuWidget::OnAnyTextPromptHideComplete() {
}


