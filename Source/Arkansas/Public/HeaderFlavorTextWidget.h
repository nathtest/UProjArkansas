#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "HeaderFlavorTextWidget.generated.h"

class UFlavorTextWidget;
class UTextBlockBase;

UCLASS(Blueprintable, EditInlineNew)
class ARKANSAS_API UHeaderFlavorTextWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FLocString, FLocString> ScrollingHeaderFlavorMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* HeaderTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlavorTextWidget* FlavorTextWidget;
    
public:
    UHeaderFlavorTextWidget();

};

