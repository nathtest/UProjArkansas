#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
#include "ArmorModifier.h"
#include "ArmorModifierEntry.h"
#include "ArmorPiece.h"
#include "ArmorPieceEntry.h"
#include "CauseDamageInfo.h"
#include "ComponentDebugInterface.h"
#include "Templates/SubclassOf.h"
#include "ArmorComponent.generated.h"

class UArmorSet;
class USpell;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UArmorComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorPiece> InnateArmorValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag UnarmoredArmorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorModifier> InnateArmorModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorPieceEntry> EquippedArmor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArmorSet* EquippedArmorSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorModifierEntry> ArmorModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSelfRepairingArmor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelfRepairingArmorInitialDT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelfRepairingArmorDamageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelfRepairingArmorDTLoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelfRepairingArmorRecoveryTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> SelfRepairingArmorRegenSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> SelfRepairingArmorBreakSpell;
    
public:
    UArmorComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void TinkerAdvanceArmor(bool bIgnoreCost);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDamageEvent(const FCauseDamageInfo& CauseDamageInfo);
    

    // Fix for true pure virtual functions not being implemented
};

