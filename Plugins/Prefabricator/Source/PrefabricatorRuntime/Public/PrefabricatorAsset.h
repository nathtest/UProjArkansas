#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include "PrefabricatorActorData.h"
#include "PrefabricatorAssetInterface.h"
#include "PrefabricatorAsset.generated.h"

class UThumbnailInfo;

UCLASS(Blueprintable)
class PREFABRICATORRUNTIME_API UPrefabricatorAsset : public UPrefabricatorAssetInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPrefabricatorActorData> ActorData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid LastUpdateID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UThumbnailInfo* ThumbnailInfo;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 Version;
    
    UPrefabricatorAsset();

};

