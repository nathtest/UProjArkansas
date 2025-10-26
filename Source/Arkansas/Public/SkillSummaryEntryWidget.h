#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillSummaryEntryWidget.generated.h"

class UButtonBase;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USkillSummaryEntryWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* SkillNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* SkillLevelText;
    
public:
    USkillSummaryEntryWidget();

};

