#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"

#include <GameplayTagContainer.h>
#include "AIPossessable.h"
#include "CauseDamageInfo.h"
#include "IndianaAIPerceptionComponent.generated.h"

class AActor;
class AIndianaAiCharacter;
class AIndianaCharacter;
class UAISenseConfig_Sight;
class URpgStat;
class URpgStatComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIndianaAIPerceptionComponent : public UAIPerceptionComponent, public IAIPossessable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAISenseConfig_Sight* OutOfCombatInteriorSightConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAISenseConfig_Sight* OutOfCombatExteriorSightConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAISenseConfig_Sight* InCombatSightConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InCombatHearingRangeScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutOfCombatInteriorHearingRangeScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutOfCombatExteriorHearingRangeScalar;
    
public:
    UIndianaAIPerceptionComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable)
    void OnPerceptionRangeScalarUpdated(const FGameplayTagContainer& CreatureType);
    
    UFUNCTION(BlueprintCallable)
    void OnGodVisionChanged(bool bGodVision);
    
    UFUNCTION(BlueprintCallable)
    void OnDormancyChanged(AIndianaAiCharacter* Character, bool bNewDormancy);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChanged(AIndianaCharacter* InCharacter, bool bIsInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterResurrected();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterDeath(AActor* Instigator, const FCauseDamageInfo& CauseDamageInfo);
    

    // Fix for true pure virtual functions not being implemented
};

