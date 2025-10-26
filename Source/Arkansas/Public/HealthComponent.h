#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include "BodyPartRegionHealth.h"
#include "ComponentDebugInterface.h"
#include "EStateOfBeing.h"
#include "NewStateOfBeingEventDelegate.h"
#include "OnBodyPartHealthChangedDelegate.h"
#include "OnBodyPartStateChangedDelegate.h"
#include "OnDamageTakenDelegate.h"
#include "OnDeathDelegate.h"
#include "OnHealthChangeDelegate.h"
#include "OnKillingBlowDelegate.h"
#include "OnMaxHealthChangeDelegate.h"
#include "OnRadToxicityChangedDelegate.h"
#include "OnRadToxicityRangeChangedDelegate.h"
#include "OnResurrectedDelegate.h"
#include "OnShieldHealthChangeDelegate.h"
#include "RadToxicityRangeData.h"
#include "Templates/SubclassOf.h"
#include "HealthComponent.generated.h"

class AActor;
class AIndianaAiCharacter;
class AIndianaCharacter;
class UAkRtpc;
class UCharacterInfoComponent;
class UDeathClass;
class URpgStat;
class URpgStatComponent;
class USpell;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHealthComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNewStateOfBeingEvent OnNewStateOfBeing;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHealthChange OnHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHealthChange OnTempHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnShieldHealthChange OnShieldHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMaxHealthChange OnMaxHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRadToxicityChanged OnRadToxicityChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRadToxicityRangeChanged OnToxicityRangeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnKillingBlow OnKillingBlowDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeath OnDowned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeath OnDeath;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResurrected OnResurrected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBodyPartStateChanged OnBodyPartStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBodyPartHealthChanged OnBodyPartHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDamageTaken OnDamageTaken;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartWithMissingHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartingHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRadToxicity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRadToxicityRangeData> RadToxicityRanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeathAtMaxRadToxicity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> MaxRadToxicitySpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetAtMaxRadToxicity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostMaxRadToxicityTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanRegenRadToxicity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseRegenRadToxicityRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCombatRadToxicityRegen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseInCombatRegenRadToxicityRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RegenRadToxicityDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCombatHealthRegen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RegenRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatRegenRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatRegenDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeDowned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentMaxHealthOnResurrect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBodyPartRegionHealth> BodyPartHealthData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, float> BodyPartHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGodMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPseudoGodMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNonPlayerPseudoGod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NonPlayerPseudoGodMinHealthPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImmuneToFallDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* DamageReceivedPercentageRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TempHealthMaxPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TempHealthDecayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDamagedByPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKilledByPlayer;
    
public:
    UHealthComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TryCureRadToxicity();
    
    UFUNCTION(BlueprintCallable)
    bool TryApplyRadToxicity(float ToxicityIn);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SuicideDelay(float Delay);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Suicide(bool bPreventRevival, TSubclassOf<UDeathClass> PreferredDeathClass);
    
    UFUNCTION(BlueprintCallable)
    void SetTempHealth(float TempHealthAmount, AActor* Instigator);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetStateOfBeing(EStateOfBeing NewStateOfBeing, bool bRestoredFromSave);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetShieldHealth(float ShieldHealthAmount, float ShieldHealthMax);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetRadToxicity(float Toxicity);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void SetRadPercent(float Percent);
    
    UFUNCTION(BlueprintCallable)
    void SetPseudoGod(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxTempHealth(float MaxTempHealth);
    
    UFUNCTION(BlueprintCallable)
    void SetInvolvedInRevive(bool bInvolvedInReviveIn);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetHealthPercentNPC(float Percent);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetHealthPercent_BP(float Percent, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetHealthPercent(float Percent, AActor* Instigator);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetHealth(float Health, AActor* Instigator);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetGod(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetBeingRevived(bool bBeingRevivedIn);
    
    UFUNCTION(BlueprintCallable)
    void Resurrect(bool bDebug, float HealthPercentOverride);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable)
    void LevelChanged(UCharacterInfoComponent* InCharacterInfoComponent, int32 Level);
    
public:
    UFUNCTION(BlueprintCallable)
    static void KillNPC(AIndianaAiCharacter* Character, TSubclassOf<UDeathClass> PreferredDeathClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReadyForEncounterConditionalQueries() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsInstanceDead(AIndianaCharacter* Character, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDowned() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void HealthFill();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasNonPlayerPseudoGod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeSinceLastSneakAttacked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTempHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStateOfBeing GetStateOfBeing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetShieldHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRegenRatePoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRegenRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRadToxicityRegenRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRadToxicity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPseudoGod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNormalizedTempHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNormalizedShieldHealth() const;
    
    UFUNCTION(BlueprintCallable)
    float GetNormalizedRadToxicity();
    
    UFUNCTION(BlueprintCallable)
    float GetNormalizedHealth();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNonPlayerPseudoGodMinHealthPercentage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxTempHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxShieldHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxRadToxicity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetLastHitInstigator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInvolvedInRevive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthOfBodyPart(FGameplayTag BodyPart) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetGodMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetBeingRevived() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableNonPlayerPseudoGodOverride(float InMinHealthPercentage);
    
protected:
    UFUNCTION(BlueprintCallable)
    void DownedComplete(AActor* DownedActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void DisableNonPlayerPseudoGodOverride();
    
protected:
    UFUNCTION(BlueprintCallable)
    void DeathComplete(AActor* DeadActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeDowned() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void AdjustRadToxicity(float Toxicity);
    

    // Fix for true pure virtual functions not being implemented
};

