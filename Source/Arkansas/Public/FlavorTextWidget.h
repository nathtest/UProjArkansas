#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "FlavorTextWidget.generated.h"

class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFlavorTextWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* FlavorText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TextReference;
    
public:
    UFlavorTextWidget();

};

