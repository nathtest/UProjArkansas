#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include <GameplayTagContainer.h>
#include "CharacterDeathDamageInfo.h"
#include "DeathComponent.h"
#include "Templates/SubclassOf.h"
#include "CharacterDeathComponent.generated.h"

class UAnimMontage;
class UAppearanceComponent;
class UCharacterDeathImpulse;
class UDeathClass;
class UDeathClassData;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USkeletalMeshComponent;
class UStaticMesh;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterDeathComponent : public UDeathComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterDeathDamageInfo DeathDamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* ReviveMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoHideWeaponOnDowned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoHideWeaponOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyDownedMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyDeathMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAshPileReceiveDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BodiesToCheckForCollision;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDeathClass* DeathClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDeathClass> DeathClassOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDeathClassData* DeathClassData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AshPileBodyPartTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UDeathClass>> ForbiddenDeathClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AshPileSpawnTraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCharacterDeathImpulse* DeathImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* OwnerMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAppearanceComponent* AppearanceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UClass* ChosenDownUClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDeathClass> ChosenDeathClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDeathClass> LastFatalDamageDeathClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowRagdoll;
    
public:
    UCharacterDeathComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StoreDeathImpact(FVector Impulse, FVector Location, FName BoneName);
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* SpawnAshPile(UStaticMesh* Mesh, UMaterialInterface* LootablePileMaterial, FVector& SpawnedPileLocation, FRotator& SpawnedPileRotation);
    
    UFUNCTION(BlueprintCallable)
    void RagdollCharacter(bool bIgnoreDeathMontages);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    
public:
    UFUNCTION(BlueprintCallable)
    void HideProps();
    
    UFUNCTION(BlueprintCallable)
    void HideAppearanceMeshes();
    
    UFUNCTION(BlueprintCallable)
    void GibCharacter();
    
    UFUNCTION(BlueprintCallable)
    void DetachImpactFx();
    
    UFUNCTION(BlueprintCallable)
    FVector CalcImpactVector();
    
    UFUNCTION(BlueprintCallable)
    void BreakBone();
    
    UFUNCTION(BlueprintCallable)
    void BreakAllBones();
    
    UFUNCTION(BlueprintCallable)
    void AttachGoreCaps();
    
    UFUNCTION(BlueprintCallable)
    void AttachAllGoreCaps();
    
};

