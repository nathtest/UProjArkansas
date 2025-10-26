#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include <EComparisonOperator.h>
#include "ERankLevel.h"
#include "ESkill.h"
#include "ESkillDifficultyRange.h"
#include "EStandingLevel.h"
#include "EStandingType.h"
#include "GameStateMetadataConditionalsBP.generated.h"

class UFactionData;
class UTravelRegionData;

UCLASS(Blueprintable)
class ARKANSAS_API UGameStateMetadataConditionalsBP : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGameStateMetadataConditionalsBP();

    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasSkill(ESkill Skill, EBoolResult& OutResult, EComparisonOperator Operater, ESkillDifficultyRange DifficultyRange, int32 TierOverride, int32 SkillValueOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasGlobalValue(FGuid Variable, EComparisonOperator Operator, int32 Value, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasFactionStanding(TSoftClassPtr<UFactionData> Faction, EStandingType StandingType, EStandingLevel StandingLevel, EComparisonOperator Operator, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasFactionRank(TSoftClassPtr<UFactionData> Faction, EComparisonOperator Operator, ERankLevel RankLevel, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestCompleteForLatestSave(FGuid QuestID, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestActiveForLatestSave(FGuid QuestID, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLatestSaveInRegion(TSoftObjectPtr<UTravelRegionData> TravelRegion, EBoolResult& OutResult);
    
};

