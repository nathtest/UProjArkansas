#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "AppearanceGoreCap.generated.h"

class USkeletalMesh;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FAppearanceGoreCap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BodyParts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> UpperCap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> LowerCap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> SkinnedCap;
    
    ARKANSAS_API FAppearanceGoreCap();
};

