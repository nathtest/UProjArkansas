#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BackgroundPanelWidget.generated.h"

class UBorder;
class UButtonBase;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UBackgroundPanelWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* Border;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* BorderInner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> OuterTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> InnerTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerDefaultOpacity;
    
public:
    UBackgroundPanelWidget();

    UFUNCTION(BlueprintCallable)
    void RegisterButtons(const TArray<UButtonBase*> Buttons);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOuterTextureLoaded(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInnerTextureLoaded(UTexture2D* Texture);
    
};

