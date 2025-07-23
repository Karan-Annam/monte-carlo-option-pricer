#include "Option.h"
#include "MonteCarloOptionPricer.h"
#include "EuropeanOptions.h"
#include "GreeksCalculator.h"
#include <vector>
#include <iostream>

int main() {
    
    Option::Inputs inputs;
    inputs.spot_price = 100.0; 
    inputs.strike_price = 100.0;   
    inputs.time_to_expiration = 1.0; 
    inputs.risk_free_rate = 0.05; 
    inputs.volatility = 0.2;       

    
    EuropeanCallOption call_option(inputs);
    
    MonteCarloOptionPricer pricer;

    double call_price = pricer.price_option(call_option, 252, 100000);

    std::cout << "European Call Option Price: " << call_price << std::endl;

    double delta = greeks::calculate_delta(call_option, pricer, call_price);
    
    std::cout << "Delta: " << delta << std::endl;

    return 0;
}
