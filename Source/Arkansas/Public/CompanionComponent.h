#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GlobalVariableReference.h>
#include <LocString.h>
#include "AIPossessable.h"
#include "CompanionCommandDelegateDelegate.h"
#include "ECompanionCommand.h"
#include "ESkill.h"
#include "ESpecialObsidianID.h"
#include "OnCompanionUpgradeDelegate.h"
#include "Templates/SubclassOf.h"
#include "CompanionComponent.generated.h"

class AActor;
class AElevator;
class AIndianaCharacter;
class UAIGroupBehavior_CompanionCombatAbilityCommandBase;
class UAnimMontage;
class UCalledShotData;
class UCompanionAbility;
class UCompanionFactionRelationshipData;
class UCompanionMoraleEvent;
class UCompanionUpgradeData;
class UEnvironmentInteractionComponent;
class UItemMod;
class USpell;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCompanionComponent : public UActorComponent, public IAIPossessable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CompanionPortrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CompanionPortraitRichTag;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysMatchWeaponsAndArmorToCharacterLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference DismissGlobalVariable;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompanionCommandDelegate OnCompanionCommandDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCalledShotData* CalledShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCompanionAbility> CompanionAbilityClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCompanionAbility* CompanionAbility;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCompanionUpgrade OnCompanionUpgrade;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCompanionUpgradeData* CompanionUpgradeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ESkill> TaggedSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkillCheckPercentToPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelsPerSkillIncrease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SkillIncreaseAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCompanionMoraleEvent*> MoraleEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> InterruptionMontages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString WeaponPreferenceDescText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCompanionFactionRelationshipData* CompanionFactionRelationshipData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> OutOfPartySpell;
    
public:
    UCompanionComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateCompanionState(ESpecialObsidianID SpecialObsidianID);
    
    UFUNCTION(BlueprintCallable)
    void SetCompanionMoving(const bool bInMoving);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerExitedAcknowledgeZone(AActor* ZoneOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerEnteredAcknowledgeZone(AActor* ZoneOwner);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnOccupiedElevatorStop(UEnvironmentInteractionComponent* EnvironmentComponent, AElevator* Elevator);
    
    UFUNCTION(BlueprintCallable)
    void OnOccupiedElevatorMove(UEnvironmentInteractionComponent* EnvironmentComponent, AElevator* Elevator);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNavigationPathUpdated();
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChange(AIndianaCharacter* InCharacter, bool bIsInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCanBeStealthed(const bool bEnable);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInOrNearCrouchArea() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetCompanionCommandMaxChargeCount(ECompanionCommand Command) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCombatAbilityCommandCooldownTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCombatAbilityCommandCooldownDrainTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<UAIGroupBehavior_CompanionCombatAbilityCommandBase> GetCombatAbilityCommandBehaviorClass() const;
    
    UFUNCTION(BlueprintCallable)
    void ApplyCompanionModUpgrade(UItemMod* ItemMod);
    

    // Fix for true pure virtual functions not being implemented
};

