#include "Option.h"
#include "MonteCarloOptionPricer.h"
#include "EuropeanOptions.h"
#include <vector>
#include <iostream>

int main() {
    // Define inputs for the option
    Option::Inputs inputs;
    inputs.current_price = 100.0; // Current price of the underlying asset
    inputs.strike_price = 100.0;   // Strike price of the option
    inputs.time_to_expiration = 1.0; // Time to expiration in years
    inputs.risk_free_rate = 0.05;  // Risk-free interest rate
    inputs.volatility = 0.2;        // Volatility of the underlying asset
    inputs.num_steps = 100;         // Number of time steps in the simulation
    inputs.num_simulations = 10000; // Number of simulations

    // Create a European Call Option
    EuropeanCallOption call_option(inputs);

    // Create a Monte Carlo Option Pricer
    MonteCarloOptionPricer pricer;

    // Price the option using Monte Carlo simulation
    double call_price = pricer.price_option(call_option);
    
    std::cout << "European Call Option Price: " << call_price << std::endl;

    return 0;
}