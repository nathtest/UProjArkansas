#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PaginatedButtonWidget.generated.h"

class UButtonBase;
class UImage;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UPaginatedButtonWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* SelectedIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
public:
    UPaginatedButtonWidget();

};

