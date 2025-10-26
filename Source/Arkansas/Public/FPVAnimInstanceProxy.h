#pragma once
#include "CoreMinimal.h"
#include "Animation\AnimInstanceProxy.h"

#include "FPVAnimInstanceProxy.generated.h"

USTRUCT(BlueprintType)
struct FFPVAnimInstanceProxy : public FAnimInstanceProxy {
    GENERATED_BODY()
public:
    ARKANSAS_API FFPVAnimInstanceProxy();
};

