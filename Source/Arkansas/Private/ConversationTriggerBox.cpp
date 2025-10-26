#include "ConversationTriggerBox.h"
#include "ObsidianIDComponent.h"

AConversationTriggerBox::AConversationTriggerBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsCompanion = false;
    this->CompanionID = ESpecialObsidianID::None;
    this->bStartFromRootNodeOnFailure = false;
    this->bOnceEver = false;
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
    this->bHasTriggered = false;
}

void AConversationTriggerBox::TriggerConversation() {
}


