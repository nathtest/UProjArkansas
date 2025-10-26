#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "MaterialIndexTargets.h"
#include "AnimNotifyState_NRayDissolve.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UAnimNotifyState_NRayDissolve : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialIndexTargets DynamicMaterialTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialIndexTargets InvisibilityMaterialTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialIndexTargets> ResolveMaterialTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDissolve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DissolveParameter;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* Mid;
    
public:
    UAnimNotifyState_NRayDissolve();

};

