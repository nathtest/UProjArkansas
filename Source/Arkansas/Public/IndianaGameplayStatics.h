#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EAttachLocation -FallbackName=EAttachLocation
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EVisibilityBasedAnimTickOption -FallbackName=EVisibilityBasedAnimTickOption
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ScalarParameterValue -FallbackName=ScalarParameterValue
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=VectorParameterValue -FallbackName=VectorParameterValue
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include "ConversationReference.h"
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "BlueprintAssetLoadCompleteDelegate.h"
#include "BlueprintAssetsLoadedCompleteDelegate.h"
#include "DamageDescription.h"
#include "EAlertState.h"
#include "EBlueprintLogVerbosity.h"
#include "ECheckBranches.h"
#include "EEventEffectFloatParams.h"
#include "EMeshPerspective.h"
#include "EMeshTarget.h"
#include "ETogglableAction.h"
#include "EventEffectParams.h"
#include "IndianaDamageEvent.h"
#include "IndianaDamageTarget.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "IndianaGameplayStatics.generated.h"

class AActor;
class AIndianaAiCharacter;
class AIndianaCharacter;
class AIndianaPlayerStart;
class AOwBaseCharacter;
class ARestrictedArea;
class UActorComponent;
class UBlendSpace;
class UBodyIdleAsset;
class UCameraPostProcessingAsset;
class UChildActorComponent;
class UDamageType;
class UDataLayerAsset;
class UDataLayerInstance;
class UDialogBoxWidget;
class UFXSystemComponent;
class UGameCalendar;
class UItem;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMeshComponent;
class UObject;
class UParticleSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMesh;
class UWeapon;

UCLASS(Blueprintable)
class UIndianaGameplayStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UIndianaGameplayStatics();

    UFUNCTION(BlueprintCallable)
    static UMaterialInstanceDynamic* VFXMID(USceneComponent* SceneComponent, TArray<FScalarParameterValue> ScalarParamValues, TArray<FVectorParameterValue> VectorParamValues, int32 MatIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UpdateAndFlushStreaming(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float UndilateTime(UObject* ContextObject, float DilatedTime);
    
    UFUNCTION(BlueprintCallable)
    static void TeleportPlayerToStart(AIndianaPlayerStart* PlayerStart);
    
    UFUNCTION(BlueprintCallable)
    static bool SuicideActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static UParticleSystemComponent* SpawnPooledEmitterAttached(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, TEnumAsByte<EAttachLocation::Type> LocationType);
    
    UFUNCTION(BlueprintCallable)
    static UParticleSystemComponent* SpawnPooledEmitterAtLocation(UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale);
    
    UFUNCTION(BlueprintCallable)
    static void SetParticleSystemEmittersEnabled(UFXSystemComponent* ParticleSystem, const TArray<FName>& EnabledEmitters, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetMoveIgnoreComponentCollision(AActor* Actor, UPrimitiveComponent* ComponentToIgnore, bool bIgnore);
    
    UFUNCTION(BlueprintCallable)
    static void SetMoveIgnoreActorCollision(AActor* ActorA, AActor* ActorB, bool bIgnore);
    
    UFUNCTION(BlueprintCallable)
    static void SetIndianaActorPseudoGod(AActor* Actor, bool bPseudoGodMode);
    
    UFUNCTION(BlueprintCallable)
    static void SetIndianaActorInteractable(AActor* Actor, bool bInteractable);
    
    UFUNCTION(BlueprintCallable)
    static void SetIndianaActorGod(AActor* Actor, bool bGodMode);
    
    UFUNCTION(BlueprintCallable)
    static void SetFPVCameraFOV(bool bOverrideCustomFOV);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetEnableWorldRendering(const UObject* WorldContextObject, bool bEnable, bool bUpdateRenderTimeWhileDisabled);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDataLayerStreamingCritical(const UObject* WorldContextObject, const UDataLayerAsset* InDataLayerAsset);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDataLayerNonStreamingCritical(const UObject* WorldContextObject, const UDataLayerAsset* InDataLayerAsset);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDataLayerInstanceStreamingCritical(const UObject* WorldContextObject, const UDataLayerInstance* InDataLayerInstance);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDataLayerInstanceNonStreamingCritical(const UObject* WorldContextObject, const UDataLayerInstance* InDataLayerInstance);
    
    UFUNCTION(BlueprintCallable)
    static void SetAnimTickOptionOnActorMeshes(AActor* Actor, EVisibilityBasedAnimTickOption TickOption);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RequestVirtualTexturePreload(const UObject* WorldContextObject, const UMaterialInterface* Material, const FVector2D& InScreenSpaceSize);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PrefetchNaniteResource(const UObject* WorldContextObject, const UStaticMesh* StaticMesh, const int32 FramesUntilUse);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void K2_ApplyDamage(AActor* DamageCauser, AActor* DamagedActor, FDamageDescription DamageDescription);
    
    UFUNCTION(BlueprintCallable)
    static bool IsWorldPointInView(const FVector& WorldPoint);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsWeaponSpinningUp(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsWeaponSpinningDown(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    static bool IsRunningAutomationTest(EBoolResult& Result);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestActive(FGuid QuestID, EBoolResult& Result);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerTrespassingInRestrictedArea_BP(const AOwBaseCharacter* FilterCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerInRestrictedAreaBufferVolume(const AIndianaAiCharacter* FilterCharacter, ARestrictedArea*& OutOwningRestrictedArea);
    
    UFUNCTION(BlueprintCallable)
    static bool IsItemStackOfClass(const FItemStack& ItemStack, TSubclassOf<UItem> ItemType, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsItemOfClass(const UItem* Item, TSubclassOf<UItem> ItemType, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCurrentWeaponAmmoPoolEmpty(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    static bool IsConversationActive(const FConversationReference& ConversationReference);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCombatAlertState(EAlertState AlertState);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCharacterInAnyBarkConversation(AIndianaCharacter* Character, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCharacterDead(const AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool IsBarkConversationActive();
    
    UFUNCTION(BlueprintCallable)
    static bool IsActionEnabled(AActor* Actor, ETogglableAction Action);
    
    UFUNCTION(BlueprintCallable)
    static void InheritMeshProperties(const UMeshComponent* ParentMesh, UMeshComponent* ChildMesh);
    
    UFUNCTION(BlueprintCallable)
    static void IndianaCancelAsyncLoadAsset(int32 Handle);
    
    UFUNCTION(BlueprintCallable)
    static void IndianaAsyncLoadAssets(TArray<TSoftObjectPtr<UObject>> Assets, int32 Priority, const FBlueprintAssetsLoadedComplete& Callback, int32& HandleOut);
    
    UFUNCTION(BlueprintCallable)
    static void IndianaAsyncLoadAsset(TSoftObjectPtr<UObject> Asset, int32 Priority, const FBlueprintAssetLoadComplete& Callback, int32& HandleOut);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponSpinUpDuration(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponSpinDownDuration(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    static USkeletalMeshComponent* GetWeaponMeshComponent(const UWeapon* Weapon, EMeshPerspective Perspective);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentSpinUpProgress(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentSpinDownProgress(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentRampTimer(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentRampSpeed(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentCharge(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentAnimCharge(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponCurrentAimProgress(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetWeaponBeamLockProgress(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    static USkeletalMeshComponent* GetSkeletalMeshComponent(const AActor* TargetActor, EMeshTarget MeshType, EMeshPerspective Perspective);
    
    UFUNCTION(BlueprintCallable)
    static UMeshComponent* GetMeshComponent(const AActor* TargetActor, EMeshTarget MeshType, EMeshPerspective Perspective);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UBodyIdleAsset*> GetGestureLibraryIdles();
    
    UFUNCTION(BlueprintCallable)
    static TArray<UBodyIdleAsset*> GetGestureLibraryGesturesForIdle(UBodyIdleAsset* IdleSequence);
    
    UFUNCTION(BlueprintCallable)
    static UGameCalendar* GetGameCalendar();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TEnumAsByte<EPhysicalSurface> GetEventEffectPhysicalSurface(const FEventEffectParams& Params);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetEventEffectParam(const FEventEffectParams& Params, EEventEffectFloatParams Param);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FName> GetEventEffectEnabledEmitters(const FEventEffectParams& Params);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetEntitlementAvailability(const UObject* WorldContextObject, const FGameplayTag& Entitlement);
    
    UFUNCTION(BlueprintCallable)
    static float GetBlendSpaceLength(const UBlendSpace* BlendSpace);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FGameplayTag> GetAllAvailableEntitlements(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void GetAllAppearanceRelatedMeshes(AActor* Actor, TArray<UMeshComponent*>& Meshes, bool bIncludeWeapon);
    
    UFUNCTION(BlueprintCallable)
    static void GetAllAppearanceAndWeaponMeshes(AActor* Actor, TArray<UMeshComponent*>& ApperanceMeshes, TArray<UMeshComponent*>& WeaponMeshes);
    
    UFUNCTION(BlueprintCallable)
    static AActor* GetActorBySpeakerName(ECheckBranches& Branches, FGuid SpeakerReference);
    
    UFUNCTION(BlueprintCallable)
    static USceneComponent* FindFirstChildComponentByTag(ECheckBranches& Branches, USceneComponent* ParentComponent, FName Tag);
    
    UFUNCTION(BlueprintCallable)
    static bool FindChildComponentsByTag(USceneComponent* ParentComponent, FName Tag, TArray<USceneComponent*>& ChildComponents);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool ExecuteRemoteEvent(const UObject* WorldContextObject, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static void EnableParticleSystemEmitters(UFXSystemComponent* ParticleSystem, const TArray<FName>& EnabledEmitters);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float DilateTime(UObject* ContextObject, float UndilatedTime);
    
    UFUNCTION(BlueprintCallable)
    static UDialogBoxWidget* CreateEndGameDialogWidget(const FLocString& BodyLocString);
    
    UFUNCTION(BlueprintCallable)
    static UDialogBoxWidget* CreateDialogWidget(const FLocString& BodyLocString, bool bCancellable);
    
    UFUNCTION(BlueprintCallable)
    static float ConvertFOV(float FOVIn, bool bConvertToVertical);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* ConstructComponentByClass(ECheckBranches& Branches, UObject* InOuter, UClass* InClass);
    
    UFUNCTION(BlueprintCallable)
    static void ClearPlayerCombat();
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllTargetsAndAwareness(AIndianaAiCharacter* InAICharacter);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllMoveIgnoreActorsFor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ClassIsChildOfWeakRef(UClass* TestClass, TSoftClassPtr<UObject> ParentClass);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static bool BP_ApplyDamage(AActor* DamageCauser, const FDamageDescription& DamageDescription, const FIndianaDamageEvent& IndianaDamageEvent, FIndianaDamageTarget DamageTarget, AActor* Instigator, bool bTriggerImpacts);
    
protected:
    UFUNCTION(BlueprintCallable)
    static void BlueprintLog(const FString& Category, EBlueprintLogVerbosity Verbosity, const FString& Message);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void ApplyGenericDamage(AActor* DamageCauser, AActor* DamagedActor, float BaseDamage, TSubclassOf<UDamageType> DamageType, bool bUseCustomDamageDescription, FDamageDescription CustomDamageDescription);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyCameraPostProcessing(UCameraPostProcessingAsset* PostProcessingAsset, FVector SourcePosition);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyCACVisibilityToActorCollision(UChildActorComponent* CAC);
    
};

