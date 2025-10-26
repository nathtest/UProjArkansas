#pragma once
#include "CoreMinimal.h"
#include "PrefabricatorComponentDeltaDesc.generated.h"

USTRUCT(BlueprintType)
struct PREFABRICATORRUNTIME_API FPrefabricatorComponentDeltaDesc {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FString> ModifiedProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FString> ModifiedSubobjectPropertyPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTransformModified;
    
    FPrefabricatorComponentDeltaDesc();
};

