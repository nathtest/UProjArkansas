#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=FloatInterval -FallbackName=FloatInterval
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2f -FallbackName=Vector2f
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimNodeReference -FallbackName=AnimNodeReference
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimUpdateContext -FallbackName=AnimUpdateContext
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include "BipedAnimInstance.h"
#include "BlockedPose.h"
#include "BodyOrientTurn.h"
#include "EHitRegion.h"
#include "EReactionType.h"
#include "P3PHitReactionAnimData.h"
#include "ParkourMove.h"
#include "PlayerTPVLocomotionAnimationData.h"
#include "Templates/SubclassOf.h"
#include "PlayerTPVAnimInstance.generated.h"

class AActor;
class UAnimSequence;
class UAnimSequenceBase;
class UBlendSpace;
class UCurveFloat;
class UDematerializerAnimationsTPV;
class UEquipmentComponent;
class UGadget;
class UGadgetDematerializer;
class UIndianaCharMovementComponent;
class UMedKitComponent;
class UPlayerMovementComponent;
class UPlayerTPVWeaponAnimations;
class UPlayerTargetingComponent;
class UPointingConfig;
class USpell;
class UThrowable;
class UWeapon;
class UWeaponAnimationsTPV;

UCLASS(Blueprintable, NonTransient)
class ARKANSAS_API UPlayerTPVAnimInstance : public UBipedAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInThirdPerson;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWeaponAnimationsTPV> HolsterWeaponAnimationsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimationsTPV* HolsterWeaponAnimations;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsSliding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsingSecondaryShoulder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPlayerInCombatState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInThrowingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPerformingWindupPowerAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsingQuickMelee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsing1HMelee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsing2HMelee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerTPVWeaponAnimations* CurrentPlayerWeaponAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPlayerTPVLocomotionAnimationData LocomotionAnimData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAnimSequence> ParkourAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsParkouring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerMovementComponent* PlayerMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMedKitComponent* PlayerMedkitComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerTargetingComponent* PlayerTargetingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDepictMidair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidairGroundDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidairVerticalSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsMultiJumping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsHovering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsingMedkit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bNRayAnimationActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bWantsToCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bWantsFineAim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFineAiming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGunPointIKEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator ControlRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RelativeAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AimOffsetAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NonCombatCrouchAimOffsetYawInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MeleeAttackAimoffsetCurveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeAimoffsetAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LeanAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsingMeleeWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsUsingLightMeleeWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PlasmaPistolSprintChargeSpeedThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PistolSprintFireSpeedThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RangedTwoHandedSprintFireSpeedThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PostFiringGunBlockedCooldownSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bReloading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFiring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bRechambering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HeavyArmorAdditiveAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SlideIKAimAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LeaningAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AimOffsetAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EnableAimOffsetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSlideTransitionOngoing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bStopTransitionOngoing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSprintFireOngoing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCrouchTransitionOngoing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LookAtClamp;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval LookAtClampMinMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Spine01NonCombatAimAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Spine02NonCombatAimAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Spine03NonCombatAimAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HeadNonCombatAimAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator HandIKAdjustmentRotator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HandIKAdjustmentAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HandIKAdjustmentAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FlinchAlpha;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval FlinchAlphaMinMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector2f HoverLeanAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HoverTurnAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StandCrouchStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bUse1HIKAim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bUse2HIKAim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDirectionChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDoSprintImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCombatStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TimeSinceCombatStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ControlRotationDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector CameraForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform CurrentWeaponMuzzleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector AimTargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector PointingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPointingConfig* PointingConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator TorsoRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCanPlayStarts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCanPlayStops;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RunStartElapsedTime;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval StandStartRateForwardInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval StandStartRateForwardOutRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval StandStartRateLeftRightInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval StandStartRateLeftRightOutRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval StandStartRateBackwardInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval StandStartRateBackwardOutRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval CrouchStartRateForwardInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval CrouchStartRateForwardOutRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval CrouchStartRateLeftRightInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval CrouchStartRateLeftRightOutRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval CrouchStartRateBackwardInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval CrouchStartRateBackwardOutRange;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObstacleInputAlignment;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInputIntoObstacle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bOverrideMontageLowerBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackAngle_NC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftFrontAngle_NC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightFrontAngle_NC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackAngle_NC;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval NonCombatForwardMovementAcceptance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval NonCombatBackwardMovementAcceptance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackAngle_CombatStand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftFrontAngle_CombatStand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightFrontAngle_CombatStand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackAngle_CombatStand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackAngle_Sprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftFrontAngle_Sprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightFrontAngle_Sprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackAngle_Sprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackAngle_CombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftFrontAngle_CombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightFrontAngle_CombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackAngle_CombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackAngle_NonCombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftFrontAngle_NonCombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightFrontAngle_NonCombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackAngle_NonCombatCrouch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackAngle_FineAimBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftFrontAngle_FineAimBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightFrontAngle_FineAimBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackAngle_FineAimBlock;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval SprintRateForwardInRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval SprintRateForwardOutRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator WorldCapsuleRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector WorldVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector NormalizedLocalVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MovementAngleRelativeToCapsule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMovingForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMovingBackward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMovingLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMovingRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EaseRelativeInputAngleInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector RelativePlayerInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RelativePlayerInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RelativeBackwardPlayerInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float EaseRelativeForwardInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float EaseRelativeBackwardInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float EaseRelativeInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInputIsForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInputIsBackward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInputIsLeftward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInputIsRightward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EHitRegion, FGameplayTagContainer> BodyRegionParts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, EReactionType> ReactionTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EReactionType, float> ReactionTypeCooldowns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FP3PHitReactionAnimData CurrentFlinch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FP3PHitReactionAnimData CurrentDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTag DisableTypeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bReactLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bReactHeavy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bReactKnockback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bShouldApplyBodyOrient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BodyOrientRates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BodyOrientRateFactor_Reversal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BodyOrientRates_Crouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BodyOrientRateFactor_Reversal_Crouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BodyOrientRates_Starting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BodyOrientRates_Hovering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BodyOrientCheckSensitivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BodyOrientUpdateSensitivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreNonCombatBodyOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBodyOrientTurn CurrentBodyOrient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HipsOrientInterpSpeedDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HipsOrientInterpSpeedSprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HipsOrientation;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval HipsOrientationForwardRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HipsOrientationForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsStopping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MovementInputAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PreviousMovementInputAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasMovementInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxStopFrameCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StopAngleRelativeToCapsule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PivotAngleAcceptance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisablePivots;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval FromBackwardToForwardAnglePivot;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval FromForwardToBackwardAnglePivot;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval FromLeftToRightAnglePivot;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval FromRightToLeftAnglePivot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPivoting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPivotRightToLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPivotLeftToRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPivotForwardToBackward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPivotBackwardToForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PivotOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PivotLeftExitRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PivotRightExitRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PivotForwardExitRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PivotBackwardExitRange;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCurveFloat> PivotOrientationCurve;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnInPlaceRotationIncident;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTurningInPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurningInPlaceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentBodyOrientAngleNonCombatJump;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDematerializerStateMachineInProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDematerializerLoopAnimationRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDematerializerCancelRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasCatalyzingPerkSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDematerializerAnimationsTPV* DematerializerAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> SprayCatalyzingPerkSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsDematerializerActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGadgetDematerializer> EquippedDematerializer;
    
public:
    UPlayerTPVAnimInstance();

    UFUNCTION(BlueprintCallable)
    void StartHovering();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetUseSecondaryShoulder(bool bUseSecondaryShoulder);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ParkourFire(UAnimSequence* AnimSequence);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowAnimStarted(const UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowAnimEnded(UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowableHoldLoopStart();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStartParkour(const FParkourMove& ParkourMove);
    
    UFUNCTION(BlueprintCallable)
    void OnStartCrouch(UIndianaCharMovementComponent* InMovementComponent, bool bPlayerToggled);
    
    UFUNCTION(BlueprintCallable)
    void OnStartClimb();
    
    UFUNCTION(BlueprintCallable)
    void OnPerkSpellsApplied();
    
    UFUNCTION(BlueprintCallable)
    void OnMultiJump();
    
    UFUNCTION(BlueprintCallable)
    void OnJumpUpdate(const FAnimUpdateContext& Context, const FAnimNodeReference& Node);
    
    UFUNCTION(BlueprintCallable)
    void OnJumpInitialUpdate(const FAnimUpdateContext& Context, const FAnimNodeReference& Node);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnGadgetUnequipped(const UGadget* Gadget);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetEquipped(const UGadget* Gadget);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetActivate(FGameplayTag GameplayTag);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFineAimStart();
    
    UFUNCTION(BlueprintCallable)
    void OnFineAimEnd();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponUnholsterInstant(UEquipmentComponent* EquipmentComponentIn, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponStartUnholster(UEquipmentComponent* UhholsterEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponStartHolster(UEquipmentComponent* HolsterEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponStartEquip(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponHolsterInstant(UEquipmentComponent* EquipmentComponentIn, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponEndUnholster(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponEndUnequip(UEquipmentComponent* HolsterEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponEndHolster(UWeapon* Weapon);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndParkour(const FParkourMove& ParkourMove);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnAttackComplete(AActor* Attacker, int32 AttackID, bool bIsQuickMelee);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponTwoHanded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponRangedHeavy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponOneHanded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponHolstered() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSprinting() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInCombat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNonCombatMovingForward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNonCombatMovingBackward() const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMoving(const float Tolerance) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInputRelativelyRightSide() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTimeElapsedForGunBlockedPose() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTurnInPlaceYawOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBlendSpace* GetRightWalkRunBlendspace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetParkourMinigunAdjustmentAlpha() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetNonCombatRunStartRight90() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetNonCombatRunStartLeft90() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetNonCombatPivotRightToLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetNonCombatPivotLeftToRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBlendSpace* GetLeftWalkRunBlendspace() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInputIntoObstacle();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetCombatRunStartRight90() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetCombatRunStartLeft90() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetCombatPivotRightToLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequenceBase* GetCombatPivotLeftToRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBlockedPose GetBlockedPose() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAvoidWeaponClipping() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void EndHovering();
    
    UFUNCTION(BlueprintCallable)
    void EndFlinch();
    
    UFUNCTION(BlueprintCallable)
    void EndDisableReaction();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUseWeaponFineAimSlot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUseRangedTwoHandedSprintFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUsePlasmaPistolSprintCharge() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUsePistolSprintFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanTurnInPlaceRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanTurnInPlaceLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanThrowableUseLowerbodyLocomotion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPivotRightExit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPivotLeftExit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPivotForwardExit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPivotBackwardExit() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcStandStartRateLeftRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcStandStartRateForward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcStandStartRateBackward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcSprintRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float CalcFlinchAlpha();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcCrouchStartRateLeftRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcCrouchStartRateForward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float CalcCrouchStartRateBackward() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintOnStartParkour(const FParkourMove& ParkourMove);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintOnEndParkour(const FParkourMove& ParkourMove);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreArmsDeviated() const;
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_OnRunStartExit();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_OnRunStartEnter();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_OnDematerializerStateMachineComplete();
    
};

