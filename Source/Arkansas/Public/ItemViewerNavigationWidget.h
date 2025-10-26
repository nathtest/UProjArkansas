#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "Templates/SubclassOf.h"
#include "ItemViewerNavigationWidget.generated.h"

class UButtonBaseContainerWidget;
class UButtonGroup;
class UHorizontalBox;
class UInputLabelWidget;
class UInputWidget;
class UPaginatedButtonWidget;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UItemViewerNavigationWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPaginatedButtonWidget*> PaginatedButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UButtonBaseContainerWidget*> ContainerButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> Images;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> Labels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPaginatedButtonWidget> ButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UButtonBaseContainerWidget> EntryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UButtonGroup* CategoryButtonGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* LeftInputLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelWidget* RightInputLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputWidget* LeftInputWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputWidget* RightInputWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* ButtonContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowLooping;
    
public:
    UItemViewerNavigationWidget();

};

