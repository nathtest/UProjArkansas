#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
#include "AimAssistConfig.h"
#include "ComponentDebugInterface.h"
#include "EGameDifficulty.h"
#include "AimAssistComponent.generated.h"

class UWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAimAssistComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAimAssistEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AimAssistEnableSettingTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFrictionEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTargetStrafeLockEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBulletMagnetismEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBulletMagnetIgnoreSpread;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrackQuickTargetEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrackForcedTargetDivisor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrictionInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrictionOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAimAssistConfig DefaultAimAssistConfig;
    
public:
    UAimAssistComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleTrackQuickTarget();
    
    UFUNCTION(BlueprintCallable)
    void ToggleTargetStrafeLock();
    
    UFUNCTION(BlueprintCallable)
    void ToggleFriction();
    
    UFUNCTION(BlueprintCallable)
    void ToggleBulletMagnetism();
    
    UFUNCTION(BlueprintCallable)
    void ToggleAimAssist();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnMagnetismStrengthChanged(float StrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void OnDifficultyChanged(EGameDifficulty NewDifficulty);
    
    UFUNCTION(BlueprintCallable)
    void OnAimSnappingStrengthChanged(float StrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void OnAimAssistEnabledChanged(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void OnAdhesionOrFrictionStrengthChanged(float NewStrength);
    
    UFUNCTION(BlueprintCallable)
    void EquippedWeaponChanged(UWeapon* NewlyEquippedWeapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void EnableAimAssist(bool Enabled);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AimAssistVisualSpread(bool bEnable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AimAssistVisualSnappingCone(bool bEnable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AimAssistVisualCone(bool bEnable);
    

    // Fix for true pure virtual functions not being implemented
};

