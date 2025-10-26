#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GameplayTagContainer.h>
#include "Wire.generated.h"

class AWireBox;
class UMaterialInterface;
class UObsidianIDComponent;
class USplineComponent;
class UStaticMesh;

UCLASS(Blueprintable)
class ARKANSAS_API AWire : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* SplineMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPoweredOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<AWireBox>> LinkedWireBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
public:
    AWire(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void WireSetPower(bool bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetPower();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGadgetDeactivated(FGameplayTag GameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetActivated(FGameplayTag GameplayTag);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWireStateEquals(bool bCompare) const;
    
};

