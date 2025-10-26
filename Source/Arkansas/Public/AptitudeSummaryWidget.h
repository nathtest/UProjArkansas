#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AptitudeSummaryWidget.generated.h"

class UButtonBase;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAptitudeSummaryWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* AptitudeTitleTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* AptitudeDescTextBlock;
    
public:
    UAptitudeSummaryWidget();

};

