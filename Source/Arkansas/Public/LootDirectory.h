#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include <GameplayTagContainer.h>
#include "LootDirectoryFlavorEntry.h"
#include "LootDirectory.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API ULootDirectory : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FLootDirectoryFlavorEntry> FlavorEntries;
    
    ULootDirectory();

};

