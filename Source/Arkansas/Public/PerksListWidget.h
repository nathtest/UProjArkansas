#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "PerksListWidget.generated.h"

class UPerksListRowWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UPerksListWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerksListRowWidget* RowOne;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerksListRowWidget* RowTwo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerksListRowWidget* RowThree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerksListRowWidget* RowFour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerksListRowWidget* RowFive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerksListRowWidget* RowSix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TextReference;
    
public:
    UPerksListWidget();

};

