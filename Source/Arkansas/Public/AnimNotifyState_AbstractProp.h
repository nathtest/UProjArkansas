#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_AbstractProp.generated.h"

class UAnimMontage;
class UAnimationAsset;
class UNewPropData;
class USkeletalMeshComponent;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_AbstractProp : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNewPropData* LoadedPropDataToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PropDespawnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* PropAnimToPlay;
    
    UAnimNotifyState_AbstractProp();

protected:
    UFUNCTION(BlueprintCallable)
    void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted, USkeletalMeshComponent* MeshComp) const;
    
};

