#include "AIGroupBehaviorVolume.h"
#include "ObsidianIDComponent.h"
#include "AIGroupBehaviorInstanceKitComponent.h"

AAIGroupBehaviorVolume::AAIGroupBehaviorVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AIGroupBehaviorInstanceKitComponent = CreateDefaultSubobject<UAIGroupBehaviorInstanceKitComponent>(TEXT("AIGroupBehaviorKit"));
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
    this->bAlwaysIncludeCompanions = true;
    this->bAutoCookOnPlayerOverlap = false;
}


