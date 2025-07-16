#ifndef ASIANOPTIONS_H
#define ASIANOPTIONS_H

#include "Option.h"
#include <vector>

class AsianCallOption : public Option {
private:
    Option::Inputs inputs;
public:
    AsianCallOption(const Option::Inputs& inputs) : inputs(inputs) {}

    AsianCallOption() = default;

    //calcualtes payoff using average over path
    double calculate_payoff(std::vector<double>& price_path) const override {
        double avg_price = 0.0;
        for (double i : price_path){
            avg_price += i;
        }
        avg_price = avg_price/price_path.size();
        return std::max(avg_price - inputs.strike_price, 0.0);
    }

    Option::Inputs get_inputs() const override{
        return inputs;
    }

    void set_inputs(const Option::Inputs& new_inputs) override {
        inputs = new_inputs;
    }

    std::string get_option_type() const override{
        return "Asian Call Option";
    }

};

class AsianPutOption : public Option {
private:
    Option::Inputs inputs;
public:
    AsianPutOption(const Option::Inputs& inputs) : inputs(inputs) {}

    AsianPutOption() = default;

    //calcualtes payoff using average over path
    double calculate_payoff(std::vector<double>& price_path) const override {
        double avg_price = 0.0;
        for (double i : price_path){
            avg_price += i;
        }
        avg_price = avg_price/price_path.size();
        return std::max(inputs.strike_price - avg_price, 0.0);
    }

    Option::Inputs get_inputs() const override{
        return inputs;
    }

    void set_inputs(const Option::Inputs& new_inputs) override {
        inputs = new_inputs;
    }

    std::string get_option_type() const override{
        return "Asian Put Option";
    }

};

#endif