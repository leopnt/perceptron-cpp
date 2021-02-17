#ifndef DEF_TRAINER_HPP
#define DEF_TRAINER_HPP

#include <iostream>

class Trainer
{
private:
    int m_nbInputs;
    float* m_inputs;

    friend std::ostream& operator<<(std::ostream& out, Trainer const& self);

public:
    Trainer();
    Trainer(int const& nbInputs);
    ~Trainer();
    float* getInputs() const;
    float getAnswer() const;
    int getNbInputs() const;
};


#endif