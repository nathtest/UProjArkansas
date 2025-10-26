#pragma once
#include "CoreMinimal.h"
#include <GlobalVariableReference.h>
#include "WantsToTalkGlobalVariables.generated.h"

USTRUCT(BlueprintType)
struct FWantsToTalkGlobalVariables {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalVariableReference> Variables;
    
    ARKANSAS_API FWantsToTalkGlobalVariables();
};

