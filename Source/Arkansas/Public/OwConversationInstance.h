#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box -FallbackName=Box
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include "OEICineConversationInstance.h"

#include "ConversationReference.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=ENodeDisplayType -FallbackName=ENodeDisplayType
#include "CauseDamageInfo.h"
#include "EPresentationModeCameraFadeType.h"
#include "OnOwConversationInstanceShutdownDelegate.h"
#include "OwConversationInstance.generated.h"

class AActor;
class AIndianaCharacter;
class AStageMarkActor;
class UOwConversationManager;
class UOwNavModifierComponent;

UCLASS(Blueprintable, Config=Game)
class UOwConversationInstance : public UOEICineConversationInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnOwConversationInstanceShutdown OnOwConversationInstanceShutdown;
    
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityCheckTime;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndividualProximityCheckDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompanionProximityCheckDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityCheckDistanceCap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOwNavModifierComponent* StageNavModifierComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> WorldActorPayload;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowSkipWidgetForBarkCinematic;
    
public:
    UOwConversationInstance();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasConversationInterrupted() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool RequiresSubtitles() const;
    
    UFUNCTION(BlueprintCallable)
    void QueueCameraReturnToPlayer();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTimeDilationUpdated(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerTeleportedToStageMark(AIndianaCharacter* Character, AStageMarkActor* StageMark);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnParticipantCineActorTargetSettingsUpdate();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCharacterDeath(AActor* Instigator, const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterCombatStateChange(AIndianaCharacter* Character, bool bIsInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnBarkCinematicSkipped();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTalkNode(int32 NodeID) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConversationEnded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetStageNavModifierBounds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UOwConversationManager* GetOWConversationManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGuid GetCurrentSpeakerID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCurrentSpeaker() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void GamePauseChanged(bool bIsPaused);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnShutdownBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnPresentationModeFadeOutComplete(EPresentationModeCameraFadeType FadeType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnPresentationModeFadeInReady(EPresentationModeCameraFadeType FadeType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnNewConversationTriggered(FConversationReference NewConversation, int32 NewStartNode);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnConversationStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnConversationNodeChanged(int32 NewNode);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnConversationEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 BP_GetCurrentNodeID() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENodeDisplayType BP_GetConversationDisplayType() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> BP_GetAllSpeakers() const;
    
};

