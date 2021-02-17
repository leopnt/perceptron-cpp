#include "trainer.hpp"

Trainer::Trainer(): m_nbInputs(2)
{
    m_inputs = new float[2];
    for (int i = 0; i < m_nbInputs; i++)
    {
        float r = (float) (rand() % 2); // random 1.0 or 0.0
        m_inputs[i] = r;
    }
}

Trainer::Trainer(int const& nbInputs): m_nbInputs(nbInputs)
{
    m_inputs = new float[nbInputs];
    for (int i = 0; i < m_nbInputs; i++)
    {
        float r = (float) (rand() % 2); // random 1.0 or 0.0
        m_inputs[i] = r;
    }
}

Trainer::~Trainer()
{
    delete[] m_inputs;
}

std::ostream& operator<<(std::ostream& out, Trainer const& self)
{
    out << "inputs: {";
    for (int i = 0; i < self.m_nbInputs; i++)
    {
        out << self.m_inputs[i];
        if (i != self.m_nbInputs -1) out << ", ";
    }
    out << "}";

    return out;
}

float* Trainer::getInputs() const
{
    return m_inputs;
}

float Trainer::getAnswer() const
{
    // this is the "thing" that we want to teach

    // simplle logic operators here
    // I assume that Trainer has only 2 inputs
    // in this case

    if (m_inputs[0] || m_inputs[1])
        return 1.f;

    return 0.f;
}

int Trainer::getNbInputs() const
{
    return m_nbInputs;
}