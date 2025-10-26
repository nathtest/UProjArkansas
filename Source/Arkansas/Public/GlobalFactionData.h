#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMaterial -FallbackName=StaticMaterial
#include <SpeakerReference.h>
#include "BountyAdjustmentsForInteger.h"
#include "BountyAdjustmentsForOclDifficulty.h"
#include "BountyForStandingType.h"
#include "EBountyAdjustment.h"
#include "EBribeDifficulty.h"
#include "ECooldownLength.h"
#include "EIndianaUIColorType.h"
#include "ERankAdjustment.h"
#include "EReputationActionType.h"
#include "ESkillDifficultyTier.h"
#include "EStandingAdjustment.h"
#include "EStandingLevel.h"
#include "PsycopathDamageMultiplier.h"
#include "ReputationActionConsequence.h"
#include "GlobalFactionData.generated.h"

class UFactionData;

UCLASS(Blueprintable)
class UGlobalFactionData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UFactionData*, TEnumAsByte<ETeamAttitude::Type>> EmotionRelationshipMapping;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EReputationActionType, FReputationActionConsequence> ReputationActionConsequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EStandingAdjustment, float> StandingAdjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EStandingLevel, int32> StandingLevelThresholds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaximumStanding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, EIndianaUIColorType> StandingLevelUIColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERankAdjustment, float> RankAdjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, float> VendorPriceModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> SkillCheckModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EBountyAdjustment, int32> BountySizes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FBountyForStandingType> BountyLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FBountyForStandingType> SuaveBountyLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESkillDifficultyTier, FBountyAdjustmentsForOclDifficulty> OclCrimeBountyGain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESkillDifficultyTier, FBountyAdjustmentsForInteger> StealingBountyGain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBountyAdjustment ViolentBountyGain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandingAdjustment ViolentStandingLoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandingAdjustment InsufficientFundsStandingLoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBountyAdjustment RestrictedAreaBountyGain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EBribeDifficulty, float> BribeScalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FSpeakerReference, FStaticMaterial> WantedPosterStaticMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FSpeakerReference, FStaticMaterial> BountyTerminalsStaticMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BountyDegradationXPMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinimumBountyDegradationAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RepDisplayRatioBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECooldownLength, int32> ConversationCooldownXP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPsycopathDamageMultiplier> PsycopathDamageMultipliers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FreeTreatmentFactionStandingLoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NeutralSumThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MixedSumThreshold;
    
public:
    UGlobalFactionData();

};

