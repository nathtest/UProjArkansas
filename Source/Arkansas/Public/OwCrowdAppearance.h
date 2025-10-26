#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OEICrowdAppearance.h"

#include "OwCrowdAppearanceEntry.h"
#include "OwCrowdAppearanceEyeColor.h"
#include "OwCrowdAppearanceHairColor.h"
#include "OwCrowdAppearanceLayers.h"
#include "OwCrowdAppearanceSkinTone.h"
#include "OwCrowdAppearance.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UOwCrowdAppearance : public UOEICrowdAppearance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FOwCrowdAppearanceEntry> OWCrowdAppearances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOwCrowdAppearanceEyeColor> EyeColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOwCrowdAppearanceHairColor> HairColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOwCrowdAppearanceSkinTone> SkinTones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FOwCrowdAppearanceLayers> Layers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EyeSumWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HairSumWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkinToneSumWeight;
    
    UOwCrowdAppearance();

};

