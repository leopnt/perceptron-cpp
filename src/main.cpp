#include <iostream>

#include "perceptron.hpp"
#include "trainer.hpp"

int main(int argc, char *argv[])
{
    Perceptron p;
    std::cout << "PERCEPTRON: " << p << std::endl;

    std::cout << "guessing before training:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        Trainer t; // new trainer data with random values
        std::cout << t << " answer: " << t.getAnswer() << std::endl;
        std::cout << "\t\tguess: " << p.guess(t.getInputs(), t.getNbInputs());
        std::cout << std::endl;
    }

    std::cout << "\ntraining perceptron..." << std::endl;
    for (int i = 0; i < 500; i++) // number of training iterations
    {
        Trainer t;
        p.train(t.getInputs(), t.getNbInputs(), t.getAnswer());
    }
    std::cout << "finished training\n" << std::endl;

    std::cout << "PERCEPTRON: new " << p << std::endl;
    std::cout << "guessing after training:" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        Trainer t;
        std::cout << t << " answer: " << t.getAnswer() << std::endl;
        std::cout << "\t\tguess: " << p.guess(t.getInputs(), t.getNbInputs());
        std::cout << std::endl;
    }
}

