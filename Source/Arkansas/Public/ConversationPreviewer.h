#pragma once
#include "CoreMinimal.h"
#include <ConversationNavigator.h>
#include "ConversationPreviewer.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FConversationPreviewer {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationNavigator PreviewNavigator;
    
public:
    FConversationPreviewer();
};

