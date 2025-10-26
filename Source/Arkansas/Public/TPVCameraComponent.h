#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "ParkourMove.h"
#include "TPVCameraComponent.generated.h"

class AIndianaPlayerCharacter;
class UCurveFloat;
class UEquipmentComponent;
class UIndianaCharMovementComponent;
class UTPVCameraSettingsData;
class UTPVSpringArmComponent;
class UWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UTPVCameraComponent : public UCameraComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFineAimPlayLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlignmentMaxPitch;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTPVCameraSettingsData* TPVCameraSettingsDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpringArmScale;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AIndianaPlayerCharacter* OwningPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVSpringArmComponent* TPVSpringArmComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PitchFOVCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DefaultNearPitchFOVCurve;
    
public:
    UTPVCameraComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetUseSecondaryShoulder(bool bUseSecondaryShoulder);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartHolster(UEquipmentComponent* EquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartEquip(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndUnHolster(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnParkourStarted(const FParkourMove& ParkourMove);
    
    UFUNCTION(BlueprintCallable)
    void OnParkourEnded(const FParkourMove& ParkourMove);
    
    UFUNCTION(BlueprintCallable)
    void OnLadderClimbStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnLadderClimbEnded();
    
    UFUNCTION(BlueprintCallable)
    void OnFineAimStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnFineAimEnded();
    
    UFUNCTION(BlueprintCallable)
    void OnFieldOfViewSettingChanged(float NewFOV);
    
    UFUNCTION(BlueprintCallable)
    void OnCrouchStarted(UIndianaCharMovementComponent* MovementComponent, bool bPlayerToggled);
    
    UFUNCTION(BlueprintCallable)
    void OnCrouchEnded(UIndianaCharMovementComponent* MovementComponent, bool bPlayerToggled);
    
    UFUNCTION(BlueprintCallable)
    void ApplyWeaponOffsets(UWeapon* EquippedWeapon);
    
};

