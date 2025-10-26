#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "EOCLDifficulty.h"
#include "ESkill.h"
#include "ESkillDifficultyTier.h"
#include "ETrapTriggerState.h"
#include "InteractionDescription.h"
#include "Templates/SubclassOf.h"
#include "TrapGroupInterface.h"
#include "TrapTriggerDelegateDelegate.h"
#include "TrapTriggerDelegateWithInitiatorDelegate.h"
#include "TrapTriggerPreDeployDelegate.h"
#include "TrapTriggerRearmingDelegate.h"
#include "TrapTriggerStateChangedDelegate.h"
#include "WireInterface.h"
#include "TrapTrigger.generated.h"

class AIndianaCharacter;
class UCapsuleComponent;
class UFactionData;
class UInteractLookAtTriggerComponent;
class UInteractableComponent;
class UObsidianIDComponent;
class UOwNavModifierComponent;
class UPrimitiveComponent;
class USceneComponent;
class UShapeComponent;
class UTeamData;

UCLASS(Blueprintable)
class ATrapTrigger : public AActor, public IWireInterface, public ITrapGroupInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrapTriggerState InitialState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerStateChanged OnTrapTriggerStateChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegate OnTrapTriggerArmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegate OnTrapTriggerDisarmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegateWithInitiator OnTrapTriggerTripped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegate OnTrapTriggerUntripped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerPreDeploy OnTrapTriggerPreDeploy;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegate OnTrapTriggerDeployed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerRearming OnTrapTriggerRearming;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegate OnTrapTriggerRearmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegateWithInitiator OnTrapTriggerEntered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrapTriggerDelegateWithInitiator OnTrapTriggerExited;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreDeploymentSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeploymentDelaySeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeploymentsPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RearmDelaySeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTeamData> TeamClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* ActivationShapeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* ActivatorTrackingShapeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractLookAtTriggerComponent* InteractLookAtTriggerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill DisarmSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOCLDifficulty DisarmDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceDisarmTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyTier ForcedDisarmTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreLightStep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFactionData> OwningFaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwNavModifierComponent* NavModifierComponent;
    
public:
    ATrapTrigger(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartInteract(const FInteractionDescription& InteractionDescription);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bAllowChildActorsToSaveGameState;
    
protected:
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
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRearming() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDeploymentPending() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETrapTriggerState GetInitialState() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETrapTriggerState GetCurrentState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaCharacter* GetActivatingCharacter();
    
    UFUNCTION(BlueprintCallable)
    void DisarmTrapTrigger(bool bAlertEffectSources);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ChangeState(ETrapTriggerState State);
    
public:
    UFUNCTION(BlueprintCallable)
    void ArmTrapTrigger();
    

    // Fix for true pure virtual functions not being implemented
};

