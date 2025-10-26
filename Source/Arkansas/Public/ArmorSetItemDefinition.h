#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ArmorItemDefinition.h"
#include "Templates/SubclassOf.h"
#include "ArmorSetItemDefinition.generated.h"

class UArmorSet;

USTRUCT(BlueprintType)
struct FArmorSetItemDefinition : public FArmorItemDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UArmorSet> ArmorSetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, bool> AlreadyDestroyedParts;
    
    ARKANSAS_API FArmorSetItemDefinition();
};

