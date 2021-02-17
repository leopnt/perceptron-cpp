#include "perceptron.hpp"

Perceptron::Perceptron(): m_nbInputs(2), m_lr(0.1)
{
    m_weights = new float[m_nbInputs];
    initRandomArr(m_weights, m_nbInputs);
}

Perceptron::Perceptron(int const& nbInputs): m_nbInputs(nbInputs), m_lr(0.1)
{
    m_weights = new float[m_nbInputs];
    initRandomArr(m_weights, m_nbInputs);
}

Perceptron::~Perceptron()
{
    delete[] m_weights;
}

std::ostream& operator<<(std::ostream& out, Perceptron const& self)
{
    out << "weights: {";
    for (int i = 0; i < self.m_nbInputs; i++)
    {
        out << self.m_weights[i];
        if (i != self.m_nbInputs -1) out << ", ";
    }
    out << "}";

    return out;
}

bool Perceptron::isValidInputSize(int const& size) const
{
    // handle bad inputs
    if (size != m_nbInputs) 
    {
        std::cout << "Warning: ";
        std::cout << "Given nb of inputs doesn't match perceptron nb of inputs";
        std::cout << std::endl;

        return false;
    }

    return true;
}

float Perceptron::rawGuess(float* inputs, int const& nbInputs) const
{
    // return a guess between -1.0 and 1.0
    
    isValidInputSize(nbInputs);

    float ot = 0.f;
    for (int i = 0; i < m_nbInputs; i++)
    {
        ot += inputs[i] * m_weights[i];
    }
    ot /= (float) m_nbInputs;

    return ot;
}

float Perceptron::guess(float* inputs, int const& nbInputs) const
{
    return round(rawGuess(inputs, nbInputs));
}

void Perceptron::train(float* inputs, int const& nbInputs, float const& answer)
{
    isValidInputSize(nbInputs);

    float tryGuess = guess(inputs, nbInputs);
    float err = answer - tryGuess;

    for (int i = 0; i < m_nbInputs; i++)
    {
        m_weights[i] += err * inputs[i] * m_lr;
    }
}
