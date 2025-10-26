#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "Item.h"
#include "LogicalGroupedExpression.h"
#include "QuestItemOnInspectText.h"
#include "QuestItem.generated.h"

class UMaterialInterface;
class UObject;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UQuestItem : public UItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanAddToInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag QuestItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> ItemMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSoftObjectPtr<UMaterialInterface>> ItemMeshMaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalGroupedExpression LootableCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuestItemOnInspectText> GlobalSetOnExaminePairs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanAutoGiftIfUncollected;
    
public:
    UQuestItem();

};

