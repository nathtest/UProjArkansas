#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "DamageTypeScalar.h"
#include "ArmorVsDamageTypes.generated.h"

USTRUCT(BlueprintType)
struct FArmorVsDamageTypes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ArmorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDamageTypeScalar> DamageTypeScalars;
    
    ARKANSAS_API FArmorVsDamageTypes();
};

