#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "BaseHUDWidget.h"
#include "ItemStack.h"
#include "CharacterOverviewWidget.generated.h"

class UAnimatingProgressBarWidget;
class UInventoryComponent;
class UPanelWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCharacterOverviewWidget : public UBaseHUDWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantAnimateOnTempHealthZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag InhalerTutorialTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TutorialThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* VisibilityPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimatingProgressBarWidget* PlayerHealthBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimatingProgressBarWidget* PlayerBonusHealthBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimatingProgressBarWidget* PlayerShieldBar;
    
public:
    UCharacterOverviewWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnHealthItemConsumed(UInventoryComponent* InventoryComponent, const FItemStack& ItemStack);
    
};

