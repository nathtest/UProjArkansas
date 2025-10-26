#include "IndianaPlayerController.h"
#include "OwCheatManager.h"
#include "GameFramework/PlayerInput.h"

AIndianaPlayerController::AIndianaPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CheatClass = UOwCheatManager::StaticClass();
    this->ClickEventKeys.AddDefaulted(1);
    this->IndianaPlayerCharacter = NULL;
}

void AIndianaPlayerController::UnpinGlobalVariable(const FString& GlobalVariable) {
}

void AIndianaPlayerController::ToggleQuestLog() {
}

void AIndianaPlayerController::TogglePauseMenu() {
}

void AIndianaPlayerController::ToggleMap() {
}

void AIndianaPlayerController::ToggleLedger() {
}

void AIndianaPlayerController::ToggleInventory() {
}

void AIndianaPlayerController::ToggleCompanions() {
}

void AIndianaPlayerController::ToggleCharacterSummary() {
}

void AIndianaPlayerController::SetYAxisInverted(bool bIsInverted) {
}

void AIndianaPlayerController::SetXAxisInverted(bool bIsInverted) {
}

void AIndianaPlayerController::SetMouseSensitivity(const float Value) {
}

void AIndianaPlayerController::SetMouseADSSensitivity(const float Value) {
}

void AIndianaPlayerController::SetInputPreferenceADS(int32 InputPreference) {
}

void AIndianaPlayerController::SetGlobalVariable(const FString& GlobalVariable, int32 Value) {
}

void AIndianaPlayerController::SetControllerYAxisInverted(bool bIsInverted) {
}

void AIndianaPlayerController::SetControllerXAxisInverted(bool bIsInverted) {
}

void AIndianaPlayerController::SetAutoSprintEnabled(bool bIsEnabled) {
}

void AIndianaPlayerController::PlayChatterOnTarget(EChatterEventType ChatterEvent) {
}

void AIndianaPlayerController::PinGlobalVariable(const FString& GlobalVariable) {
}

void AIndianaPlayerController::OpenQuestLog() {
}

void AIndianaPlayerController::OpenMap() {
}

void AIndianaPlayerController::OpenLedger() {
}

void AIndianaPlayerController::OpenInventory() {
}

void AIndianaPlayerController::OpenCompanions() {
}

void AIndianaPlayerController::OpenCharacterSummary() {
}

void AIndianaPlayerController::OnRestoredStateOfBeing(EStateOfBeing RestoredStateOfBeing) {
}

void AIndianaPlayerController::OnKeyBindsReset() {
}

void AIndianaPlayerController::OnAxisMappingRemoved(FInputAxisKeyMapping Value) {
}

void AIndianaPlayerController::OnAxisMappingAdded(FInputAxisKeyMapping Value) {
}

void AIndianaPlayerController::OnActionMappingRemoved(FInputActionKeyMapping Value) {
}

void AIndianaPlayerController::OnActionMappingAdded(FInputActionKeyMapping Value) {
}

bool AIndianaPlayerController::IsYAxisInverted() const {
    return false;
}

bool AIndianaPlayerController::IsXAxisInverted() const {
    return false;
}

float AIndianaPlayerController::GetMouseSensitivity() const {
    return 0.0f;
}

float AIndianaPlayerController::GetMouseADSSensitivity() const {
    return 0.0f;
}

float AIndianaPlayerController::GetInteractHoldTime() const {
    return 0.0f;
}

AIndianaPlayerController* AIndianaPlayerController::GetIndianaPlayerController() {
    return NULL;
}

void AIndianaPlayerController::DebugTogglePause() {
}

void AIndianaPlayerController::DebugStartTechArtWidget2() {
}

void AIndianaPlayerController::DebugStartTechArtWidget1() {
}

void AIndianaPlayerController::DebugSpawnCompanionForced(FName CompanionName) {
}

void AIndianaPlayerController::DebugSpawnCompanion(FName CompanionName) {
}

AIndianaAiCharacter* AIndianaPlayerController::DebugSpawnAICharacter(FName AICharacterAssetName) {
    return NULL;
}

void AIndianaPlayerController::DebugRevertDutchAngle(float Axis) {
}

void AIndianaPlayerController::DebugFrameStep() {
}

void AIndianaPlayerController::DebugEndTechArtWidget2() {
}

void AIndianaPlayerController::DebugEndTechArtWidget1() {
}

void AIndianaPlayerController::DebugDutchAngleAdjustment(float Axis) {
}

void AIndianaPlayerController::DebugDespawnCompanions() {
}

void AIndianaPlayerController::CloseLedger() {
}

void AIndianaPlayerController::AddStickYawInput(float Val) {
}

void AIndianaPlayerController::AddStickRollInput(float Val) {
}

void AIndianaPlayerController::AddStickPitchInput(float Val) {
}


