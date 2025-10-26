#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AssetUserData -FallbackName=AssetUserData
#include <GameplayTagContainer.h>
#include "MapRendererFilterData.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMapRendererFilterData : public UAssetUserData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FilterCategories;
    
    UMapRendererFilterData();

};

