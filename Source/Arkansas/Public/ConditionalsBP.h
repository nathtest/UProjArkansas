#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include <EComparisonOperator.h>
#include "EBuildType.h"
#include "EDownLoadableContent.h"
#include "EOCLState.h"
#include "ESkill.h"
#include "ESkillDifficultyRange.h"
#include "ESpecialObsidianID.h"
#include "ETrapTriggerState.h"
#include "Templates/SubclassOf.h"
#include "ConditionalsBP.generated.h"

class AWire;
class UConversationAsset;
class UFactionData;
class UFlaw;
class UItem;
class UPerk;
class UShipDestinationData;

UCLASS(Blueprintable)
class UConditionalsBP : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UConditionalsBP();

    UFUNCTION(BlueprintCallable)
    static bool PlayerHasSkillOrPerkPoints(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasPerk(TSoftClassPtr<UPerk> Perk, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasFlaw(TSoftClassPtr<UFlaw> Flaw, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsWireEnabled(const AWire* Wire, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTrapStateEqual(FGuid TrapObjectID, ETrapTriggerState State, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsRestrictedAreaEnabled(FGuid RestrictedAreaID, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerWounded(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerWithinVolume(FGameplayTag Type, FGameplayTag Flavor, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerSkill(ESkill Skill, EBoolResult& OutResult, EComparisonOperator Operator, ESkillDifficultyRange DifficultyRange, int32 TierOverride, int32 SkillValueOverride, bool bUseCompanionInterjection);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerShipLocation(TSoftObjectPtr<UShipDestinationData> ShipDestination, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerInStealth(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerInCombat(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPartyFull(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPackagedBuild(EBuildType BuildType, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsOCLStateEqual(FGuid OCLObjectID, EOCLState State, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFactionRelationship(TSubclassOf<UFactionData> Faction, TEnumAsByte<ETeamAttitude::Type> AttitudeType, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCurrentActiveCompanionAmount(EComparisonOperator Operator, int32 Quantity, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompanionInActiveParty(ESpecialObsidianID Companion, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool HasItem(TSoftClassPtr<UItem> Item, EBoolResult& OutResult, EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool HasDLCTag(const FGameplayTag& DLCEntitlementTag, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool HasDLC(EDownLoadableContent DLC, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool DoesPlayerNeedDoctor(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool DoesConversationNodePass(UConversationAsset* Conversation, int32 NodeID, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool CompanionWantsToTalk(ESpecialObsidianID CompanionID, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool CompanionHasPerk(ESpecialObsidianID CompanionID, TSoftClassPtr<UPerk> Perk, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool CanPlayerAffordDoctor(EBoolResult& OutResult);
    
};

