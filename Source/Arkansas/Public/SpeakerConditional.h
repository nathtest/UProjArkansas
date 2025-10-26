#pragma once
#include "CoreMinimal.h"
#include <SpeakerReference.h>
#include "LogicalExpression.h"
#include "SpeakerConditional.generated.h"

USTRUCT(BlueprintType)
struct FSpeakerConditional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalExpression Conditional;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpeakerReference Speaker;
    
    ARKANSAS_API FSpeakerConditional();
};

