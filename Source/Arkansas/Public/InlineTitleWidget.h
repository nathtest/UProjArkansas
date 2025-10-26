#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InlineTitleWidget.generated.h"

class UTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UInlineTitleWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* RoleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* NameText;
    
public:
    UInlineTitleWidget();

};

