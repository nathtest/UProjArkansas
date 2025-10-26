#pragma once
#include "CoreMinimal.h"
#include <EQuestType.h>
#include "QuestTypeGrouping.generated.h"

USTRUCT(BlueprintType)
struct FQuestTypeGrouping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EQuestType> quests;
    
    ARKANSAS_API FQuestTypeGrouping();
};

