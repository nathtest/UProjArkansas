#include "EnvQueryGenerator_FeetLocation.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Point.h"

UEnvQueryGenerator_FeetLocation::UEnvQueryGenerator_FeetLocation() {
    this->ItemType = UEnvQueryItemType_Point::StaticClass();
    this->QueryContext = UEnvQueryContext_Querier::StaticClass();
}


