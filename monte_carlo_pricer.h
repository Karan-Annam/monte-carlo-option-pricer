#ifndef MCPH
#define MCPH

struct Inputs{
    double time_to_expiration = 0;
    double volatility = 0;
    double risk_free_rate = 0;
    double current_price = 0;
    double strike_price = 0;
};

constexpr int num_samples = 1000000000;

double monte_carlo_price(Inputs input);


#endif 
