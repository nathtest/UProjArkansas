#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=ETextCommit -FallbackName=ETextCommit
#include "EIndianaUIColorType.h"
#include "IndianaUserWidget.h"
#include "TextEntryWidget.generated.h"

class UEditableText;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UTextEntryWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEditableText* EditableTextField;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CapacityTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* BadNameWarning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CharacterMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CharacterMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString HintText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaUIColorType HintTextColor;
    
public:
    UTextEntryWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnTextfieldCommitted(const FText& Text, TEnumAsByte<ETextCommit::Type> CommitType);
    
    UFUNCTION(BlueprintCallable)
    void OnTextfieldChanged(const FText& Text);
    
};

