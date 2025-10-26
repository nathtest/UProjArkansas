#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "GenericCollapsableList.h"
#include "TutorialList.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTutorialList : public UGenericCollapsableList {
    GENERATED_BODY()
public:
    UTutorialList();

    UFUNCTION(BlueprintCallable)
    void AddNewCompletedTutorial(const FGameplayTag& TutorialTag);
    
};

