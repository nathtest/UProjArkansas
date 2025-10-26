#pragma once
#include "CoreMinimal.h"
#include <EQuestType.h>
#include "EQuestLocation.h"
#include "EQuestSortingOptions.h"
#include "QuestTypeFilterListStruct.generated.h"

USTRUCT(BlueprintType)
struct FQuestTypeFilterListStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestSortingOptions OptionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestType QuestTypeEnum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestLocation QuestLocationEnum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString QuestBeginningLetter;
    
    ARKANSAS_API FQuestTypeFilterListStruct();
};

