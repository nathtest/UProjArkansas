#pragma once
#include "CoreMinimal.h"
#include <AkComponent.h>
#include "IndianaFlybyAkComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIndianaFlybyAkComponent : public UAkComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorldZOffset;
    
public:
    UIndianaFlybyAkComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateEmitterLocation();
    
    UFUNCTION(BlueprintCallable)
    void InitializeEmitter();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateEmitter();
    
};

