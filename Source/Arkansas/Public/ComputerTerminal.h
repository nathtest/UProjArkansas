#pragma once
#include "CoreMinimal.h"
#include <SpeakerReference.h>
#include <VoiceOverComponentSetupData.h>
#include "ComputerHackInterruptedDelegate.h"
#include "ComputerHackLoopStopDelegate.h"
#include "ComputerHackStartDelegate.h"
#include "ComputerHackStateChangedDelegate.h"
#include "ComputerHackSuccessDelegate.h"
#include "ComputerInsufficientSkillDelegate.h"
#include "ComputerLockedDelegate.h"
#include "ComputerTerminalConversationEndDelegate.h"
#include "ComputerTerminalConversationInstanceEndDelegate.h"
#include "ComputerUnlockAttemptedLockedDelegate.h"
#include "ComputerUnlockedDelegate.h"
#include "ComputerUseDelegate.h"
#include "EComputerHackState.h"
#include "EComputerType.h"
#include "EInteractionType.h"
#include "EOCLDifficulty.h"
#include "ESkillDifficultyTier.h"
#include "InteractableActor.h"
#include "InteractionDescription.h"
#include "MapFloorTrackedActor.h"
#include "OwSpeaker.h"
#include "RPGInteractableRequirements.h"
#include "RenderTargetDisplayInterface.h"
#include "Templates/SubclassOf.h"
#include "ComputerTerminal.generated.h"

class ASceneCapture2D;
class UAkComponent;
class UAnimationProxyData;
class UComputerTerminalWidgetComponent;
class UItem;
class UMaterialInterface;
class UOwConversationInstance;
class UOwSpeakerInfoComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AComputerTerminal : public AInteractableActor, public IMapFloorTrackedActor, public IOwSpeaker, public IRenderTargetDisplayInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipAutomaticConversation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerUse OnComputerUse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerUnlockAttemptedLocked OnComputerUnlockAttemptedLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerInsufficientSkill OnComputerInsufficientSkill;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerUnlocked OnComputerUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerLocked OnComputerLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerHackStart OnComputerHackStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerHackSuccess OnComputerHackSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerHackInterrupted OnComputerHackInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerHackLoopStop OnComputerHackLoopStop;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerTerminalConversationEnd OnComputerConversationEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerTerminalConversationInstanceEnd OnComputerConversationInstanceEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimationProxyData> HackAnimationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreForCrime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPlayerDistance;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UComputerTerminalWidgetComponent* MainScreenWidgetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwSpeakerInfoComponent* SpeakerInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LockScreenStaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UComputerTerminalWidgetComponent* ComputerTerminalWidgetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASceneCapture2D> Camera;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData VoiceOverSetupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* VoiceOverAudioComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOCLDifficulty HackDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceHackTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyTier ForcedHackTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItem> AutoHackItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveAutoHackItemAfterUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItem> HackResourceItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerHackStateChanged OnComputerHackStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EComputerType, TSoftObjectPtr<UMaterialInterface>> LockScreenTextures;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MainScreenWidgetComponentTag;
    
public:
    AComputerTerminal(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateInteractHold(float ElapsedTime);
    
    UFUNCTION(BlueprintCallable)
    void UnlockComputer(bool bFireComputerUnlockedEvent);
    
    UFUNCTION(BlueprintCallable)
    void StartInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    void SetRenderShown(bool bNewRenderShown, FSpeakerReference Speaker);
    
    UFUNCTION(BlueprintCallable)
    bool PassesRPGRequirements(uint8 InteractionIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFPVAnimationComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    void LockComputer(bool bFireComputerLockedEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
    UFUNCTION(BlueprintCallable)
    FRPGInteractableRequirements GetRPGRequirements(EInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable)
    void ConversationInstanceStart(UOwConversationInstance* OwConversationInstance);
    
    UFUNCTION(BlueprintCallable)
    void ConversationInstanceEnd(UOwConversationInstance* OwConversationInstance);
    
    UFUNCTION(BlueprintCallable)
    void ChangeState(EComputerHackState State);
    
    UFUNCTION(BlueprintCallable)
    void CancelInteract(const FInteractionDescription& InteractionDescription);
    

    // Fix for true pure virtual functions not being implemented
};

