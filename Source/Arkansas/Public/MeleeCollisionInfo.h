#pragma once
#include "CoreMinimal.h"
#include <TransformedShapeVariant.h>
#include "MeleeCollisionInfo.generated.h"

USTRUCT(BlueprintType)
struct FMeleeCollisionInfo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransformedShapeVariant CollisionShapeInfo;
    
public:
    ARKANSAS_API FMeleeCollisionInfo();
};

