#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "DragContainerWidget.generated.h"

class UDragDropOperation;
class UIndianaDragDropOperation;
class UNamedSlot;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UDragContainerWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UIndianaDragDropOperation> OperationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNamedSlot* NamedSlot;
    
public:
    UDragContainerWidget();

    UFUNCTION(BlueprintCallable)
    void OnOperationDrop(UDragDropOperation* Operation);
    
    UFUNCTION(BlueprintCallable)
    void OnOperationDragCancelled(UDragDropOperation* Operation);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnDragStarted(UIndianaDragDropOperation* Operation);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnDragGroupStarted(UIndianaDragDropOperation* Operation);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnDragGroupDrop(UIndianaDragDropOperation* Operation);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnDragGroupCancelled(UIndianaDragDropOperation* Operation);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnDragConfirmDrop(UIndianaDragDropOperation* Operation);
    
};

