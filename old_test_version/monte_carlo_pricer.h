#ifndef MCPH
#define MCPH

struct Inputs{
    double time_to_expiration = 0;
    double volatility = 0;
    double risk_free_rate = 0;
    double current_price = 0;
    double strike_price = 0;
};

struct Prices{
    double put_option_price = 0;
    double call_option_price = 0;
};

constexpr int num_samples = 100000;

Prices euro_monte_carlo_price(Inputs& input);


#endif 
