#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "EHUDAdjustmentType.h"
#include "IndianaInterfaceUserWidget.h"
#include "Templates/SubclassOf.h"
#include "HUDAdjustorWidget.generated.h"

class UCanvasPanel;
class UGenericListButtonWidget;
class UHUDAdjustmentData;
class UHUDAdjustorSliderWidget;
class UHUDWidgetRepresentationWidget;
class UImage;
class UInputLabelGroupWidget;
class UScrollBox;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UHUDAdjustorWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UHUDAdjustorSliderWidget> SliderClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGenericListButtonWidget> DefaultsButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UHUDAdjustmentData* AdjustmentData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ResetToDefaultsText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EHUDAdjustmentType, FGameplayTag> AdjustmentUserSettingMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CountTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* DescTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* InputLabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ContainerCanvasPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* AdjustmentScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* SafeSpaceAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* HealthRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* LeftCompanion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* RightCompanion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* MinimapRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* QuestTrackerRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* NotificationsRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* EquipmentRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* AudioLogRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* RadioRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* LevelUpRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* NewAreaRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* EnemyScannerRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* ObservationRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* ReputationRepresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDWidgetRepresentationWidget* BountyRepresentation;
    
public:
    UHUDAdjustorWidget();

};

