#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <LocString.h>
#include "EAnimNotify.h"
#include "OnToxicityCrashDelegate.h"
#include "Templates/SubclassOf.h"
#include "ToxicityMeterChangeDelegate.h"
#include "MedKitComponent.generated.h"

class AIndianaCharacter;
class UAkAudioEvent;
class UAnimMontage;
class UHealthComponent;
class URpgStat;
class URpgStatComponent;
class USpell;
class UTexture2D;
class UWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMedKitComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FToxicityMeterChange ToxicityMeterChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnToxicityCrash OnToxicityCrash;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnToxicityCrash OnToxicityCrashEnd;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* AbilityIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* TriggerSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* SingleDoseMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* SingleDoseMontageP1P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* DoubleDoseMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* DoubleDoseMontageP1P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentToHealCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToxicityDepletionDelayInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToxicityDepletionDelayOutOfCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> CrashSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToxicityCrashThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToxicityDepletionRateInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToxicityDepletionRateOutOfCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrashDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* CrashReactionAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* CrashRecoverAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* InhalerFailedAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* InhalerFailedCrashAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ConsumeNourishmentAudioEvent;
    
public:
    UMedKitComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TryFullHealWithNourishmentItems();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartMedkit(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable)
    void OnRadChanged(UHealthComponent* HealthComponentIn, float PrevNormalizedRad, float CurrNormalizedRad);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChanged(AIndianaCharacter* Character, bool bIsInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnAnimNotifyEvent(EAnimNotify AnimNotifyEvent, FName OptionalSocket);
    
    UFUNCTION(BlueprintCallable)
    void OnAbilityMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    
public:
    UFUNCTION(BlueprintCallable)
    bool HasNourishmentItem() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentToxicity() const;
    
    UFUNCTION(BlueprintCallable)
    void ConsumeBestNourishmentItem();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearCrash();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddToxicity(float NewToxicity);
    
};

