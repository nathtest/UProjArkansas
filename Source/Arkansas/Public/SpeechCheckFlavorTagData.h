#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <LocString.h>
#include "SpeechCheckFlavorTagData.generated.h"

UCLASS(Blueprintable)
class USpeechCheckFlavorTagData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString SpeechTagName;
    
    USpeechCheckFlavorTagData();

};

