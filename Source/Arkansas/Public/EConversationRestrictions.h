#pragma once
#include "CoreMinimal.h"
#include "EConversationRestrictions.generated.h"

UENUM()
enum class EConversationRestrictions : uint32 {
    None,
    Combat,
    HostileSE,
    Crime = 4,
    All = 0xFFFFFFFF,
};

