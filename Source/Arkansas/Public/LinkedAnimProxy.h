#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "LinkedAnimProxy.generated.h"

class AOEIPassiveAnimProxy;

USTRUCT(BlueprintType)
struct FLinkedAnimProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AOEIPassiveAnimProxy> AnimProxy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SubStateTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutomatic;
    
    ARKANSAS_API FLinkedAnimProxy();
};

