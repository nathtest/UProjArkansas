#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EEndPlayReason -FallbackName=EEndPlayReason
#include "ConversationManager.h"

#include "ConversationReference.h"
#include "ConversationDescription.h"
#include "ConversationPreviewer.h"
#include "EndConversationInstanceDelegate.h"
#include "OnConversationInterruptCompletedDelegate.h"
#include "StartConversationInstanceDelegate.h"
#include "OwConversationManager.generated.h"

class AActor;
class UOwConversationInstance;

UCLASS(Blueprintable)
class ARKANSAS_API UOwConversationManager : public UConversationManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartConversationInstance OnStartConversationInstance;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndConversationInstance OnEndConversationInstance;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, UOwConversationInstance*> ActiveConversationInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UOwConversationInstance*> TerminatingConversationInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UOwConversationInstance* PendingConversationInstance;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationPreviewer ConversationPreviewer;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FConversationDescription ResumeDescription;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnConversationInterruptCompleted OnConversationInterruptCompleted;
    
    UOwConversationManager();

private:
    UFUNCTION(BlueprintCallable)
    void OnSpeakerActorEndPlay(AActor* SpeakerActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
    UFUNCTION(BlueprintCallable)
    void OnSpeakerActorDestroyed(AActor* SpeakerActor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnResumeExpirationTimerComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnResumeDelayTimerComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnResumeConditionsQueryTimerComplete();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerInInterrogationConversation();
    
    UFUNCTION(BlueprintCallable)
    static bool IsConversationValid(const FConversationReference& Conversation, AActor* Owner, int32 InStartingNode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsConversationInterruptActive();
    
    UFUNCTION(BlueprintCallable)
    static bool IsCharacterValidForGenericSpeaker(const FConversationReference& Conversation, AActor* Character);
    
};

