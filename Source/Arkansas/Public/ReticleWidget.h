#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "BarPositionAnchorSet.h"
#include "EBodyPartRegion.h"
#include "EDetectionLevel.h"
#include "IndianaUserWidget.h"
#include "ReticleWidget.generated.h"

class AActor;
class AIndianaCharacter;
class UAkAudioEvent;
class UAkRtpc;
class UCanvasPanel;
class UCauseDamageReticleWidget;
class UCompanionCommandComponent;
class UCrosshairWidget;
class UEquipmentComponent;
class UImage;
class UMaterialInstanceDynamic;
class UOverlay;
class URangedMode;
class UTextBlockBase;
class UTexture2D;
class UWeapon;
class UWidgetAnimation;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UReticleWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D DefaultLockSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D FullyLockedSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DefaultLockColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor FullyLockedColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinLockOnThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StealthTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InteractCountThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeatParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowHeatBarAtZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBarPositionAnchorSet HeatBarAnchorSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ChargeActiveParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ChargeProgressParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ChargeFlashParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaxChargesParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlashDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowChargeBarAtZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBarPositionAnchorSet ChargeBarAnchorSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ReticleVisibilityTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag PerspectiveTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ShoulderTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCompanionCommandComponent> CompanionCommandComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* ReticleSizeRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag LockOnBodyPartTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OnLockonActiveAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OnLockonDetectedAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OnLockonDetectedStopAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OnLockonLockedAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OnLockonAcquiredAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OnLockonLostAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* RootCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ReticuleInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ReticleLockOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCrosshairWidget* Crosshair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* TTDRotators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* TTDOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* TTDDTOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* TTDFill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCauseDamageReticleWidget* CauseDamageWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* DTImageOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* DTImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* DTTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NPCAwarenessTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* StealthOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* HeatBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ChargingBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BleedIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString BleedText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* StunIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString StunText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* KnockDownIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString KnockDownText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* AnalyzerIntro;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ReticleLockOnPercentageName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EnergyBarPercentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EnergyBarSegmentsName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CachedHeatBarMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CachedChargeBarMaterial;
    
public:
    UReticleWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnWeaponEquipped(UEquipmentComponent* EquipmentComp, UWeapon* EquippedWeapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponAttack(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnTTDTargetLost();
    
    UFUNCTION(BlueprintCallable)
    void OnTTDTargetAcquired();
    
    UFUNCTION(BlueprintCallable)
    void OnTTDReticleMeterModeChanged(int32 bVisible);
    
    UFUNCTION(BlueprintCallable)
    void OnTTDMeterVisibilityChanged(int32 VisibilityIn);
    
    UFUNCTION(BlueprintCallable)
    void OnTTDMeterChanged(float PrevValue, float CurrValue);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetAnalyzerChanged(EBodyPartRegion BodyPartRegion, const AActor* TargetedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnShoulderChanged(bool bShoulderSwappedIn);
    
    UFUNCTION(BlueprintCallable)
    void OnScopedStateChanged(URangedMode* RangedMode, bool bIsFullyFineAimed);
    
    UFUNCTION(BlueprintCallable)
    void OnReticleVisibilityChanged(int32 VisibilityIn);
    
    UFUNCTION(BlueprintCallable)
    void OnReticleModeChanged(int32 ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void OnPerspectiveChanged(int32 PerspectiveIn);
    
    UFUNCTION(BlueprintCallable)
    void OnLockOnTargetChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnLockOnProgressChanged(float Progress);
    
    UFUNCTION(BlueprintCallable)
    void OnHUDVisibilityChanged(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void OnFineAimAutoAimEnableChanged(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void OnDetectionlevelChanged(EDetectionLevel OldLevel, EDetectionLevel NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChanged(AIndianaCharacter* InCharacter, bool bCombatIn, bool bRestoring);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnTargetLocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnScopeStateChanged(bool bIsFullyFineAimed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnLockOnTargetChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnLockOnProgressChanged(float Progress);
    
};

