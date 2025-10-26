#include "AIDetectionComponent.h"
#include "Perception\AIPerceptionTypes.h"

UAIDetectionComponent::UAIDetectionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ComponentTags.AddDefaulted(1);
    this->bAutoActivate = true;
}

void UAIDetectionComponent::OnPlayerKill(AActor* Killer, AActor* Victim, const FCauseDamageInfo& CauseDamageInfo) {
}

void UAIDetectionComponent::OnPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus) {
}

void UAIDetectionComponent::OnDamageEvent(const FCauseDamageInfo& CauseDamageInfo) {
}

void UAIDetectionComponent::OnConversationInterruptCompleted(AIndianaAiCharacter* InCharacter) {
}

void UAIDetectionComponent::OnCombatStateChange(AIndianaCharacter* InCharacter, bool bInCombat, bool bRestoring) {
}

float UAIDetectionComponent::GetPlayerTimeSinceThreatened() const {
    return 0.0f;
}

float UAIDetectionComponent::GetPlayerTimeSinceBecameAware() const {
    return 0.0f;
}

float UAIDetectionComponent::GetPlayerAwarenessTimeRemainingEstimate() const {
    return 0.0f;
}

float UAIDetectionComponent::GetPlayerAwarenessMeter() const {
    return 0.0f;
}

EAlertState UAIDetectionComponent::GetPlayerAlertState() const {
    return EAlertState::Unaware;
}

float UAIDetectionComponent::GetAwarenessTimeRemainingEstimate() const {
    return 0.0f;
}

float UAIDetectionComponent::GetAwarenessMeter() const {
    return 0.0f;
}

EAlertState UAIDetectionComponent::GetAlertState() const {
    return EAlertState::Unaware;
}

void UAIDetectionComponent::ForceHostilePlayerRelationship() {
}

void UAIDetectionComponent::ForceFullDetection(AActor* DetectedActor, const FVector ExternalStimulusLocation, const bool bPermitArkansasAI) {
}


