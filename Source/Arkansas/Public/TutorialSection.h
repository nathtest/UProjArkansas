#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "TutorialSectionEntry.h"
#include "TutorialSection.generated.h"

USTRUCT(BlueprintType)
struct FTutorialSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString SectionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTutorialSectionEntry> TutorialEntries;
    
    ARKANSAS_API FTutorialSection();
};

