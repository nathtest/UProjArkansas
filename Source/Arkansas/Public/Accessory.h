#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ArmorItem.h"
#include "Accessory.generated.h"

class UModAppearances;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAccessory : public UArmorItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UModAppearances* AccessoryVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCoversBeard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlendShapeToActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendShapeStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FaceRegionsThisCovers;
    
    UAccessory();

};

