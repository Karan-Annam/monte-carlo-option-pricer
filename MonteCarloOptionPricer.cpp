#include "MonteCarloOptionPricer.h"
#include "Option.h"
#include <cmath>
#include <iostream>
#include <vector>

MonteCarloOptionPricer::MonteCarloOptionPricer() 
    : generator(std::random_device{}()), dist(0.0, 1.0) {}


std::vector<double> MonteCarloOptionPricer::generate_price_path(const Option::Inputs& inputs){
    std::vector<double> ret_path;
    double S_curr = inputs.current_price;
    double dt = inputs.time_to_expiration/inputs.num_steps;

    ret_path.push_back(S_curr);

    for(int i = 0; i < inputs.num_steps; i++){
        double Z = dist(generator);
        S_curr = S_curr * exp((inputs.risk_free_rate - 0.5 * inputs.volatility * inputs.volatility) 
        * dt + inputs.volatility * sqrt(dt) * Z); 
        ret_path.push_back(S_curr);
    }

    return ret_path;
}


double MonteCarloOptionPricer::price_option(const Option& option, Option::Inputs& inputs){
    double avg_payoff = 0;

    for(int i = 0; i < inputs.num_simulations; i++){
        std::vector<double> path = MonteCarloOptionPricer::generate_price_path(inputs);
        avg_payoff += option.calculate_payoff(path);

        // Temporary progress indicator REMOVE/REPLACE LATER
        if(i % 1000 == 0){
            std::cout << (i/static_cast<double>(inputs.num_simulations)) * 100 << "% completed\r";
        }
    }
    avg_payoff = avg_payoff / inputs.num_simulations;

    double price = exp(-inputs.risk_free_rate * inputs.time_to_expiration) * avg_payoff;

    return price;
}

double MonteCarloOptionPricer::price_option(const Option& option){
    Option::Inputs inputs =  option.get_inputs();
    return MonteCarloOptionPricer::price_option(option, inputs);
}