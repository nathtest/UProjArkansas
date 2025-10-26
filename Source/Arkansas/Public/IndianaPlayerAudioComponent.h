#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <OEIWwiseEmitter.h>
#include "ECompanionCommand.h"
#include "EDetectionType.h"
#include "EPlayerAudioDetectionState.h"
#include "EPlayerAudioEvent.h"
#include "EUnlockAbility.h"
#include "EZyraniumType.h"
#include "IndianaAudioComponent.h"
#include "IndianaPlayerAudioComponent.generated.h"

class AActor;
class AIndianaCharacter;
class UAkPlaySoundEventEffect;
class UAkRtpc;
class UAkStateValue;
class UAkSwitchValue;
class UArmorType;
class UListenerPositioningSettings;
class UOEIWwiseObjectPoolWrapper;
class UPlayerMovementComponent;
class URpgStat;
class URpgStatComponent;
class UTravelRegionData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIndianaPlayerAudioComponent : public UIndianaAudioComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<EPlayerAudioEvent, UAkPlaySoundEventEffect*> PlayerAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerDetectionStateDangerToUndetectedEarlyTransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlayerAudioDetectionState, float> RequiredRequestTimes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallaCheckTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallaFarDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallaMediumDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallaNearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* WeaponSelectActiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* WeaponSelectInactiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* TTDActiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* TTDInactiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* StealthActiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* StealthInactiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* CalledShotActiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* CalledShotInactiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* KillCamActiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* KillCamInactiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* PlayerDetectionStateUndetectedStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* PlayerDetectionStateDangerStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* PlayerDetectionStateCombatStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* BerserkerStateActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* BerserkerStateInactive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* ZyraniumStateLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* ZyraniumStateHeavy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* ZyraniumStateEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UAkStateValue*> ArmorTagArmorTypeStateValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UTravelRegionData*, UAkStateValue*> RegionStateValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* DefaultRegionStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UArmorType*, UAkStateValue*> ArmorTypeStateValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* DefaultArmorTypeStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* PerspectiveFirstPersonStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* PerspectiveThirdPersonNearStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* PerspectiveThirdPersonFarStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* PerspectiveFirstPersonSwitchValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* PerspectiveThirdPersonNearSwitchValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* PerspectiveThirdPersonFarSwitchValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* StealthActiveSwitchValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkSwitchValue* StealthInactiveSwitchValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* FootstepVolumeRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* IsConversationRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* BattleHelmOfPteroBaneRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* RetroMarkOneRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* SuperRetroMarkTwoRTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WhizCategoryTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOEIWwiseObjectPoolWrapper* EmitterPoolWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UListenerPositioningSettings* FirstPersonListenerPositioningSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UListenerPositioningSettings* ThirdPersonNearListenerPositioningSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UListenerPositioningSettings* ThirdPersonFarListenerPositioningSettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOEIWwiseEmitter> WhizEmitters;
    
public:
    UIndianaPlayerAudioComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void TacticalTimeDilationStart();
    
    UFUNCTION(BlueprintCallable)
    void TacticalTimeDilationEnd(float Duration);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnUnlockAbilityChanged(EUnlockAbility Ability);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStealthChange(bool bStealthed);
    
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable)
    void OnSlideStarted(UPlayerMovementComponent* MovementComp);
    
    UFUNCTION(BlueprintCallable)
    void OnSlideEnded(UPlayerMovementComponent* MovementComp);
    
    UFUNCTION(BlueprintCallable)
    void OnLadderSlideStarted(UPlayerMovementComponent* MovementComp);
    
    UFUNCTION(BlueprintCallable)
    void OnLadderSlideEnded(UPlayerMovementComponent* MovementComp);
    
    UFUNCTION(BlueprintCallable)
    void OnKillCameraStart(const AActor* CameraTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnKillCameraEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnHazardOccupancyChange(AIndianaCharacter* Character, bool bInside, EZyraniumType ZyraniumType);
    
    UFUNCTION(BlueprintCallable)
    void OnDetectionChange(AActor* Detectee, EDetectionType DetectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionCommandCooldownEnd(ECompanionCommand Command, int32 CompanionIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChanged(AIndianaCharacter* InCharacter, bool bInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void GamePauseChanged(bool bPaused);
    
};

