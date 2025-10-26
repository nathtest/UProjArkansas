#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GlobalVariableReference.h>
#include "AIGroupBehaviorInstanceKit.h"
#include "CauseDamageInfo.h"
#include "EAlertState.h"
#include "EEncounterActivationType.h"
#include "EEncounterVolume.h"
#include "EncounterActivatedDelegate.h"
#include "EncounterActivationConditions.h"
#include "EncounterActorCombatChangedDelegate.h"
#include "EncounterActorDamagedDelegate.h"
#include "EncounterActorKilledDelegate.h"
#include "EncounterActorSpawnedDelegate.h"
#include "EncounterAlertStateChangedDelegate.h"
#include "EncounterClearConditions.h"
#include "EncounterCompleteDelegate.h"
#include "EncounterDeactivatedDelegate.h"
#include "EncounterSettings.h"
#include "EncounterWaveActivatedDelegate.h"
#include "EncounterWaveCompleteDelegate.h"
#include "EncounterWaveInformation.h"
#include "EncounterWaveTimerActivatedDelegate.h"
#include "SpawnNodeActorGenericFunctionCallDelegate.h"
#include "Encounter.generated.h"

class ACharacterSpawner;
class AEncounterManager;
class AEncounterVolume;
class AIndianaAiCharacter;
class AIndianaCharacter;
class AVolume;
class UAIGroupBehaviorInstanceKitComponent;
class UAkAudioEvent;
class UHealthComponent;
class UObject;
class UObsidianIDComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AEncounter : public AActor, public IAIGroupBehaviorInstanceKit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterComplete OnEncounterComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterActivated OnEncounterActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterDeactivated OnEncounterDeactivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterActorSpawned OnEncounterActorSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterActorDamaged OnEncounterActorDamaged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterActorKilled OnEncounterActorKilled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterActorCombatChanged OnEncounterActorCombatChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterWaveComplete OnEncounterWaveComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterWaveActivated OnEncounterWaveActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterWaveTimerActivated OnEncounterWaveTimerActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterAlertStateChanged OnEncounterAlertStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* StartAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioEmitterId;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEncounterWaveInformation> EncounterWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEncounterManager* EncounterManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterSettings EncounterSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference ActorKilledGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterClearConditions ClearConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference CompletionGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CompletionGlobalVariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEncounterActivationConditions EnabledConditions;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EEncounterActivationType ActivationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBoxActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisengageTriggerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEncounterVolume* DisengageTriggerVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReEngageTriggerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEncounterVolume* ReEngageTriggerVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntendedSpaceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEncounterVolume* IntendedSpaceVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FallbackSpaceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEncounterVolume* FallbackSpaceVolume;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FallbackLogicEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FallbackFlag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AVolume*> ActivationActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeactivationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* ObsidianID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepAlertStateActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNonPlayerPseudoGod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NonPlayerPseudoGodMinHealthPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AVolume* NonPlayerPseudoGodDisableVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIGroupBehaviorInstanceKitComponent* AIGroupBehaviorInstanceKitComponent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxUnstasisedCharactersPerTick;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugTrap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDynamicTetherGlobalAISettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableDynamicTetherOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DynamicTetherMaximumRangeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DynamicTetherToleranceMultiplierOverride;
    
public:
    AEncounter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopAudio();
    
    UFUNCTION(BlueprintCallable)
    void StartAudio();
    
    UFUNCTION(BlueprintCallable)
    void ResetActivationFailed();
    
    UFUNCTION(BlueprintCallable)
    void RefreshEncounter();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNonPlayerPseudoGodVolumeBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnLinkedNPCKilled(AActor* InstigatingActor, const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnLinkedNPCHealthChanged(UHealthComponent* HealthComponent, float NormalizedOldHealth, float NormalizedNewHealth, AActor* InstigatingActor);
    
    UFUNCTION(BlueprintCallable)
    void OnLinkedNPCCombatStateChanged(AIndianaCharacter* Character, bool bIsInCombat, bool bRestoring);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEditorSelectionChanged(TArray<UObject*> SelectedObjects);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorUnstasis(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorHealthChanged(UHealthComponent* HealthComponent, float NormalizedOldHealth, float NormalizedNewHealth, AActor* InstigatingActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDoneSpawning(AActor* Actor, ACharacterSpawner* CharacterSpawner);
    
    UFUNCTION(BlueprintCallable)
    void OnActivationEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnActivationBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void IterateThroughSpawnedActors(const FSpawnNodeActorGenericFunctionCall& GenericFunctionCall);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInVolumeShrink(EEncounterVolume VolumeEnum, FVector Pos, float ShrinkRadius) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInVolume(EEncounterVolume VolumeEnum, FVector Pos) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInsideIntendedSpace(FVector Pos) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInsideFallbackSpace(FVector Pos) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInsideEncounterSpace(FVector Pos) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEncounterActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEncounterCompleted() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumActiveCharacters() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxWaveSpawns(int32 WaveIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxAlertStateAwareness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAlertState GetMaxAlertState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetFallbackNavLocation(AIndianaCharacter* Pather, const FVector QueryExtent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetFallbackLocation() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FEncounterWaveInformation> GetEncounterWaves();
    
    UFUNCTION(BlueprintCallable)
    TArray<AIndianaAiCharacter*> GetEncounterWaveCharacters(int32 WaveIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAlertState GetEncounterPlayerAlertState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetEncounterDebugCondition();
    
    UFUNCTION(BlueprintCallable)
    TArray<AIndianaAiCharacter*> GetEncounterCharacters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AIndianaAiCharacter*> GetActiveAICharacters() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceDeactivateEncounter();
    
protected:
    UFUNCTION(BlueprintCallable)
    void DeactivateWave(int32 WaveIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateEncounter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckEncounterWaveTime(int32 WaveIndex, float Seconds);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ActivateWave(int32 WaveIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void ActivateEncounter();
    

    // Fix for true pure virtual functions not being implemented
};

