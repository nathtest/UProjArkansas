#pragma once
#include "CoreMinimal.h"
#include "Particles\ParticleSystemComponent.h"

#include "PooledParticleSystemComponent.generated.h"

class UParticlePool;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPooledParticleSystemComponent : public UParticleSystemComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticlePool* OwningPool;
    
public:
    UPooledParticleSystemComponent(const FObjectInitializer& ObjectInitializer);

};

