#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"


//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "GameFrameWork\Character.h"

#include <GameplayTagContainer.h>
#include "PropComponents.h"
#include "Templates/SubclassOf.h"
#include "OwBaseCharacter.generated.h"

class UAIMovementComponent;
class UAkRtpc;
class UAnimSequenceBase;
class UAnimationAsset;
class UEquipmentComponent;
class UFactionData;
class UIndianaCharMovementComponent;
class ULocomotionLogicComponent;
class UNewPropData;
class USceneComponent;
class UTalkingIdleOverrideData;
class UWeapon;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API AOwBaseCharacter : public ACharacter, public IGenericTeamAgentInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTalkingIdleOverrideData* TalkingIdleOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPropComponents> IdleMeshProps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPropComponents> NonCombatMeshProps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPropComponents> ForeverProps;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* GroundOffsetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIndianaCharMovementComponent* IndianaCharacterMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIMovementComponent* AIMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULocomotionLogicComponent* LocomotionLogicComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CurrentProxySubState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderDepthOnlyDuringScanner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* InvisibleRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* BossRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreCorpseForDetection;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOptimizeMovementTicks;
    
public:
    AOwBaseCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SpawnScriptedProp(UAnimSequenceBase* Animation, UNewPropData* PropToSpawn, UAnimationAsset* PropAnimToPlay, bool bUseParentPosition);
    
    UFUNCTION(BlueprintCallable)
    void SetProxySubState(FGameplayTag PriorityTag, FGameplayTag DesiredSubState, FGameplayTag CurrentProxySubStateToCheck);
    
    UFUNCTION(BlueprintCallable)
    void OnMovementUpdated(float DeltaSeconds, FVector OldLocation, FVector OldVelocity);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGadgetDeactivateVisuals(FGameplayTag GameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetDeactivated(FGameplayTag GameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetActivated(FGameplayTag GameplayTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UFactionData> K2_GetFactionData() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCombat() const;
    
    UFUNCTION(BlueprintCallable)
    void HideProps();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEquipmentComponent* GetEquipmentComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeapon* GetCurrentWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAIMovementComponent* GetAIMovementComponent() const;
    

    // Fix for true pure virtual functions not being implemented
};

