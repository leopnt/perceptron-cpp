#ifndef DEF_PERCEPTRON_HPP
#define DEF_PERCEPTRON_HPP

#include <iostream>
#include <math.h>
#include "utils.hpp"

class Perceptron
{
private:
    float m_lr; // learning rate
    int m_nbInputs;
    float *m_weights;
    float m_output;

    bool isValidInputSize(int const& size) const;
    float rawGuess(float* inputs, int const& nbInputs) const;

    friend std::ostream& operator<<(std::ostream& out, Perceptron const& self);

public:
    Perceptron();
    Perceptron(int const& nbInputs);
    ~Perceptron();

    float getConfidence(float* inputs, int const& nbInputs) const;
    float guess(float* inputs, int const& nbInputs) const;
    void train(float* inputs, int const& nbInputs, float const& answer);
};

#endif