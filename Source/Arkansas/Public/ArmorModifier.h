#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "Templates/SubclassOf.h"
#include "ArmorModifier.generated.h"

class UIndianaDamageType;

USTRUCT(BlueprintType)
struct FArmorModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer EffectedBodyParts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UIndianaDamageType>> DamageTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageThresholdPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageResistance;
    
    ARKANSAS_API FArmorModifier();
};

