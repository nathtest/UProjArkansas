#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RadialSectionWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URadialSectionWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdjustOpacityOnUnusableChanged;
    
public:
    URadialSectionWidget();

};

