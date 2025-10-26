#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "LauncherEmitterDelegateDelegate.h"
#include "TrapEffectSource.h"
#include "TrapGroupInterface.h"
#include "LauncherEmitter.generated.h"

class UEquipmentComponent;
class UInteractLookAtTriggerComponent;
class UInteractableComponent;
class UInventoryComponent;
class ULauncherEmitterComponent;
class UObsidianIDComponent;

UCLASS(Blueprintable)
class ARKANSAS_API ALauncherEmitter : public AActor, public ITrapEffectSource, public ITrapGroupInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLauncherEmitterDelegate OnEmitterDisarmed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLauncherEmitterDelegate OnEmitterFire;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEquipmentComponent* EquipmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractLookAtTriggerComponent* InteractLookAtTriggerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULauncherEmitterComponent* LauncherEmitterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* ObsidianIDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FiringAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialProjectileVelocity;
    
public:
    ALauncherEmitter(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void StopFiring();
    
    UFUNCTION(BlueprintCallable)
    void SetProjectileVelocity(float Velocity);
    
    UFUNCTION(BlueprintCallable)
    void OnObservationRevealed();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDisarmed() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool Fire();
    
    UFUNCTION(BlueprintCallable)
    void EndPrimaryTrigger();
    
public:
    UFUNCTION(BlueprintCallable)
    void Disarm();
    
protected:
    UFUNCTION(BlueprintCallable)
    void BeginPrimaryTrigger();
    

    // Fix for true pure virtual functions not being implemented
};

