#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "CheckboxWithText.generated.h"

class UImage;
class UOWRichTextBlockBase;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class ARKANSAS_API UCheckboxWithText : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString CheckedDisplayString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString UncheckedDisplayString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> SuccessTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> FailTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CheckboxBorderImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CheckboxMarkImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOWRichTextBlockBase* TextBlock;
    
public:
    UCheckboxWithText();

};

