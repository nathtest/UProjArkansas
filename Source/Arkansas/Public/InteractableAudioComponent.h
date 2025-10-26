#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
#include "InteractableAudioComponent.generated.h"

class UAkPlaySoundEventEffect;
class UEventEffectState;
class UOEIWwiseObjectPoolWrapper;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInteractableAudioComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UAkPlaySoundEventEffect*> GameplayTagEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UAkPlaySoundEventEffect*> GameplayTagStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOEIWwiseObjectPoolWrapper* WwiseObjectPoolWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEventEffectState* EventEffectState;
    
public:
    UInteractableAudioComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerEventByTag(const FGameplayTag& EventTag);
    
    UFUNCTION(BlueprintCallable)
    void StopEventByTag(const FGameplayTag& EventTag);
    
    UFUNCTION(BlueprintCallable)
    void LeaveStateByTag(const FGameplayTag& StateTag);
    
    UFUNCTION(BlueprintCallable)
    void EnterStateByTag(const FGameplayTag& StateTag);
    
};

