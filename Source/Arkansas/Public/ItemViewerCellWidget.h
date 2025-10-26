#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemViewerCellWidget.generated.h"

class UItemViewerButtonWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UItemViewerCellWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemViewerButtonWidget* Button;
    
public:
    UItemViewerCellWidget();

};

