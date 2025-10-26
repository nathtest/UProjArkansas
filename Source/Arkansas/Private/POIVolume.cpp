#include "POIVolume.h"
#include "ObsidianIDComponent.h"

APOIVolume::APOIVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkillDifficultyTierOverride = ESkillDifficultyTier::Invalid;
    this->LootBudgetMultiplier = 1.00f;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}


