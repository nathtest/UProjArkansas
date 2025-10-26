#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include "AnimEventGameplayContext.h"
#include "AnimEventGameplayTagData.generated.h"

class UBasePlayAnimEventEffect;

USTRUCT(BlueprintType)
struct FAnimEventGameplayTagData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimEventGameplayContext Context;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBasePlayAnimEventEffect* AnimEventEffect;
    
    ARKANSAS_API FAnimEventGameplayTagData();
};

