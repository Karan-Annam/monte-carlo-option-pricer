#include "Option.h"
#include "MonteCarloOptionPricer.h"
#include "EuropeanOptions.h"
#include <vector>
#include <iostream>

int main() {
    
    Option::Inputs inputs;
    inputs.current_price = 100.0; 
    inputs.strike_price = 100.0;   
    inputs.time_to_expiration = 1.0; 
    inputs.risk_free_rate = 0.05; 
    inputs.volatility = 0.2;       
    inputs.num_steps = 100;        
    inputs.num_simulations = 100000; 

    
    EuropeanCallOption call_option(inputs);
    
    MonteCarloOptionPricer pricer;

    double call_price = pricer.price_option(call_option);
    
    std::cout << "European Call Option Price: " << call_price << std::endl;

    return 0;
}
