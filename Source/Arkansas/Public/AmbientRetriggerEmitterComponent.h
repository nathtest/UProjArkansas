#pragma once
#include "CoreMinimal.h"
#include "OEIWwiseAmbientEmitterComponent.h"


#include "AmbientRetriggerEmitterComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UAmbientRetriggerEmitterComponent : public UOEIWwiseAmbientEmitterComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHandleLifetimeAutomatically;
    
    UAmbientRetriggerEmitterComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void EmitterVirtualised();
    
    UFUNCTION(BlueprintCallable)
    void EmitterPhysicalised();
    
};

