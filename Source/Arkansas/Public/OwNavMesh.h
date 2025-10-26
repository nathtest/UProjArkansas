#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box -FallbackName=Box
#include "NavMesh/RecastNavMesh.h"

#include "IslandConnectivityData.h"
#include "NavIslandConnection.h"
#include "OwNavMesh.generated.h"

class UCustomNavLinkRegistry;

UCLASS(Blueprintable)
class AOwNavMesh : public ARecastNavMesh {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNavIslandConnection> NavIslandConnectionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox NavIslandConnectionsBounds;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIslandConnectivityData IslandConnectivityData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomNavLinkRegistry* CustomNavLinkRegistryPtr;
    
public:
    AOwNavMesh(const FObjectInitializer& ObjectInitializer);

};

