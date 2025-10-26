#pragma once
#include "CoreMinimal.h"
#include "PrefabObjectPathEntry.h"
#include "PrefabricatorPolyDesc.h"
#include "PrefabricatorBrushBuilderData.generated.h"

class UPrefabricatorProperty;

USTRUCT(BlueprintType)
struct PREFABRICATORRUNTIME_API FPrefabricatorBrushBuilderData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ClassPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrefabObjectPathEntry ClassPathReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrefabricatorProperty*> Properties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPrefabricatorPolyDesc> Polys;
    
    FPrefabricatorBrushBuilderData();
};

