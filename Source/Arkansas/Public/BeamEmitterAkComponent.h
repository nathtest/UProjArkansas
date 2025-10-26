#pragma once
#include "CoreMinimal.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "BeamEmitterAkComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBeamEmitterAkComponent : public UAkComponent {
    GENERATED_BODY()
public:
    UBeamEmitterAkComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateEmitterLocation(FVector StartPoint, FVector EndPoint);
    
};

