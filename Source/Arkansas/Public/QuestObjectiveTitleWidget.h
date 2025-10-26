#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=ECompletionStatus -FallbackName=ECompletionStatus
#include "Blueprint/UserWidget.h"
#include "QuestObjectiveTitleWidget.generated.h"

class UQuestIconImage;
class UQuestObjectiveWidget;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UQuestObjectiveTitleWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCullOptionalString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestIconImage* ObjectiveIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* ObjectiveTitleTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* OptionalTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestObjectiveWidget* QuestObjective;
    
public:
    UQuestObjectiveTitleWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnOptionalObjective(bool bIsOptional);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnObjectiveStatusChange(ECompletionStatus ObjectiveStatus);
    
};

