#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttributeSummaryGroupWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAttributeSummaryGroupWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UAttributeSummaryGroupWidget();

};

