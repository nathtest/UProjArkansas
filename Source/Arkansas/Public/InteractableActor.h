#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GameplayTagContainer.h>
#include "AnimationProxyResponderInterface.h"

#include <PropAnimationPlayer.h>
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "OnAnimNotifyEventDelegate.h"
#include "OnAnimProxySkippedDelegate.h"
#include "OnEnterRpgExaminablePageDelegate.h"
#include "OnExitRpgExaminablePageDelegate.h"
#include "OnFpvAnimProxyCompleteDelegate.h"
#include "OnFpvAnimProxyStartedDelegate.h"
#include "OnInteractDelegate.h"
#include "OnInteractStateChangedDelegate.h"
#include "OnInteractStateInteractDelegate.h"
#include "OnPageChoiceSelectDelegate.h"
#include "InteractableActor.generated.h"

class AIndianaCharacter;
class AIndianaPlayerCharacter;
class AStaticMeshActor;
class UAnimationProxyComponent;
class UInteractableAudioComponent;
class UInteractableComponent;
class UObsidianIDComponent;
class URPGExaminableData;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class AInteractableActor : public AActor, public IAnimationProxyResponderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteract OnInteract;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStateChanged OnInteractStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStateInteract OnInteractStateInteract;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFpvAnimProxyStarted OnFpvAnimProxyPreStart;
    
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
    FOnAnimNotifyEvent OnAnimNotifyEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAnimProxySkipped AnimProxySkipped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPropAnimationPlayer PropAnimationPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* Interactable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProxyComponent* AnimProxyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* ObsidianIDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseInteractHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AStaticMeshActor*> AdditionalStaticMeshVideoActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTurnOffVideoMaterialOnVideoEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTurnOnStaticVideoMaterialOnVideoEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableAudioComponent* InteractableAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* PreviewSkeletalMesh;
    
public:
    AInteractableActor(const FObjectInitializer& ObjectInitializer);

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
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractBP();
    
    UFUNCTION(BlueprintCallable)
    void OnFpvAnimProxyCompleteDelegateFired();
    
    UFUNCTION(BlueprintCallable)
    void OnBinkMediaOpened(const FString& OpenedUrl);
    
    UFUNCTION(BlueprintCallable)
    void OnBinkMediaClosed();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnAnimProxySkipped(AIndianaPlayerCharacter* PlayerCharacter, const FGameplayTag& SkippedAnimProxyKey);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInConversation() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasPotentialConversationPresentationModeStarted();
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description) const;
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInteractableComponent* GetInteractableComponent() const;
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetGameplayTag() const;
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    

    // Fix for true pure virtual functions not being implemented
};

