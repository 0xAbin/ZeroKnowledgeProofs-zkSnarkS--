#include <iostream>
#include <cstdlib>
#include <ctime>


bool statement()
{
    int secret = 42;

   
    return secret % 2 == 0;
}


int generate_challenge()
{
   
    srand(time(nullptr));

    return rand() % 2;
}

int provide_proof(int challenge)
{
    
    if (challenge == 0)
        return 42;
    else
        return rand();
}

int main()
{
  
    int challenge = generate_challenge();

   
    int proof = provide_proof(challenge);

   
    bool is_proof_valid = (challenge == 0 && proof == 42) || (challenge == 1 && proof != 42);

  
    if (is_proof_valid)
        std::cout << "The prover has convinced the verifier that the statement is true." << std::endl;
    else
        std::cout << "The prover has failed to convince the verifier that the statement is true." << std::endl;

    return 0;
}
