#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "EZyraniumType.h"
#include "HazardDisabledDelegate.h"
#include "HazardEnabledDelegate.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "OwActorPoolInterface.h"
#include "Templates/SubclassOf.h"
#include "TrapGroupInterface.h"
#include "WireInterface.h"
#include "Hazard.generated.h"

class AIndianaCharacter;
class UAkRtpc;
class UEventEffect;
class UEventEffectState;
class UObsidianIDComponent;
class UOwActorPool;
class UOwNavModifierComponent;
class UPrimitiveComponent;
class URpgStat;
class USceneComponent;
class USpellConditional;
class UStaticMeshComponent;
class UStatusEffect;
class UTeamData;

UCLASS(Blueprintable)
class ARKANSAS_API AHazard : public AActor, public IWireInterface, public ITrapGroupInterface, public IOwActorPoolInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHazardEnabled OnHazardEnabling;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHazardEnabled OnHazardEnabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHazardEnabled OnHazardDisabling;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHazardDisabled OnHazardDisabled;


    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bAllowChildActorsToSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldBeAvoided;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    TArray<USpellConditional*> TargetConditionals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> HazardEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEventEffect* StartEventEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEventEffect* StopEventEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEventEffectState* EventEffectState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTeamData> HazardTeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateHazardOnFriendly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreventedByShieldGadget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnableRampUpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisableRampDownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* RampRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RTPCName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EffectExpirationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* EffectExpirationDurationModifyingStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoDisableTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoDisableKillTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* CollisionStaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckLoS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EZyraniumType ZyraniumType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> ActorsToRetryApplication;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> IntigatorOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwNavModifierComponent* NavModifierComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeferredSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPooled;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwActorPool* OwningPool;
    
public:
    AHazard(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void SetInstigator(AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void SetHazardEnabled(bool bInEnabled);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawnedFromPoolBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReaquiredFromPoolBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFreedToPoolBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeferredSpawnCompleteBP();
    
    UFUNCTION(BlueprintCallable)
    void OnAutoDisableKillTimeElapsed();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActorExited(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnActorEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPointInsideHazard(const FVector& Point, const float Extent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHazardEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPower() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShouldBeAvoided() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInActorPool();
    
protected:
    UFUNCTION(BlueprintCallable)
    void FreeToPoolBP();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UFUNCTION(BlueprintCallable)
    void AttemptEnableHazard(bool bEnable);
    

    // Fix for true pure virtual functions not being implemented
};

