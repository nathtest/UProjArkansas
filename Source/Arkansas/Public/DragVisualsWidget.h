#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DragVisualsWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UDragVisualsWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UDragVisualsWidget();

};

