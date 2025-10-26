#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EventListener.h"
#include "Templates/SubclassOf.h"
#include "OnPlayerInCombatWith.generated.h"

class AIndianaCharacter;
class UFactionData;

UCLASS(Blueprintable, EditInlineNew)
class UOnPlayerInCombatWith : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFactionData> FactionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertFactionRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CreatureType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
public:
    UOnPlayerInCombatWith();

protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerInCombatWith(AIndianaCharacter* Character, bool bAdded);
    
};

