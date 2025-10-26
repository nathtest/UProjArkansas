#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "DamageDescription.h"
#include "DamageLevelScaler.h"
#include "DamageTierScaler.h"
#include "EInteractionType.h"
#include "ETrapDifficulty.h"
#include "ETrapState.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "Templates/SubclassOf.h"
#include "TrapActivatedDelegate.h"
#include "TrapActivationCancelledDelegate.h"
#include "TrapArmAttemptedFailedDelegate.h"
#include "TrapArmInterruptedDelegate.h"
#include "TrapArmStartDelegate.h"
#include "TrapArmedDelegate.h"
#include "TrapAttackedDelegate.h"
#include "TrapChangedDelegate.h"
#include "TrapDeactivatedDelegate.h"
#include "TrapDetonatedDelegate.h"
#include "TrapDisarmAttemptedFailedDelegate.h"
#include "TrapDisarmInterruptedDelegate.h"
#include "TrapDisarmStartDelegate.h"
#include "TrapDisarmedDelegate.h"
#include "TrapPreDetonateDelegate.h"
#include "TrapRearmedDelegate.h"
#include "TrapRearmingDelegate.h"
#include "Trap.generated.h"

class AIndianaCharacter;
class UAkComponent;
class UCapsuleComponent;
class UImpactDataSet;
class UInteractLookAtTriggerComponent;
class UInteractableComponent;
class UNiagaraSystem;
class UObsidianIDComponent;
class UPrimitiveComponent;
class URpgStat;
class URpgStatComponent;
class USceneComponent;
class UShapeComponent;
class UStatusEffect;

UCLASS(Blueprintable)
class ATrap : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapChanged OnTrapStateChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapArmed OnTrapArmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapDisarmed OnTrapDisarmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapDeactivated OnTrapDeactivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapArmAttemptedFailed OnTrapArmAttemptedFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapDisarmAttemptedFailed OnTrapDisarmAttemptedFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapArmStart OnTrapArmStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapDisarmStart OnTrapDisarmStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapArmInterrupted OnTrapArmInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapDisarmInterrupted OnTrapDisarmInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapActivated OnTrapActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapActivationCancelled OnTrapActivationCancelled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapPreDetonate OnTrapPreDetonate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapDetonated OnTrapDetonated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapAttacked OnTrapAttacked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapRearming OnTrapRearming;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapRearmed OnTrapRearmed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrapState InitialState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanArm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanDisarm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrapDifficulty TrapDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreDetonationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DetonationDelaySeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DetonationsPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RearmDelaySeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffectType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageDescription DamageDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageLevelScaler DamageLevelScaler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageTierScaler DamageTierScaler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UImpactDataSet* ImpactDataSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraFxShotOrigin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraFxShotEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraFxBeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttackFxBeamEndParam;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractLookAtTriggerComponent* InteractLookAtTriggerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* ActivationShapeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* ActivatorTrackingShapeComponent;
    
public:
    ATrap(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateInteractHold(float ElapsedTime);
    
    UFUNCTION(BlueprintCallable)
    void StartInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractTarget(bool bIsTarget, UInteractableComponent* Interactable);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable)
    void OnObservationRevealed();
    
    UFUNCTION(BlueprintCallable)
    void OnActivatorTrackingShapeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnActivatorTrackingShapeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnActivationShapeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnActivationShapeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRearming() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDetonationPending() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description) const;
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetExactTrapDifficulty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETrapState GetCurrentState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UShapeComponent* GetActivatorTrackingShapeComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UShapeComponent* GetActivationShapeComponent() const;
    
    UFUNCTION(BlueprintCallable)
    void DisarmTrap(AIndianaCharacter* Initiator, bool bFireTrapDisarmedEvent);
    
    UFUNCTION(BlueprintCallable)
    void DeactivateTrap(AIndianaCharacter* Initiator, bool bFireTrapDeactivatedEvent);
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UFUNCTION(BlueprintCallable)
    void CancelInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void ArmTrap(AIndianaCharacter* Initiator, bool bFireTrapArmedEvent);
    
};

