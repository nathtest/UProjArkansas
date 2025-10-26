#include "OwFPVPresentationMode.h"

UOwFPVPresentationMode::UOwFPVPresentationMode() {
    this->bFadeInOut = false;
    this->FadeToBlackTime = 0.00f;
    this->FadeHoldTime = 0.10f;
    this->FadeFromBlackTime = 0.20f;
    this->bAlwaysUseDoubleSpeakerFraming = false;
    this->bEnableZoom = true;
    this->ZoomReferenceMode = EPresentationModeZoomReferenceMode::ConversationOwner;
    this->MinimumDistanceToZoom = 350.00f;
    this->bOverrideDesiredZoomFOV = false;
    this->DesiredZoomFOV = 30.00f;
    this->SimulatedDistanceToSpeakerWhenZooming = 172.00f;
    this->bCinematicShotEnabledByDefault = true;
    this->ConversationFadeInstance = NULL;
}

void UOwFPVPresentationMode::SetPresentationModeBaseCameraShakeEnabled(const AIndianaPlayerCharacter* Player, bool bEnabled, float BlendTime) {
}

void UOwFPVPresentationMode::SetFPVPresentationModeCinematicShotEnabled(const AIndianaPlayerCharacter* Player, bool bEnabled, float BlendTime) {
}

void UOwFPVPresentationMode::OnViewTargetChanged(APlayerController* PlayerController, AActor* OldViewTarget, AActor* NewViewTarget) {
}

void UOwFPVPresentationMode::OnSpeakerTeleportedToStageMark(AIndianaCharacter* SpeakerCharacter, AStageMarkActor* StageMark) {
}

void UOwFPVPresentationMode::OnFadeInstanceStateChanged(UPresentationModeCameraFadeInstance* FadeInstance, EPresentationModeCameraFadeState NewState) {
}

void UOwFPVPresentationMode::OnConversationCameraSwayUserSettingChanged(bool bCameraSwayEnabled) {
}


