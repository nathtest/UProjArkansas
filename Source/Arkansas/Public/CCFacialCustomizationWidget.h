#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "BoneModificationUIWrapper.h"
#include "CCCharacterCustomizationBaseWdgt.h"
#include "CCFacialCustomizationWidget.generated.h"

class UBoneModifications;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCCFacialCustomizationWidget : public UCCCharacterCustomizationBaseWdgt {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBoneModifications*> BoneModifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAgeIntensityFirst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultComplexionIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFrecklesWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UBoneModifications*, FBoneModificationUIWrapper> BoneMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AgeCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString FrecklesCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString EyeDarkCircleCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ComplexionIntensityCategory;
    
public:
    UCCFacialCustomizationWidget();

};

