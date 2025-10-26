#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EIndianaUIColorType.h"
#include "IndianaUserWidget.h"
#include "ReputationEntryWidget.generated.h"

class UButtonBase;
class UImage;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UReputationEntryWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString KillOnSightStringRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaUIColorType KillOnSightRepColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NameTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* StatusTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ButtonFactionLogo;
    
public:
    UReputationEntryWidget();

};

