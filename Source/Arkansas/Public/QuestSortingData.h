#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include <EQuestType.h>
#include <LocString.h>
#include "DifficultyRange.h"
#include "EQuestDifficulty.h"
#include "EQuestLocation.h"
#include "QuestSortingData.generated.h"

UCLASS(Blueprintable)
class UQuestSortingData : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EQuestType, FLocString> QuestTypeStringIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EQuestLocation, FLocString> QuestLocationStringIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EQuestDifficulty, FLocString> QuestDifficultyStringIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EQuestDifficulty, FDifficultyRange> QuestDifficultyRanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString MostRecentQuestListTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AlphabeticalQuestListTitle;
    
public:
    UQuestSortingData();

};

