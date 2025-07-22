#ifndef OPTION_H
#define OPTION_H

#include <vector>
#include <string>

/*
    Abstract class for all option types
    Defines general interface for all options
*/
class Option {
public:
    struct Inputs{
        // Default values
        double time_to_expiration = 1; // in years
        double volatility = 0.2; // annualized volatility
        double risk_free_rate = 0.05; // annualized risk-free rate
        double spot_price = 100.0; // current price of asset
        double strike_price = 100.0; // strike price of option
        
    };

    virtual ~Option();

    // calculate payoff given a price path
    // to be overridden by derived option types
    virtual double calculate_payoff(std::vector<double>& path) const = 0;

    virtual Option::Inputs get_inputs() const = 0;

    virtual void set_inputs(const Option::Inputs& new_inputs) = 0;

    //returns option type as string
    virtual std::string get_option_type() const = 0;
};

#endif