#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include <GameplayTagContainer.h>
#include "TPVPersonalityCollection.generated.h"

class UTPVPersonalitySet;
class UWeaponAnimationsCreature;

UCLASS(Blueprintable)
class UTPVPersonalityCollection : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTPVPersonalitySet* DefaultPersonality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<UWeaponAnimationsCreature>, TSoftObjectPtr<UTPVPersonalitySet>> WeaponBasedPersonalities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, TSoftObjectPtr<UTPVPersonalitySet>> AdditionalPersonalities;
    
    UTPVPersonalityCollection();

};

