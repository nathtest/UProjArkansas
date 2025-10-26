#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "WeaponModDefaultVisuals.generated.h"

class UModVisual;

USTRUCT(BlueprintType)
struct FWeaponModDefaultVisuals {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer WeaponCategories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UModVisual* DefaultVisuals;
    
    ARKANSAS_API FWeaponModDefaultVisuals();
};

