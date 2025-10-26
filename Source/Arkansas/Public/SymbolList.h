#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ESymbolType.h"
#include "GenericCollapsableList.h"
#include "Templates/SubclassOf.h"
#include "SymbolList.generated.h"

class UIndianaDamageType;
class UMapCompassUIVisualData;
class USymbolDescriptionPanelEntry;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USymbolList : public UGenericCollapsableList {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESymbolType, FLocString> SymbolEntryNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USymbolDescriptionPanelEntry> SymbolEntryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapCompassUIVisualData* MapCompassVisualData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UIndianaDamageType>> DamageTypesData;
    
public:
    USymbolList();

};

