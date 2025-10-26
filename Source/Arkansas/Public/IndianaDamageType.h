#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DamageType -FallbackName=DamageType
#include <LocString.h>
#include "EIndianaDamageType.h"
#include "Templates/SubclassOf.h"
#include "IndianaDamageType.generated.h"

class UNiagaraComponent;
class UParticleSystemComponent;
class URpgStat;
class USceneComponent;
class USpell;
class UStatusEffect;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API UIndianaDamageType : public UDamageType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaDamageType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeathPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* ReceiveDamageStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> DeathSpellStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> DeathSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> OnHitSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnHitSpellChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* SpellChanceStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> OnMaxStacksSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSpellStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSpellStacksResistant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RTPCName;
    
    UIndianaDamageType();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TriggerMuzzleFx(USceneComponent* AttachComponent, const FName& AttachSocket) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupImpactFx_OLD_Cascade(UParticleSystemComponent* ParentEffect, bool bCritical, bool bWeakSpot, bool bRadial, float Radius) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupImpactFx(UNiagaraComponent* ParentEffect, bool bCombined, int32 DamageFlags, float Radius) const;
    
};

