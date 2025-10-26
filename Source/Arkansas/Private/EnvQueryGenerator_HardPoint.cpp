#include "EnvQueryGenerator_HardPoint.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryGenerator_HardPoint::UEnvQueryGenerator_HardPoint() {
    this->SampleOriginContext = UEnvQueryContext_Querier::StaticClass();
    this->HardPointContext = UEnvQueryContext_Querier::StaticClass();
}


