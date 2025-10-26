#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "AddictionModifier.generated.h"

USTRUCT(BlueprintType)
struct FAddictionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AddictionTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AmountToRemove;
    
    ARKANSAS_API FAddictionModifier();
};

FORCEINLINE uint32 GetTypeHash(const FAddictionModifier& Mod)
{
    return HashCombine(::GetTypeHash(Mod.AmountToRemove), ::GetTypeHash(Mod.AmountToRemove));
}