#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "UniqueExaminableExaminedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUniqueExaminableExamined, FLocString, NameLocString, FLocString, DescriptionLocString);

