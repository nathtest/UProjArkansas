#include "EnvQueryGenerator_Self.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

UEnvQueryGenerator_Self::UEnvQueryGenerator_Self() {
    this->ItemType = UEnvQueryItemType_Actor::StaticClass();
}


