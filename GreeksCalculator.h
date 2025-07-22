#ifndef GREEKS_CALCULATOR_H
#define GREEKS_CALCULATOR_H
#include "Option.h"
#include "MonteCarloOptionPricer.h"

namespace greeks {

    double calculate_delta(Option& option, MonteCarloOptionPricer& pricer, double calc_price);

    double calculate_gamma(Option& option, MonteCarloOptionPricer& pricer, double calc_price);

    double calculate_theta(Option& option);

    double calculate_vega(Option& option);

    double calculate_rho(Option& option);
}

#endif