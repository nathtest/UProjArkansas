#pragma once
#include "CoreMinimal.h"
#include <EQuestState.h>
#include <QuestReference.h>
#include "EEqualityComparison.h"
#include "InteractableRequirement.h"
#include "QuestRequirement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UQuestRequirement : public UInteractableRequirement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestReference QuestReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEqualityComparison Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestState ComparisonState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefault;
    
public:
    UQuestRequirement();

};

