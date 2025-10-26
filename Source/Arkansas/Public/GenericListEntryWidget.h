#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Slate -ObjectName=ETextJustify -FallbackName=ETextJustify
#include "IndianaUserWidget.h"
#include "GenericListEntryWidget.generated.h"

class UButtonBase;
class UImage;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UPanelWidget;
class UTextBlockBase;
class UTexture2D;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class UGenericListEntryWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString NameLocString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DescriptionLocString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDisplayMaximum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayMaximumValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayNameOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResizeValueIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETextJustify::Type> NameOnlyJustification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ValueParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ValueMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideValueMaterialIfEmpty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OversizeTextThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NameTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* ValuePanelWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* ValueTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* OversizedValueTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ValueIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ExtendedValueIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* ExtendedDisplay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CurrentValueMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CurrentExtendedValueMaterial;
    
public:
    UGenericListEntryWidget();

    UFUNCTION(BlueprintCallable)
    void SetNameTextFromString(const FString& NameAsString);
    
    UFUNCTION(BlueprintCallable)
    void SetNameText(const FLocString& NameAsLocString);
    
    UFUNCTION(BlueprintCallable)
    void SetDisplayNameOnly(bool bDisplayNameOnlyIn, bool bForceDisplayOverride);
    
    UFUNCTION(BlueprintCallable)
    void SetDescriptionTextFromLocString(const FLocString& DescLocString);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnValueTextSet(const FText& ValueTextApplied);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnValueIconSet(UTexture2D* IconApplied);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnNameTextSet(const FText& NameTextApplied);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOnDescriptionTextSet(const FText& DescriptionTextApplied);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLocString GetNameLocString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLocString GetDescriptionLocString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UButtonBase* GetButton() const;
    
    UFUNCTION(BlueprintCallable)
    void FontSizeModifierChanged(int32 ModifierIn);
    
};

