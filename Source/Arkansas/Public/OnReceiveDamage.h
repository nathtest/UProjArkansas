#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "CauseDamageInfo.h"
#include "EBodyPartRegion.h"
#include "EDamageFlags.h"
#include "FactionListener.h"
#include "Templates/SubclassOf.h"
#include "OnReceiveDamage.generated.h"

class UAmmo;
class UIndianaDamageType;

UCLASS(Blueprintable, EditInlineNew)
class UOnReceiveDamage : public UFactionListener {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer WeaponTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UIndianaDamageType> DamageType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageFlags DamageFlag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UAmmo>> AmmoTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPassThroughDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PassThroughDamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequirePlayerIsDamageSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EBodyPartRegion> BodyPartRegions;
    
public:
    UOnReceiveDamage();

protected:
    UFUNCTION(BlueprintCallable)
    void OnDamageEvent(const FCauseDamageInfo& CauseDamageInfo);
    
};

