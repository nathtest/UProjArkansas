#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include "ArmorData.h"
#include "ArmorItem.h"
#include "ArmorVisualProperties.h"
#include "EHeadStyle.h"
#include "Helmet.generated.h"

class UModAppearances;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UHelmet : public UArmorItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHeadStyle HeadStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UModAppearances* HelmetVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorVisualProperties VisualProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorData Armor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FaceRegionsThisCovers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag VoicePostProcessOverride;
    
public:
    UHelmet();

};

