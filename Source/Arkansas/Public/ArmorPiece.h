#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ArmorData.h"
#include "ArmorPiece.generated.h"

USTRUCT(BlueprintType)
struct FArmorPiece {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BodyParts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorData ArmorData;
    
    ARKANSAS_API FArmorPiece();
};

