#include "EnvQueryGenerator_JitterGrid.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryGenerator_JitterGrid::UEnvQueryGenerator_JitterGrid() {
    this->GenerateAround = UEnvQueryContext_Querier::StaticClass();
}


