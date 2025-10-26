#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "StatsSummaryPageWidget.generated.h"

class UAptitudeSummaryWidget;
class UCharacterDescriptionPanel;
class UFlavorTextWidget;
class UGenericListEntryWidget;
class UInputLabelGroupWidget;
class UPlayerStatSummary;
class UStatusEffectEntryWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UStatsSummaryPageWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ToxicityNameString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ZyraniumExposureNameString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideZyraniumOnZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlavorTextWidget* FlavorTextWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* InputLabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAptitudeSummaryWidget* AptitudeSummary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerStatSummary* CharacterStatSummary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterDescriptionPanel* DescriptionPanel;
    
public:
    UStatsSummaryPageWidget();

private:
    UFUNCTION(BlueprintCallable)
    void OnStatusEffectItemHoveredFocused(const UStatusEffectEntryWidget* StatusEffectItem);
    
    UFUNCTION(BlueprintCallable)
    void OnStatItemHoveredFocused(UGenericListEntryWidget* StatItem);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAptitudeHoveredFocused();
    
};

