#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "TPVAsyncWhiskerSetupTickFunction.h"
#include "TPVAsyncWhiskerTraceTickFunction.h"
#include "TPVSpringArmComponent.generated.h"

class AIndianaPlayerCharacter;
class UActorComponent;
class UCurveFloat;
class UEquipmentComponent;
class UTPVCameraComponent;
class UTPVWhiskerComponent;
class UWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UTPVSpringArmComponent : public USpringArmComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFineAimPlayLength;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVWhiskerComponent* Whiskers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVCameraComponent* TPVCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTPVAsyncWhiskerSetupTickFunction AsyncWhiskerSetupTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTPVAsyncWhiskerTraceTickFunction AsyncWhiskerTraceTick;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PitchTargetArmLengthCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TPVNearPitchTargetArmLengthCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AIndianaPlayerCharacter* OwningPlayer;
    
public:
    UTPVSpringArmComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetUseSecondaryShoulder(bool bUseSecondaryShoulder);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartUnHolster(UEquipmentComponent* EquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartHolster(UEquipmentComponent* EquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartEquip(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnTPVCameraDeactivated(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnFineAimStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnFineAimEnded();
    
public:
    UFUNCTION(BlueprintCallable)
    void ApplyWeaponOffsets(UWeapon* Weapon);
    
};

