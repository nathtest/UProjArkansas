#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include <EQuestState.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=QuestManager -FallbackName=QuestManager
#include "QuestManager.h"

#include "VisibleAddendumList.h"
#include "OwQuestManager.generated.h"

UCLASS(Blueprintable)
class UOwQuestManager : public UQuestManager {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestCompleted_BP, const FGuid&, QuestID);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnQuestCompleted_BP OnQuestCompleted_BP;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVisibleAddendumList> TrackedAddendums;
    
public:
    UOwQuestManager();

protected:
    UFUNCTION(BlueprintCallable, Exec)
    void QuestTriggerAddendum(const FString& QuestName, int32 AddendumNode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QuestStartX(int32 StartCount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QuestStart(const FString& QuestName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QuestMentioned(const FString& QuestName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QuestListAll();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QuestFail(const FString& QuestName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QuestComplete(const FString& QuestName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EQuestState GetQuestState_BP(const FGuid& QuestID) const;
    
};

