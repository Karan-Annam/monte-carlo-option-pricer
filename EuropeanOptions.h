#ifndef EUROPEANOPTIONS_H
#define EUROPEANOPTIONS_H

#include "Option.h"


class EuropeanCallOption : public Option {
private:
    Inputs inputs;

public:
    EuropeanCallOption(const Inputs& inputs) : inputs(inputs) {}

    EuropeanCallOption() = default;

    double calculate_payoff(std::vector<double>& path) const override {
        double final_price = path.back();
        return std::max(final_price - inputs.strike_price, 0.0);
    }

    Option::Inputs get_inputs() const override {
        return inputs;
    }

    void set_inputs(const Option::Inputs& new_inputs) override {
        inputs = new_inputs;
    }

    std::string get_option_type() const override {
        return "European Call Option";
    }
};


class EuropeanPutOption : public Option {

private:
    Inputs inputs;

public:
    EuropeanPutOption(const Inputs& inputs) : inputs(inputs) {}

    EuropeanPutOption() = default;

    double calculate_payoff(std::vector<double>& path) const override {
        double final_price = path.back();
        return std::max(inputs.strike_price - final_price, 0.0);
    }

    Option::Inputs get_inputs() const override{
        return inputs;
    }

    void set_inputs(const Option::Inputs& new_inputs) override {
        inputs = new_inputs;
    }

    std::string get_option_type() const override {
        return "European Put Option";
    }
};


#endif