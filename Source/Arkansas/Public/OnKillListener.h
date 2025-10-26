#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include "CauseDamageInfo.h"
#include "EDamageFlags.h"
#include "EIndianaDamageType.h"
#include "FactionListener.h"
#include "Templates/SubclassOf.h"
#include "OnKillListener.generated.h"

class AActor;
class UIndianaDamageType;
class UStatusEffect;

UCLASS(Blueprintable, EditInlineNew)
class UOnKillListener : public UFactionListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer WeaponCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAsh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStealthAttack;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageFlags DamageFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UIndianaDamageType> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRespectPreventRevival;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EIndianaDamageType> DamagedByTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
public:
    UOnKillListener();

protected:
    UFUNCTION(BlueprintCallable)
    void OnKillAsh(AActor* Killer, AActor* Victim, TSubclassOf<UIndianaDamageType> InDamageType, const FGameplayTag& InWeaponCategory) const;
    
    UFUNCTION(BlueprintCallable)
    void OnKill(AActor* Killer, AActor* Victim, const FCauseDamageInfo& CauseDamageInfo) const;
    
};

