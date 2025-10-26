#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <EComparisonOperator.h>
#include <SpeakerReference.h>
#include "EBountyAdjustment.h"
#include "EBountyLevel.h"
#include "EBribeDifficulty.h"
#include "ERankAdjustment.h"
#include "ERankLevel.h"
#include "EStandingAdjustment.h"
#include "EStandingLevel.h"
#include "EStandingType.h"
#include "Templates/SubclassOf.h"
#include "FactionManager.generated.h"

class UFactionData;

UCLASS(Blueprintable)
class UFactionManager : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFactionKillOnSight_BP, const UFactionData*, FactionData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFactionAdjusted_BP, const UFactionData*, FactionData);
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UFactionData>, UFactionData*> FactionMap;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFactionAdjusted_BP OnFactionAdjusted_BP;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFactionKillOnSight_BP OnFactionKillOnSight_BP;
    
    UFactionManager();

    UFUNCTION(BlueprintCallable)
    static void UpdateLastKnownBounties_BP();
    
    UFUNCTION(BlueprintCallable)
    static void TransferBountyToNPC_BP(TSubclassOf<UFactionData> FactionData, FSpeakerReference SpeakerReference);
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void SetRandomReputations_Debug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetPositiveReputation_Debug(const FString& FactionName, int32 Amount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetNegativeReputation_Debug(const FString& FactionName, int32 Amount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetKillOnSight_Debug(const FString& FactionName);
    
public:
    UFUNCTION(BlueprintCallable)
    static void SetKillOnSight_BP(TSubclassOf<UFactionData> FactionData);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveBounty_BP(TSubclassOf<UFactionData> FactionData, FSpeakerReference SpeakerReference, EBountyAdjustment BountySize, int32 OverrideBountySize);
    
    UFUNCTION(BlueprintCallable)
    static void ReducePlayerBountyToFlatRate_BP(TSubclassOf<UFactionData> FactionData, int32 FlatRate);
    
    UFUNCTION(BlueprintCallable)
    static void RankUp_BP(TSubclassOf<UFactionData> FactionData);
    
    UFUNCTION(BlueprintCallable)
    static void PayOffBounty_BP(TSubclassOf<UFactionData> FactionData);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerBountyLevel_BP(TSubclassOf<UFactionData> FactionData, EComparisonOperator Operator, EBountyLevel BountyLevel, int32 OverrideBountyAmount);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFactionStandingType_BP(TSubclassOf<UFactionData> FactionData, EStandingType StandingType);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFactionStanding_BP(TSubclassOf<UFactionData> FactionData, EStandingType StandingType, EStandingLevel StandingLevel, EComparisonOperator Operator);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFactionRank_BP(TSubclassOf<UFactionData> FactionData, EComparisonOperator Operator, ERankLevel RankLevel, bool bRankEarned);
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void GetReputationDescription_Debug(const FString& FactionName);
    
public:
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayerBounty_BP(TSubclassOf<UFactionData> FactionData, bool bUseLastKnownBounty);
    
    UFUNCTION(BlueprintCallable)
    static float GetBribeScalar_BP(EBribeDifficulty BribeDifficulty);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetBounty_BP(TSubclassOf<UFactionData> FactionData, FSpeakerReference SpeakerReference, bool bUseLastKnownBounty);
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void GetAllReputationDescriptions_Debug();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool DoesFactionAdjustBountyOrStandingForCrime_BP(const TSubclassOf<UFactionData>& FactionData);
    
    UFUNCTION(BlueprintCallable)
    static void ClearFactionRecentHostilityToPlayer_BP(TSubclassOf<UFactionData> FactionData);
    
    UFUNCTION(BlueprintCallable)
    static void AdjustFactionStanding_BP(TSubclassOf<UFactionData> FactionData, EStandingAdjustment StandingAdjustment, bool bPositiveAdjustment, float CustomStandingAdjustment, bool bIgnoreFactionScalar, bool bSetEncountered);
    
    UFUNCTION(BlueprintCallable)
    static void AdjustFactionRank_BP(TSubclassOf<UFactionData> FactionData, ERankAdjustment RankAdjustment, bool bPositiveAdjustment, float CustomStandingAdjustment);
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void AddPositiveReputation_Debug(const FString& FactionName, int32 Amount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddPlayerBounty_Debug(const FString& FactionName, EBountyAdjustment BountySize, int32 OverrideBountySize);
    
public:
    UFUNCTION(BlueprintCallable)
    static void AddPlayerBounty_BP(TSubclassOf<UFactionData> FactionData, EBountyAdjustment BountySize, int32 OverrideBountySize);
    
private:
    UFUNCTION(BlueprintCallable, Exec)
    void AddNegativeReputation_Debug(const FString& FactionName, int32 Amount);
    
public:
    UFUNCTION(BlueprintCallable)
    static void AddBounty_BP(TSubclassOf<UFactionData> FactionData, FSpeakerReference SpeakerReference, EBountyAdjustment BountySize, int32 OverrideBountySize);
    
};

