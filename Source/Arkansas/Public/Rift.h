#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include <GameplayTagContainer.h>
#include <GlobalVariableReference.h>
#include "DamageDescription.h"
#include "InteractableActor.h"
#include "OnPauseRiftCountdownDelegate.h"
#include "OnPlayBurstEventDelegate.h"
#include "OnReverseBurstEventDelegate.h"
#include "OnUnpauseRiftCountdownDelegate.h"
#include "RiftActorDesc.h"
#include "Rift.generated.h"

class AActor;
class AIndianaPlayerCharacter;
class ARift;
class UAkAudioEvent;
class UAkRtpc;
class UAkStateValue;
class UBoxComponent;
class UCameraShakeSourceComponent;
class UCurveFloat;
class UDataLayerAsset;
class UDataLayerInstance;
class UDataLayerManager;
class UMaterialInterface;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class UNiagaraComponent;
class UOEIWwiseAmbientEmitterComponent;
class UOwAnimationProxyComponent;
class UOwConversationInstance;
class UOwNavModifierComponent;
class UPostProcessComponent;
class UPrimitiveComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ARKANSAS_API ARift : public AInteractableActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataLayerAsset* DataLayerAsset;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<AActor>> RiftActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRiftActorDesc> RiftActorDescs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RiftDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RiftIndex;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ImpassableNavMetaAreaActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* RiftMaterialStatic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* RiftMaterialSkeletal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageDescription RiftDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* WwiseRiftCoreOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* WwiseRiftCoreClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* WwiseRiftOpenPlayerStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* WwiseRiftOpenPlayerStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* WwiseRiftCoreProximityRadiusIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* WwiseRiftCoreProximityRadiusOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* WwiseRiftCoreConditionStateOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* WwiseRiftCoreConditionStateClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* WwiseRiftCoreConditionRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* WwiseMomentsRiftAnimRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RiftAmbientFXTickRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RiftAmbientFXExponentialCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RiftAmbientFXIntensityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RiftAmbientFXPlayerDistanceModifierCurve;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayBurstEvent OnPlayBurstEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReverseBurstEvent OnReverseBurstEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReverseBurstEvent OnRestoreRiftCountdown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPauseRiftCountdown OnPauseRiftCountdown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUnpauseRiftCountdown OnUnpauseRiftCountdown;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRiftOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRiftedRift;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurstActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurstForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RiftOpenTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRiftCountdownActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RiftCountdownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsScalarActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScalarTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScalarTimelineDirectionForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AIndianaPlayerCharacter* PlayerCharacter;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStaticMeshComponent>> InstancedComponents;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARift*> RiftedRifts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle RiftTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle NavTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle RiftAmbientFXTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* InteractionSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* KillSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraCore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraCoreCalm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference CalmGlobalVar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CalmGlobalVarValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraBurst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* PostProcessBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* PostProcessComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOEIWwiseAmbientEmitterComponent* AmbientEmitterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwAnimationProxyComponent* AnimationProxyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraShakeSourceComponent* CameraShakeSourceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwNavModifierComponent* ClosedNavModifierComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataLayerAsset* CachedDataLayerAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataLayerManager* DataLayerManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataLayerInstance* DataLayerInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollectionInstance* MaterialParameterCollectionInstance;
    
public:
    ARift(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateRiftPositionParam();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnpauseRiftCountdown();
    
protected:
    UFUNCTION(BlueprintCallable)
    void UnpauseRift(UOwConversationInstance* Instance);
    
public:
    UFUNCTION(BlueprintCallable)
    void UnloadActors();
    
    UFUNCTION(BlueprintCallable)
    void ShowRifts();
    
    UFUNCTION(BlueprintCallable)
    void SetRiftTransitionParam(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetRiftCountDownParam(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetIsRiftedRift(bool bIsRifted);
    
    UFUNCTION(BlueprintCallable)
    void SetBaseMeshVisibility(bool bIsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReverseBurstEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RestoreRiftCountdown();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayBurstEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PauseRiftCountdown();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PauseRift(UOwConversationInstance* Instance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetCalm(bool bInCalm);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRiftTimerHandleEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnRiftAmbientFXTimerHandleEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnPostProcessEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPostProcessBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnNavTimerHandleEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnKillSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGlobalVariableChanged(const FGuid& GlobalVariable, int32 Value);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAnimNotifyEventTriggered(FGameplayTag Event);
    
    UFUNCTION(BlueprintCallable)
    void HideRifts();
    
    UFUNCTION(BlueprintCallable)
    void CloseRift();
    
    UFUNCTION(BlueprintCallable)
    void BP_SetRiftCalm(bool bInCalm);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnRiftAmbientFXUpdateTick();
    
    UFUNCTION(BlueprintCallable)
    void ActivateActors();
    
};

