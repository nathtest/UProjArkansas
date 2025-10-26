#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=ESelectInfo -FallbackName=ESelectInfo
#include "Blueprint/UserWidget.h"
#include "QuestLogComboBoxWidget.generated.h"

class UComboBoxStringBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UQuestLogComboBoxWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UComboBoxStringBase* ComboBox;
    
public:
    UQuestLogComboBoxWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnValueChanged(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSortOptionIncrement();
    
};

