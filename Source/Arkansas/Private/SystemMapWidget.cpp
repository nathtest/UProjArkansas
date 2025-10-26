#include "SystemMapWidget.h"

USystemMapWidget::USystemMapWidget() {
    //this->bIsFocusable = true;
    this->SelectionWidgetClass = NULL;
    this->EntryWidgetClass = NULL;
    this->QuestSortingData = NULL;
    this->SystemMapData = NULL;
    this->bOverrideShowInactiveQuests = true;
    this->bShowDialogForSingleDestination = false;
    this->bSimulateSystemMapData = false;
    this->bUseAcceleration = true;
    this->ArmMovementConstantRateLimit = 0.50f;
    this->TargetAcceleration = 1.00f;
    this->InitialVelocity = 0.75f;
    this->MaximumSpeed = 3.00f;
    this->bUseDeceleration = true;
    this->StartDecelerationRatio = 0.20f;
    this->TargetDeceleration = 1.00f;
    this->MinimumSpeed = 0.50f;
    this->bResetArrowToZeroOnEntry = true;
    this->DefaultLocationIndex = -1;
    this->InfoWidget = NULL;
    this->ActiveQuestPanel = NULL;
    this->LocationTextBlock = NULL;
    this->ActiveQuestTextBlock = NULL;
    this->LocationEntriesPanel = NULL;
    this->Intro = NULL;
    this->Outro = NULL;
    this->OutroPlaybackSpeed = 1.00f;
    this->bForceCloseOnRepeatedInput = true;
    this->CachedTargetDestination = NULL;
}

void USystemMapWidget::OnOutroFinished() {
}

FEventReply USystemMapWidget::OnMapImageMouseDownTouch(FGeometry MyGeometry, const FPointerEvent& MouseEvent) {
    return FEventReply{};
}


