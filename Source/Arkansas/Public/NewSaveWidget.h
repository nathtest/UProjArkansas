#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NewSaveWidget.generated.h"

class UButtonBase;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UNewSaveWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NewSaveText;
    
public:
    UNewSaveWidget();

};

