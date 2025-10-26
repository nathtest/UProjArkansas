#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=ECompletionStatus -FallbackName=ECompletionStatus
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "QuestObjectiveWidget.generated.h"

class UOWRichTextBlockBase;
class UPanelWidget;
class UQuestAddendumWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UQuestObjectiveWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UQuestAddendumWidget> ObjectiveAddendum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOWRichTextBlockBase* ObjectiveTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* AddendumList;
    
public:
    UQuestObjectiveWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnObjectiveStatusChange(ECompletionStatus ObjectiveStatus);
    
};

