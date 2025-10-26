#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "IntraPrefabReference.h"
#include "PrefabObjectPathEntry.h"
#include "PrefabricatorProperty.generated.h"

UCLASS(Blueprintable, DefaultToInstanced)
class PREFABRICATORRUNTIME_API UPrefabricatorProperty : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PropertyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ExportedValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPrefabObjectPathEntry> ExportedObjectReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntraPrefabReference> IntraPrefabReferences;
    
    UPrefabricatorProperty();

};

