#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "LightToggleAmbientVolume.generated.h"

class AActor;
class ALight;

UCLASS(Blueprintable)
class ARKANSAS_API ALightToggleAmbientVolume : public ATriggerVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ALight*> LightsToEnableOnEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ALight*> LightsToDisableOnEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FixtureLightsToEnableOnEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FixtureLightsToDisableOnEntry;
    
    ALightToggleAmbientVolume(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
    
};

