#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "PrefabContainerInterface.h"
#include "PrefabricatorActorDeltaDesc.h"
#include "PrefabActor.generated.h"

class UPrefabComponent;
class UPrefabricatorAsset;

UCLASS(Blueprintable)
class PREFABRICATORRUNTIME_API APrefabActor : public AActor, public IPrefabContainerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrefabComponent* PrefabComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid LastUpdateID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FPrefabricatorActorDeltaDesc> InstanceDeltas;
    
    APrefabActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool SavePrefab();
    
    UFUNCTION(BlueprintCallable)
    void LoadPrefab();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrefabOutdated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPrefabricatorAsset* GetPrefabAsset() const;
    

    // Fix for true pure virtual functions not being implemented
};

