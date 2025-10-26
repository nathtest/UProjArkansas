#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AssetUserData -FallbackName=AssetUserData
#include "PrefabricatorAssetUserData.generated.h"

class APrefabActor;

UCLASS(Blueprintable, EditInlineNew)
class PREFABRICATORRUNTIME_API UPrefabricatorAssetUserData : public UAssetUserData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<APrefabActor> PrefabActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ItemId;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<APrefabActor> PrefabActor_Duplicated;
    
public:
    UPrefabricatorAssetUserData();

};

