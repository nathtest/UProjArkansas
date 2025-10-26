#include "EnvQueryGenerator_Cover.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

UEnvQueryGenerator_Cover::UEnvQueryGenerator_Cover() {
    this->ItemType = UEnvQueryItemType_Actor::StaticClass();
    this->SearchCenter = UEnvQueryContext_Querier::StaticClass();
    this->bUseOctree = true;
}


