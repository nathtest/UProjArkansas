#include "Encounter.h"
#include "ObsidianIDComponent.h"
#include "AIGroupBehaviorInstanceKitComponent.h"
#include "EncounterComponent.h"

AEncounter::AEncounter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRelevantForLevelBounds = false;
    this->RootComponent = CreateDefaultSubobject<UEncounterComponent>(TEXT("RootComponent"));
    this->bShouldSaveGameState = true;
    this->StartAudioEvent = NULL;
    this->AudioEmitterId = 0;
    this->EncounterManager = NULL;
    this->CompletionGlobalVariableValue = 1;
    this->ActivationType = EEncounterActivationType::Proximity;
    this->ActivationRadius = 18000.00f;
    this->bBoxActivation = false;
    this->DisengageTriggerRadius = 1850.00f;
    this->DisengageTriggerVolume = NULL;
    this->ReEngageTriggerRadius = 1400.00f;
    this->ReEngageTriggerVolume = NULL;
    this->IntendedSpaceRadius = 1900.00f;
    this->IntendedSpaceVolume = NULL;
    this->FallbackSpaceRadius = 500.00f;
    this->FallbackSpaceVolume = NULL;
    this->FallbackLogicEnable = true;
    this->FallbackFlag = false;
    this->DeactivationTime = 1.00f;
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
    this->bKeepAlertStateActive = false;
    this->bNonPlayerPseudoGod = false;
    this->NonPlayerPseudoGodMinHealthPercentage = 1.00f;
    this->NonPlayerPseudoGodDisableVolume = NULL;
    this->AIGroupBehaviorInstanceKitComponent = CreateDefaultSubobject<UAIGroupBehaviorInstanceKitComponent>(TEXT("AIGroupBehaviorKit"));
    this->MaxUnstasisedCharactersPerTick = 1;
    this->bDebugTrap = false;
    this->bOverrideDynamicTetherGlobalAISettings = false;
    this->bEnableDynamicTetherOverride = false;
    this->DynamicTetherMaximumRangeOverride = 5000.00f;
    this->DynamicTetherToleranceMultiplierOverride = 1.20f;
}

void AEncounter::StopAudio() {
}

void AEncounter::StartAudio() {
}

void AEncounter::ResetActivationFailed() {
}

void AEncounter::RefreshEncounter() {
}

void AEncounter::OnNonPlayerPseudoGodVolumeBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void AEncounter::OnLinkedNPCKilled(AActor* InstigatingActor, const FCauseDamageInfo& CauseDamageInfo) {
}

void AEncounter::OnLinkedNPCHealthChanged(UHealthComponent* HealthComponent, float NormalizedOldHealth, float NormalizedNewHealth, AActor* InstigatingActor) {
}

void AEncounter::OnLinkedNPCCombatStateChanged(AIndianaCharacter* Character, bool bIsInCombat, bool bRestoring) {
}

void AEncounter::OnEditorSelectionChanged(TArray<UObject*> SelectedObjects) {
}

void AEncounter::OnActorUnstasis(AActor* Actor) {
}

void AEncounter::OnActorHealthChanged(UHealthComponent* HealthComponent, float NormalizedOldHealth, float NormalizedNewHealth, AActor* InstigatingActor) {
}

void AEncounter::OnActorDoneSpawning(AActor* Actor, ACharacterSpawner* CharacterSpawner) {
}

void AEncounter::OnActivationEndOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void AEncounter::OnActivationBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void AEncounter::IterateThroughSpawnedActors(const FSpawnNodeActorGenericFunctionCall& GenericFunctionCall) {
}

bool AEncounter::IsInVolumeShrink(EEncounterVolume VolumeEnum, FVector Pos, float ShrinkRadius) const {
    return false;
}

bool AEncounter::IsInVolume(EEncounterVolume VolumeEnum, FVector Pos) const {
    return false;
}

bool AEncounter::IsInsideIntendedSpace(FVector Pos) const {
    return false;
}

bool AEncounter::IsInsideFallbackSpace(FVector Pos) const {
    return false;
}

bool AEncounter::IsInsideEncounterSpace(FVector Pos) const {
    return false;
}

bool AEncounter::IsEncounterActive() const {
    return false;
}

bool AEncounter::HasEncounterCompleted() const {
    return false;
}

int32 AEncounter::GetNumActiveCharacters() const {
    return 0;
}

int32 AEncounter::GetMaxWaveSpawns(int32 WaveIndex) const {
    return 0;
}

float AEncounter::GetMaxAlertStateAwareness() const {
    return 0.0f;
}

EAlertState AEncounter::GetMaxAlertState() const {
    return EAlertState::Unaware;
}

FVector AEncounter::GetFallbackNavLocation(AIndianaCharacter* Pather, const FVector QueryExtent) const {
    return FVector{};
}

FVector AEncounter::GetFallbackLocation() const {
    return FVector{};
}

TArray<FEncounterWaveInformation> AEncounter::GetEncounterWaves() {
    return TArray<FEncounterWaveInformation>();
}

TArray<AIndianaAiCharacter*> AEncounter::GetEncounterWaveCharacters(int32 WaveIndex) {
    return TArray<AIndianaAiCharacter*>();
}

EAlertState AEncounter::GetEncounterPlayerAlertState() {
    return EAlertState::Unaware;
}

bool AEncounter::GetEncounterDebugCondition() {
    return false;
}

TArray<AIndianaAiCharacter*> AEncounter::GetEncounterCharacters() {
    return TArray<AIndianaAiCharacter*>();
}

TArray<AIndianaAiCharacter*> AEncounter::GetActiveAICharacters() const {
    return TArray<AIndianaAiCharacter*>();
}

void AEncounter::ForceDeactivateEncounter() {
}

void AEncounter::DeactivateWave(int32 WaveIndex) {
}

void AEncounter::DeactivateEncounter() {
}

bool AEncounter::CheckEncounterWaveTime(int32 WaveIndex, float Seconds) {
    return false;
}

void AEncounter::ActivateWave(int32 WaveIndex) {
}

void AEncounter::ActivateEncounter() {
}


