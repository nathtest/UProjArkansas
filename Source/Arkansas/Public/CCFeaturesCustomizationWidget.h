#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "CCCharacterCustomizationBaseWdgt.h"
#include "CCFeaturesCustomizationWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCCFeaturesCustomizationWidget : public UCCCharacterCustomizationBaseWdgt {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString CheekMakeupCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString EyelinerMakeupCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString EyeshadowMakeupCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString LipMakeupCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DirtCategory;
    
public:
    UCCFeaturesCustomizationWidget();

};

