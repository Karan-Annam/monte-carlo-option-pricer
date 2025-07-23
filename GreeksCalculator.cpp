#include "GreeksCalculator.h"
#include <iostream>

/*
    Calculates delta of option using finite differences method for first order differential approximation
    Prices options for bumps up and down by bump_size
    Returns average of finite differences type shit
*/
double greeks::calculate_delta(Option& option, MonteCarloOptionPricer& pricer, double calc_price){
    Option::Inputs inputs = option.get_inputs();


    int num_bumps = 10;
    double bump_size = 0.01 * inputs.spot_price;
    double sum_finite_diff = 0;

    double temp = inputs.spot_price;

    for(int i = 1; i < num_bumps; i++){
        inputs.spot_price = temp + i * bump_size;
        double up_price = pricer.price_option(option, inputs, 100, 100000);

        inputs.spot_price = temp - i * bump_size;
        double down_price = pricer.price_option(option, inputs, 100, 100000);
        sum_finite_diff += (up_price - down_price) / (2 * i * bump_size);

        std::cout <<"path " << i << " completed" << std::endl;
    }

    return sum_finite_diff / num_bumps;
}

/*
    Calculates gamma of option using finite differences method for second order differential apx
    Returns average of finite differences type shit
*/
double greeks::calculate_gamma(Option& option, MonteCarloOptionPricer& pricer, double calc_price){
    Option::Inputs inputs = option.get_inputs();

    int num_bumps = 10;
    int bump_size = 0.01;
    double temp = inputs.spot_price;

    double sum_finite_diff = 0;

    for(int i = 0; i < num_bumps; i++){
        inputs.spot_price = temp + i * bump_size;
        double up_price = pricer.price_option(option, inputs, 100, 10000);
        inputs.spot_price = temp - i * bump_size;
        double down_price = pricer.price_option(option, inputs, 100, 10000);
        sum_finite_diff += (up_price - 2 * calc_price + down_price) / (bump_size * i * bump_size);
    }

    return sum_finite_diff / num_bumps;
}

