#pragma once
#include "CoreMinimal.h"
#include "Animation\AnimMetaData.h"

#include "OverrideRotationSpeedAnimMetaData.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOverrideRotationSpeedAnimMetaData : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRotationSpeed;
    
    UOverrideRotationSpeedAnimMetaData();

};

