#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include <GameplayTagContainer.h>
#include "FineAimBoneToggle.h"
#include "WeaponModBoneData.h"
#include "WeaponVisuals.h"
#include "PrimaryWeaponVisuals.generated.h"

class UCharacterAnimInstance;
class UReticleVisualsDataAsset;

UCLASS(Blueprintable)
class UPrimaryWeaponVisuals : public UWeaponVisuals {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReticleVisualsDataAsset* ReticleVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideAttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesAimOffsets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WeaponFineAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WeaponNormalAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldAddReticleOffsetToAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetFineAimAutomatically;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFineAimNormalizedStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponModBoneData> FineAimBoneData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCodeDrivenFineAimToggles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFineAimBoneToggle> FineAimInBoneToggles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFineAimBoneToggle> FineAimOutBoneToggles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCharacterAnimInstance> CharacterAnimInstance;
    
public:
    UPrimaryWeaponVisuals();

    UFUNCTION(BlueprintCallable)
    void DoBoneHideBP(FName BoneName, bool bVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ChargePhaseChangeBP(const TArray<FGameplayTagContainer>& TurnOffTags, const TArray<FGameplayTagContainer>& TurnOnTags);
    
};

