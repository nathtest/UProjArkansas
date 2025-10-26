#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box -FallbackName=Box
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavRelevantInterface -FallbackName=NavRelevantInterface
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavigationDataChunkActor -FallbackName=NavigationDataChunkActor
#include "WorldPartition/NavigationData/NavigationDataChunkActor.h"

#include "OwNavigationDataChunkActor.generated.h"

class UNavMeshCustomNavLinkCollection;

UCLASS(Blueprintable)
class ARKANSAS_API AOwNavigationDataChunkActor : public ANavigationDataChunkActor, public INavRelevantInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UNavMeshCustomNavLinkCollection*> NavLinkCollections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox NavDataQueryBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox NavDataTileBounds;
    
public:
    AOwNavigationDataChunkActor(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

