#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "ComponentDebugInterface.h"
#include "ECharacterAudioEvent.h"
#include "ECharacterMovementAudioEvents.h"
#include "EDodgeDirection.h"
#include "EFootID.h"
#include "EFootstepType.h"
#include "ESpecialMovementEvent.h"
#include "LandAudioEvent.h"
#include "Templates/SubclassOf.h"
#include "IndianaAudioComponent.generated.h"

class UAkAudioEvent;
class UAkPlaySoundEventEffect;
class UAkSwitchValue;
class UAnimationAudioSet;
class UAnimationGameplayTagAudio;
class UEventEffectState;
class UFootstepAudio;
class UFootstepData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UIndianaAudioComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* PerspectiveSwitchValueOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* CreatureTypeSwitchValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CreatureType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<ECharacterAudioEvent, UAkPlaySoundEventEffect*> CharacterAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<ECharacterMovementAudioEvents, UAkPlaySoundEventEffect*> CharacterMovementAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLandAudioEvent> LandEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* FootstepEventOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFootstepAudio* CurrentFootstepAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEventEffectState* EventEffectState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAudioSet* AnimationAudioSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimationGameplayTagAudio> AnimationGameplayTagSet;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CurrentHeadStylePostProcess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUseExplicitPostProcess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CurrentExplicitPostProcess;
    
public:
    UIndianaAudioComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateFootstepRTPCs();
    
    UFUNCTION(BlueprintCallable)
    void OnUsingFurnitureStateChanged(bool bNewUsingFurnitureState);
    
    UFUNCTION(BlueprintCallable)
    void OnUglyStick(bool bUglyStick);
    
    UFUNCTION(BlueprintCallable)
    void OnStopClimb();
    
    UFUNCTION(BlueprintCallable)
    void OnStartClimb();
    
    UFUNCTION(BlueprintCallable)
    void OnSpecialMovementEvent(ESpecialMovementEvent SpecialEvent, const FVector& position, const FVector& Normal, TEnumAsByte<EPhysicalSurface> PhysMaterial);
    
    UFUNCTION(BlueprintCallable)
    void OnRagdollImpact(const FVector& NormalImpulse, const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    void OnNewFootstepData(const UFootstepData* NewData);
    
    UFUNCTION(BlueprintCallable)
    void OnLanded(float FallDistance, const FVector& position, const FVector& Normal, TEnumAsByte<EPhysicalSurface> PhysMaterial);
    
    UFUNCTION(BlueprintCallable)
    void OnJumpAnimStateChanged(bool bNewJumpAnimState);
    
    UFUNCTION(BlueprintCallable)
    void OnFootstep(EFootID FootID, EFootstepType FootstepType, const FVector& position, const FVector& Normal, TEnumAsByte<EPhysicalSurface> PhysMaterial);
    
    UFUNCTION(BlueprintCallable)
    void OnDodge(EDodgeDirection Direction, const FVector& position, const FVector& Normal, TEnumAsByte<EPhysicalSurface> PhysMaterial);
    

    // Fix for true pure virtual functions not being implemented
};

