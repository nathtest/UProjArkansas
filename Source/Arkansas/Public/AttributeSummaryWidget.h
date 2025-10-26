#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttributeSummaryWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAttributeSummaryWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UAttributeSummaryWidget();

};

