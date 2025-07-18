#ifndef GREEKS_CALCULATOR_H
#define GREEKS_CALCULATOR_H

class GreeksCalculator {
    private: 
        std::vector<vector<double>> cached_rand_nums;

    public:
        GreeksCalculator();
        GreeksCalculator(std::vector<std::vector<double>> cached_rand_nums);

        double calculate_delta(Option& option)
}

#endif