#pragma once
#include "CoreMinimal.h"
#include "NavAreas/NavArea.h"
#include "NavArea_NavLinkBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API UNavArea_NavLinkBase : public UNavArea {
    GENERATED_BODY()
public:
    UNavArea_NavLinkBase();

};

