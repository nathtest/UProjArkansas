#include "EnvQueryTest_NavmeshConnectivity.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_NavmeshConnectivity::UEnvQueryTest_NavmeshConnectivity() {
    this->TestPurpose = EEnvTestPurpose::Filter;
    this->FilterType = EEnvTestFilterType::Match;
    this->ScoringEquation = EEnvTestScoreEquation::Constant;
    this->DestinationContext = UEnvQueryContext_Querier::StaticClass();
    this->PatherContext = UEnvQueryContext_Querier::StaticClass();
    this->bCheckNavLinks = true;
    this->bCheckElevators = false;
}


