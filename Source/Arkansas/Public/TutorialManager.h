#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <GameplayTagContainer.h>
#include "CauseDamageInfo.h"
#include "ESkill.h"
#include "EXPGainReason.h"
#include "ItemStack.h"
#include "TutorialManager.generated.h"

class AActor;
class AIndianaAiCharacter;
class AIndianaCharacter;
class ARestrictedArea;
class UCharacterInfoComponent;
class UEquipmentComponent;
class UHealthComponent;
class UIndianaCharMovementComponent;
class UInventoryComponent;
class UQuestItem;
class UWeapon;

UCLASS(Abstract, Blueprintable)
class UTutorialManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ESkill> DialogueSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TutorialLogDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UQuestItem> ShroudItem;
    
public:
    UTutorialManager();

    UFUNCTION(BlueprintCallable)
    static void ShowTutorialMessage(const FGameplayTag& TutorialTag, bool bShowOncePerSession, bool bInfiniteDuration);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayerTargetChange(const bool bAdded);
    
    UFUNCTION(BlueprintCallable)
    void PlayerTakeDamage(const FCauseDamageInfo& CauseDamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void PlayerSkillUpdated(UCharacterInfoComponent* InCharacterInfoComponent, ESkill Skill, int32 NewValue);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayerSkillCheckSuccess(EXPGainReason Reason, int32 XPEarned, ESkill SkillUsed);
    
    UFUNCTION(BlueprintCallable)
    void PlayerMedKitUsed();
    
public:
    UFUNCTION(BlueprintCallable)
    void PlayerLevelChanged(int32 NewLevel);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayerLanded(UIndianaCharMovementComponent* InMovementComponent, float DistanceFell);
    
    UFUNCTION(BlueprintCallable)
    void PlayerKill(AActor* Killer, AActor* Victim, const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void PlayerItemAdded(UInventoryComponent* InventoryComponent, const FItemStack& Item);
    
    UFUNCTION(BlueprintCallable)
    void PlayerHealthChanged(UHealthComponent* InHealthComponent, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void PlayerFinishedEquipping(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEnteredRestrictedArea(const ARestrictedArea* RestrictedArea);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEncumberedChanged(bool bEncumbered);
    
    UFUNCTION(BlueprintCallable)
    void PlayerCompanionKilled(AActor* Companion);
    
public:
    UFUNCTION(BlueprintCallable)
    void PlayerCompanionAdded(AIndianaAiCharacter* NPC, bool bRegister);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayerCombatStateChanged(AIndianaCharacter* InCharacter, bool bIsInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void PlayerCausedDamage(const FCauseDamageInfo& CauseDamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    static void MarkTutorialComplete(const FGameplayTag& TutorialTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsTutorialCompleted(const FGameplayTag& TutorialTag);
    
    UFUNCTION(BlueprintCallable)
    static void HideTutorialMessage(const FGameplayTag& TutorialTag);
    
    UFUNCTION(BlueprintCallable)
    static void HideIncompleteTutorial(const FGameplayTag& TutorialTag);
    
};

