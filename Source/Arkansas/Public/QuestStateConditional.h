#pragma once
#include "CoreMinimal.h"
#include <EQuestState.h>
#include <QuestReference.h>
#include "EEqualityComparison.h"
#include "QuestStateConditional.generated.h"

USTRUCT(BlueprintType)
struct FQuestStateConditional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestReference QuestReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEqualityComparison Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestState ComparisonState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefault;
    
    ARKANSAS_API FQuestStateConditional();
};

