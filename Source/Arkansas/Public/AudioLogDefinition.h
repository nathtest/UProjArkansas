#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "AudioLogDefinition.generated.h"

class UConversationAsset;

USTRUCT(BlueprintType)
struct FAudioLogDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseUniqueName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ConversationDisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConversationAsset* ConversationAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartNode;
    
    ARKANSAS_API FAudioLogDefinition();
};

