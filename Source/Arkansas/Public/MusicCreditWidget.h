#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "MusicCreditWidget.generated.h"

class UInlineTitleWidget;
class UPanelWidget;
class UTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UMusicCreditWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInlineTitleWidget> SongCreditEntryWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* SongTitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* SongCreditList;
    
public:
    UMusicCreditWidget();

};

