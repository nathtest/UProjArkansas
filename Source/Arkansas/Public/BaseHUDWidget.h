#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EHudIconDisplayArea.h"
#include "EUnlockAbility.h"
#include "IndianaUserWidget.h"
#include "OnResetEventTimerDelegate.h"
#include "RadToxicityRangeData.h"
#include "BaseHUDWidget.generated.h"

class AActor;
class AIndianaCharacter;
class ARestrictedArea;
class UHealthComponent;
class UScaleBox;
class UWeapon;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UBaseHUDWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResetEventTimer OnResetEventTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ScaleSettingTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> SubscribedTutorials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScaleBox* ContainerScaleBox;
    
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 EventSubscriptions;
    
public:
    UBaseHUDWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnWidgetVisibilityChanged(int32 NewVisibility);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTTDMeterChanged(float PrevValue, float CurrValue);
    
    UFUNCTION(BlueprintCallable)
    void OnToxicityMeterChanged(float PrevValue, float CurrValue);
    
    UFUNCTION(BlueprintCallable)
    void OnTempHealthChanged(UHealthComponent* HealthComponentIn, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void OnShieldHealthChanged(UHealthComponent* HealthComponentIn, float PrevNormalizedHealth, float CurrNormalizedHealth);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnScaleSettingChanged(float NewValue);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRadRangeChanged(const TArray<FRadToxicityRangeData> ToxicityRangeData);
    
    UFUNCTION(BlueprintCallable)
    void OnRadChanged(UHealthComponent* HealthComponentIn, float PrevNormalizedRad, float CurrNormalizedRad);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimerToxicityMultiplierChanged(float CurrValue);
    
    UFUNCTION(BlueprintCallable)
    void OnMaxHealthChanged(UHealthComponent* HealthComponentIn, float PrevMaxHealth, float CurMaxHealth);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnHUDVisibilityChanged(bool bIsVisible);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnHudIconRequestReceived(EHudIconDisplayArea HudIconDisplayArea);
    
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(UHealthComponent* HealthComponentIn, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void OnExitedRestrictedAreaBuffer(const ARestrictedArea* RestrictedArea);
    
    UFUNCTION(BlueprintCallable)
    void OnExitedRestrictedArea(const ARestrictedArea* RestrictedArea);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponChange(UWeapon* EquippedWeapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEnterRestrictedAreaBuffer(const ARestrictedArea* RestrictedArea);
    
    UFUNCTION(BlueprintCallable)
    void OnEnterRestrictedArea(const ARestrictedArea* RestrictedArea);
    
    UFUNCTION(BlueprintCallable)
    void OnEnemyFoundBody();
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChanged(AIndianaCharacter* InCharacter, bool bCombatIn, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnAbilityUnlocked(EUnlockAbility UnlockedAbility);
    
    UFUNCTION(BlueprintCallable)
    void OnAbilityLocked(EUnlockAbility UnlockedAbility);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnTutorialHighlightChanged(FGameplayTag SubscribedTutorial, bool bHighlightOn);
    
};

