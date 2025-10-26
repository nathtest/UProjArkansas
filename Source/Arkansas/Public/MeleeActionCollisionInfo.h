#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <TransformedShape.h>
#include "MeleeActionCollisionInfo.generated.h"

class UShapeComponent;

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class UMeleeActionCollisionInfo : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* CollisionShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransformedShape CollisionShapeInfo;
    
    UMeleeActionCollisionInfo();

};

