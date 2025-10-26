#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "AnimationProxyResponderInterface.h"
#include <PropAnimationPlayer.h>
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "OnEnterRpgExaminablePageDelegate.h"
#include "OnExitRpgExaminablePageDelegate.h"
#include "OnFpvAnimProxyCompleteDelegate.h"
#include "OnFpvAnimProxyStartedDelegate.h"
#include "OnInteractCancelledDelegate.h"
#include "OnInteractCompletedDelegate.h"
#include "OnInteractDelegate.h"
#include "OnInteractStartedDelegate.h"
#include "OnInteractStateChangedDelegate.h"
#include "OnInteractStateInteractDelegate.h"
#include "OnPageChoiceSelectDelegate.h"
#include "InteractableTriggerVolume.generated.h"

class AIndianaCharacter;
class UAnimationProxyComponent;
class UInteractableComponent;
class UObsidianIDComponent;
class URPGExaminableData;
class USceneComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AInteractableTriggerVolume : public ATriggerVolume, public IAnimationProxyResponderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteract OnInteract;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStateChanged OnInteractStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStateInteract OnInteractStateInteract;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFpvAnimProxyStarted OnFpvAnimProxyStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFpvAnimProxyComplete OnFpvAnimProxyComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPageChoiceSelect OnPageChoiceSelect;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEnterRpgExaminablePage OnPageEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnExitRpgExaminablePage OnPageExit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStarted OnInteractStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractCompleted OnInteractCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractCancelled OnInteractCancelled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProxyComponent* AnimationProxyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPropAnimationPlayer PropAnimationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TargetPointComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireFacingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FacingAngle;
    
public:
    AInteractableTriggerVolume(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractTarget(bool bIsTarget, UInteractableComponent* Interactable);
    
    UFUNCTION(BlueprintCallable)
    void OnPageExitDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex, bool bWasUIClosed);
    
    UFUNCTION(BlueprintCallable)
    void OnPageEnterDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPageChoiceSelectDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex, int32 PageChoiceIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnInteractStateInteractDelegateFired(int32 StateIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnInteractStateChangedDelegateFired(int32 NewState, int32 OldState);
    
    UFUNCTION(BlueprintCallable)
    void OnFpvAnimProxyCompleteDelegateFired();
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UFUNCTION(BlueprintCallable)
    void CancelInteract(const FInteractionDescription& InteractionDescription);
    

    // Fix for true pure virtual functions not being implemented
};

