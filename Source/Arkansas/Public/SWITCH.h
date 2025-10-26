#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "AnimationProxyResponderInterface.h"
#include <PropAnimationPlayer.h>
#include "CycleBehavior.h"
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "MapFloorTrackedActor.h"
#include "SwitchLeverInteractionCompleteDelegate.h"
#include "SwitchStateChangedDelegate.h"
#include "SWITCH.generated.h"

class AIndianaCharacter;
class UAkComponent;
class UAnimationProxyData;
class UInteractableComponent;
class UObsidianIDComponent;
class USceneComponent;
class UTravelTriggerComponent;

UCLASS(Blueprintable)
class ASWITCH : public AActor, public IMapFloorTrackedActor, public IAnimationProxyResponderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSwitchStateChanged OnSwitchStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTravelTriggerComponent* TravelTriggerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    CycleBehavior CyclingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialState;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSwitchLeverInteractionComplete OnSwitchLeverInteractionComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPropAnimationPlayer PropAnimationPlayer;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationProxyData* AnimationProxyData;
    
    ASWITCH(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SignalSwitchLeverInteractionComplete();
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentState(int32 NewState, AActor* Initiator);
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    UInteractableComponent* GetInteractableComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentState() const;
    
    UFUNCTION(BlueprintCallable)
    void CycleNextState(AActor* Initiator);
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

    // Fix for true pure virtual functions not being implemented
};

