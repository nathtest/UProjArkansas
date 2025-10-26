#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include <GameplayTagContainer.h>
#include "InterestStateTextures.h"
#include "PointOfInterestTextureData.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class UPointOfInterestTextureData : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FInterestStateTextures> POITagMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* TextureNotFound;
    
public:
    UPointOfInterestTextureData();

};

