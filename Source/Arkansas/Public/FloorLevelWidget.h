#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FloorLevelWidget.generated.h"

class UImage;
class UWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFloorLevelWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* FloorImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CurrentFloorImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* QuestPresenceIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* PlayerLocationDisplay;
    
public:
    UFloorLevelWidget();

};

