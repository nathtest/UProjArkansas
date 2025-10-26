#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "AppearanceMatch.generated.h"

USTRUCT(BlueprintType)
struct FAppearanceMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Genders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Views;
    
    ARKANSAS_API FAppearanceMatch();
};

