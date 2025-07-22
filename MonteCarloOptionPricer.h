#ifndef MONTECARLOOPTIONPRICER_H
#define MONTECARLOOPTIONPRICER_H

#include "Option.h"
#include <random>
#include <cmath>
#include <vector>
#include <memory>

/*
    This pricer should perform the following things:
    1. Generate price paths for assets using Geometric Brownian Motion(GBM)
    2. Run Monte Carlo Simulation and call calculate_payoff for the options(takes pointer to Option class object)
    3. Calculate option price and relevant statistics
    4. Create option types(return pointer to Option class object)
    5. TBD: Implement variance reduction techniques like Antithetic Variates, Control Variates, etc.
    6. TBD: Allow parallelization for Monte Carlo simulation(implemented using threads or CUDA)
*/
class MonteCarloOptionPricer {
public:
    struct price_results{
        double price; 
        double stddev;
        double delta;
        double gamma;
        double theta;
        double vega;
        //double rho
        std::string option_type; 
    };

private:
    std::mt19937 generator;
    std::normal_distribution<double> dist;

    //generates a single price path using geometric brownian motion
    //outputs vector of pricer over time steps
    std::vector<double> generate_price_path(Option::Inputs& inputs, int num_steps);

public:
    MonteCarloOptionPricer();

    //prices an option using Monte Carlo simulation
    //uses the provided option object to calculate payoffs... uses included inputs
    double price_option(const Option& option, int num_steps, int num_sims);

    // if inputs are provided, they will be used to override the default values in the option
    double price_option(const Option& option, Option::Inputs& inputs, int num_steps, int num_sims);

    price_results calculate_greeks(const Option& option);

    //STILL NEED TO IMPLEMENT
    price_results price_option_with_stats(const Option& option);

};


#endif