#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemInspectorStatWidget.generated.h"

class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UItemInspectorStatWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* StatTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* StatValueTextBlock;
    
    UItemInspectorStatWidget();

};

