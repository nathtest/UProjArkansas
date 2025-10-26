#include "EnvQueryTest_HardPointV2.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_HardPointV2::UEnvQueryTest_HardPointV2() {
    this->TestPurpose = EEnvTestPurpose::Filter;
    this->FilterType = EEnvTestFilterType::Match;
    this->ScoringEquation = EEnvTestScoreEquation::Constant;
    this->Context = UEnvQueryContext_Querier::StaticClass();
}


