#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box -FallbackName=Box
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "EAudioStimulusRadius.h"
#include "EEmissiveState.h"
#include "EInteractionRestrictions.h"
#include "EInteractionType.h"
#include "EOCLResult.h"
#include "EOCLState.h"
#include "EOwnerType.h"
#include "ESkillDifficultyRange.h"
#include "ESkillDifficultyTier.h"
#include "ESoundDetectionType.h"
#include "ETerminalLockState.h"
#include "EmissiveStateParams.h"
#include "InteractActorDescription.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "OCLAnimateCloseDelegate.h"
#include "OCLAnimateInstantCloseDelegate.h"
#include "OCLAnimateInstantOpenDelegate.h"
#include "OCLAnimateOpenDelegate.h"
#include "OCLAnimateUnjamDelegate.h"
#include "OCLBarredDelegate.h"
#include "OCLCloseEndDelegate.h"
#include "OCLCloseInterruptedDelegate.h"
#include "OCLCloseStartDelegate.h"
#include "OCLJammedDelegate.h"
#include "OCLLockedDelegate.h"
#include "OCLLockpickInterruptedDelegate.h"
#include "OCLLockpickLoopStopDelegate.h"
#include "OCLLockpickStartDelegate.h"
#include "OCLLockpickSuccessDelegate.h"
#include "OCLOnPowerChangedDelegate.h"
#include "OCLOpenAttemptedLockedDelegate.h"
#include "OCLOpenEndDelegate.h"
#include "OCLOpenInterruptedDelegate.h"
#include "OCLOpenStartDelegate.h"
#include "OCLSealedDelegate.h"
#include "OCLStateChangedDelegate.h"
#include "OCLUnbarredDelegate.h"
#include "OCLUnjammedDelegate.h"
#include "OCLUnlockedDelegate.h"
#include "OCLUnsealedDelegate.h"
#include "OCLWireConnectedDelegate.h"
#include "OnEnterRpgExaminablePageDelegate.h"
#include "OnExitRpgExaminablePageDelegate.h"
#include "OnFpvAnimProxyCompleteDelegate.h"
#include "OnInteractBeginAnimDelegate.h"
#include "OnInteractEventStartedOrEndedDelegate.h"
#include "OnInteractStateChangedDelegate.h"
#include "OnInteractStateInteractDelegate.h"
#include "OnPageChoiceSelectDelegate.h"
#include "Templates/SubclassOf.h"
#include "InteractableComponent.generated.h"

class AActor;
class AIndianaCharacter;
class UAnimationProxyData;
class UFactionData;
class UInteractionEventBase;
class UItem;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UOwConversationInstance;
class URPGExaminableData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UInteractableComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOCLState InitialStateOCL;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItem> KeyItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveKeyAfterUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyRange InteractDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceInteractTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyTier ForcedInteractTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItem> LockpickItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItem> HackingItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimationProxyData> KeyItemAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoCloseDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoCloseDelayNPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoCloseRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreForCrime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLStateChanged OnOCLStateChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenStart OnOCLOpenStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenEnd OnOCLOpenEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLCloseStart OnOCLCloseStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLCloseEnd OnOCLCloseEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLAnimateOpen OnOCLAnimateOpen;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLAnimateClose OnOCLAnimateClose;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLAnimateUnjam OnOCLAnimateUnjam;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLAnimateInstantOpen OnOCLAnimateInstantOpen;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLAnimateInstantClose OnOCLAnimateInstantClose;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenAttemptedLocked OnOCLOpenAttemptedLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenAttemptedLocked OnOCLOpenAttemptedBarred;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLocked OnOCLLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLUnlocked OnOCLUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLBarred OnOCLBarred;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLUnbarred OnOCLUnbarred;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLSealed OnOCLSealed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLUnsealed OnOCLUnsealed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenInterrupted OnOCLOpenInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLCloseInterrupted OnOCLCloseInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickStart OnOCLLockpickStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickSuccess OnOCLLockpickSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickInterrupted OnOCLLockpickInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickLoopStop OnOCLLockpickLoopStop;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOnPowerChanged OCLOnPowerChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLWireConnected OCLWireConnected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLJammed OnOCLJammed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLUnjammed OnOCLUnjammed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETerminalLockState InitialTerminalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFactionData> OwningFaction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStateChanged OnInteractStateChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractStateInteract OnInteractStateInteractDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFpvAnimProxyComplete OnFpvAnimProxyCompleteDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPageChoiceSelect OnPageChoiceSelectDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEnterRpgExaminablePage OnPageEnterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnExitRpgExaminablePage OnPageExitDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractBeginAnim OnInteractBeginAnimDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractEventStartedOrEnded OnInteractionEventStartedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInteractEventStartedOrEnded OnInteractionEventEndedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FacingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FacingAngleRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConversationInteractRangeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NoInputInteractRangeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoesRequirePlayerInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUseWhileFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString LocString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCrime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockPropagation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInteractionsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitialInteractionEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractActorDescription> InteractTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractionEventBase* InteractionEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockInteractionEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefaultCanHighlightDirect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefaultCanHighlightProximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefaultCanHighlightThrowableProximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoRegisterToOctree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObservationGuideTriggerRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObservationGuideMaxZOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CustomHighlightStencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOwnerType OwnerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EEmissiveState, UMaterialInterface*> EmissiveMaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> EmissiveMaterialSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BarredMaterialSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEmissiveStateParams> EmissiveStateParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasAudioStimulus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAudioStimulusRadius AudioStimulusRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioStimulusRadiusOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESoundDetectionType AudioStimulusSoundType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMaterialInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BarredMaterialInstances;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EOCLState CurrentStateOCL;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ETerminalLockState CurTerminalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TOptional<bool> TemporaryInteractionsEnabledState;
    
public:
    UInteractableComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateInteractHold(float ElapsedTime);
    
    UFUNCTION(BlueprintCallable)
    void UnsealOCL(bool bFireOCLUnsealedEvent);
    
    UFUNCTION(BlueprintCallable)
    void UnlockOCL(bool bFireOCLUnlockedEvent);
    
    UFUNCTION(BlueprintCallable)
    void UnjamOCL(bool bFireOCLJammedEvent);
    
    UFUNCTION(BlueprintCallable)
    void UnbarOCL(bool bFireOCLUnbarredEvent, bool bEnterLockedState);
    
    UFUNCTION(BlueprintCallable)
    void ToggleInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartInteract(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    void SignalOCLAnimationComplete();
    
    UFUNCTION(BlueprintCallable)
    void SetInteractionState(int32 StateIn, bool bForceExecute);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractionsEnabled(bool bNewInteractionsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentInteractivityStateTemporary(bool bIsTemporary);
    
    UFUNCTION(BlueprintCallable)
    void SealOCL(bool bFireOCLSealedEvent);
    
    UFUNCTION(BlueprintCallable)
    void OverrideComponentsBoundingBox(const FBox& OverrideBox, bool bRegisterToOctree);
    
    UFUNCTION(BlueprintCallable)
    EOCLResult OpenOCL(AActor* Initiator, bool bSeal, bool bIgnoreLockStatus, bool bIgnoreStartEvent, bool bIgnoreEndEvent, bool bIgnoreSound, bool bInstantAnimation);
    
    UFUNCTION(BlueprintCallable)
    void OnPageExit(URPGExaminableData* RPGExaminableData, int32 PageIndex, bool bWasUIClosed);
    
    UFUNCTION(BlueprintCallable)
    void OnPageEnter(URPGExaminableData* RPGExaminableData, int32 PageIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPageChoiceSelect(URPGExaminableData* RPGExaminableData, int32 PageIndex, int32 PageChoiceIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnInteractStateInteract(int32 StateIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnInteractStateChanged(int32 NewState, int32 OldState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGadgetDeactivated(FGameplayTag GameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetActivated(FGameplayTag GameplayTag);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnFpvAnimProxyComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnConversationInstanceEnded(UOwConversationInstance* ConversationInstanceShuttingDown);
    
    UFUNCTION(BlueprintCallable)
    void LockOCL(bool bFireOCLLockedEvent);
    
    UFUNCTION(BlueprintCallable)
    void JamOCL(bool bFireOCLJammedEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSealing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSealed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOpening() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOpen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJammed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInteractionCrime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConsolidationEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsClosing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsClosed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBarred() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActorInFrontOfOCL(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable)
    bool HasWirePower();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FLocString GetLocString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetInteractState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description, float InteractDistance) const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    EInteractionRestrictions GetInteractionRestrictions(AIndianaCharacter* Initiator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetInteractHoldTime(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    EInteractionRestrictions GetIgnoredInteractionRestrictions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FGameplayTag GetGameplayTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETerminalLockState GetCurrentTerminalState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EOCLState GetCurrentStateOCL() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableInteractions();
    
    UFUNCTION(BlueprintCallable)
    void DisableInteractions();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CompleteInteract(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    EOCLResult CloseOCL(AActor* Initiator, bool Block, bool bSeal, bool bIgnoreLockStatus, bool bIgnoreStartEvent, bool bIgnoreEndEvent, bool bIgnoreSound, bool bInstantAnimation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& InteractPayload) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CancelInteract(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    void BarOCL(bool bFireOCLBarredEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreInteractionsEnabled() const;
    
};

