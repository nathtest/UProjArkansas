#pragma once
#include "CoreMinimal.h"
#include <EQuestState.h>
#include "GenericCollapsableListEntry.h"
#include "QuestListEntryWidget.generated.h"

class UImage;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UQuestListEntryWidget : public UGenericCollapsableListEntry {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CritPathImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CompanionImage;
    
public:
    UQuestListEntryWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetQuestCompletionStatus(EQuestState QuestState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetActiveQuest(bool bActive);
    
};

