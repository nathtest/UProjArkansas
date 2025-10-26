#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include <GameplayTagContainer.h>
#include "AnimEventGameplayTagContainer.h"
#include "EAnimLadderState.h"
#include "EAnimMovementModifierState.h"
#include "EAnimMovementState.h"
#include "EHolsterState.h"
#include "EStateOfBeing.h"
#include "OwAnimInstance.h"
#include "PairedWeaponMontageInfo.h"
#include "Templates/SubclassOf.h"
#include "CharacterAnimInstance.generated.h"

class UIndianaCharMovementComponent;
class ULocomotionAnimationSet;
class UPoseAsset;
class UThrowable;
class UThrowableAnimInstance;
class UWeaponAnimations;

UCLASS(Blueprintable, NonTransient)
class UCharacterAnimInstance : public UOwAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWeaponAnimations> DefaultWeaponAnimationsTemplate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimations* DefaultWeaponAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimations* WeaponAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimations* WeaponAnimationsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimations* CurrentWeaponAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocomotionAnimationSet* LocomotionAnimationSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimMovementState MovementState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimMovementModifierState MovementModifierState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoingParkour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimLadderState LadderState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUsingLadderAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UThrowableAnimInstance* ThrowableAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastFallDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsEquipping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUnequipping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBlocking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsReloading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBeingBumped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsHitReacting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitReactStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitReactX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitReactY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForwardSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StrafeSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float NormalizedSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFullyCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrouchedProgressNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWeaponIsHolstered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHolsterState CurrentHolsterState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHelmetIsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponAnimCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponRampSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WeaponFineAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WeaponFineAimOffsetX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WeaponNormalAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EStateOfBeing HealthState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsDowned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsHealthy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasRecentlyMoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseAsset* FacePoses;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPairedWeaponMontageInfo> MontagesToStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPairedWeaponMontageInfo> MontagesToPlay;
    
public:
    UCharacterAnimInstance();

    UFUNCTION(BlueprintCallable)
    void SetDisabledAnimation(FAnimEventGameplayTagContainer Container);
    
    UFUNCTION(BlueprintCallable)
    void OnUseLadderAnimations(bool bIsUsingLadderAnimationsIn);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowableUnequipped(UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowableEquipped(UThrowable* Throwable);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRebuildAnimationSetData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNewWeaponAnimations(UWeaponAnimations* NewWeaponAnimations);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNewLocomotionAnimationSet(ULocomotionAnimationSet* NewLocomtionAnimationSet);
    
    UFUNCTION(BlueprintCallable)
    void OnMovementLanded(UIndianaCharMovementComponent* InMovementComponent, float Distance);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MatchesWeaponCategoryTag(FGameplayTag WeaponCategoryTag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MatchesArmorTypeTag(FGameplayTag ArmorTypeTag) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsThrowStateMachineInProgress() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMontagePlayingOnSlot(FName SlotNodeName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentHolsterState(EHolsterState HolsterState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMontagePlayingStatusOfSlot(FName SlotNodeName, float CurrentWeight, bool& Playing, bool& Additive, bool& HasRootMotion, float& Weight) const;
    
};

