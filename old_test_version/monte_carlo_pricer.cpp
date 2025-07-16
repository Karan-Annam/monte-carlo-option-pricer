#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include "monte_carlo_pricer.h"


class monte_carlo_pricer{
public:
    
    Prices euro_monte_carlo_price(Inputs& input);
};


int main(void){
    Inputs input;
    Prices prices;
    std::cout << "Enter input params in the order time_to_expiry, volatility, risk_free_rate, current_price, strike_price" << std::endl;
    std::vector<double> userinput;
    for(int i = 0; i < 5; i++){
        double curr;
        std::cin >> curr;
        userinput.push_back(curr);
    }
    input.time_to_expiration = userinput[0];
    input.volatility = userinput[1];   
    input.risk_free_rate = userinput[2];
    input.current_price = userinput[3];
    input.strike_price = userinput[4];

    prices = euro_monte_carlo_price(input);

    std::cout << "Call Option Price: " << prices.call_option_price << std::endl;
    std::cout << "Put Option Price: " << prices.put_option_price << std::endl;

    return 0;
}

Prices euro_monte_carlo_price(Inputs& inputs){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::normal_distribution<> dist(0.0, 1.0); 

    Prices ret_price;
    
    double sum_call_option_payoffs = 0.0;
    double sum_put_option_payoffs = 0.0;

    for (int i = 0; i < num_samples; i++){
        double normal_sample = dist(gen);
        double S_T = inputs.current_price * exp((inputs.risk_free_rate - 0.5 * inputs.volatility * inputs.volatility) 
        * inputs.time_to_expiration + inputs.volatility * sqrt(inputs.time_to_expiration) * normal_sample);

        double call_option_payoff = std::max(S_T - inputs.strike_price, 0.0);
        double put_option_payoff = std::max(inputs.strike_price - S_T, 0.0);

        sum_call_option_payoffs += call_option_payoff;
        sum_put_option_payoffs += put_option_payoff;

        if(i % 10000000 == 0) {
            std::cout << "Progress: " << (i / static_cast<double>(num_samples)) * 100 << "%\r";
        }
    }

    ret_price.call_option_price = exp(-inputs.risk_free_rate * inputs.time_to_expiration) * (sum_call_option_payoffs / num_samples);
    ret_price.put_option_price = exp(-inputs.risk_free_rate * inputs.time_to_expiration) * (sum_put_option_payoffs / num_samples);

    return ret_price;
}
