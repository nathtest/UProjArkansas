#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "HitFlinchAnim.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FHitFlinchAnim {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BodyParts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Anim;
    
    ARKANSAS_API FHitFlinchAnim();
};

