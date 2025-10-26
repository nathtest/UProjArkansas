#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EQuestSortingOptions.h"
#include "QuestSortTypePage.generated.h"

USTRUCT(BlueprintType)
struct FQuestSortTypePage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestSortingOptions OptionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString SortingTypeString;
    
    ARKANSAS_API FQuestSortTypePage();
};

