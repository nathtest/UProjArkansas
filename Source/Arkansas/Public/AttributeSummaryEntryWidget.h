#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttributeSummaryEntryWidget.generated.h"

class UButtonBase;
class UImage;
class UTextBlockBase;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAttributeSummaryEntryWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* AttributeNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* AttributeLevelText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> AttributeValueImages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ValueImage;
    
public:
    UAttributeSummaryEntryWidget();

};

