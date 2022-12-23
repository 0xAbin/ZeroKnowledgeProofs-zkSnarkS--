#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <gmpxx.h>
#include <vector>
#include <unordered_map>

// This function represents the statement that we want to prove
// In this case, the statement is that we know the discrete logarithm of y to the base g
bool statement(mpz_class g, mpz_class y, mpz_class p, mpz_class x)
{
    mpz_class left, right;

    // Calculate the left side of the equation
    mpz_powm(left.get_mpz_t(), g.get_mpz_t(), x.get_mpz_t(), p.get_mpz_t());

    // Calculate the right side of the equation
    right = y;

    // Return whether the left side is equal to the right side
    return left == right;
}

// This function generates a random challenge value
int generate_challenge()
{
    // Seed the random number generator
    srand(time(nullptr));

    // Generate a random number between 0 and 99
    return rand() % 100;
}

// This function represents the proof that we provide to the verifier
std::pair<mpz_class, mpz_class> provide_proof(int challenge, mpz_class g, mpz_class y, mpz_class p, mpz_class x)
{
    // Calculate g^(c*x)
    mpz_class g_to_cx;
    mpz_powm_ui(g_to_cx.get_mpz_t(), g.get_mpz_t(), challenge * x.get_ui(), p.get_mpz_t());

    // Calculate y^c
    mpz_class y_to_c;
    mpz_powm_ui(y_to_c.get_mpz_t(), y.get_mpz_t(), challenge, p.get_mpz_t());

    // Return the pair (g^(c*x), y^c)
    return std::make_pair(g_to_cx, y_to_c);
}

int main()
{
    // The prover and verifier engage in the Zero Knowledge Proof protocol

    // Set the values of g, y, p, and x
    mpz_class g, y, p, x;
    g = 2;
    y = 8;
    p = 13;
    x = 3;

    // The verifier generates a challenge value
    int challenge = generate_challenge();

    // The prover provides a proof in response to the challenge
    std::pair<mpz_class, mpz_class> proof = provide_proof(challenge, g, y, p, x);

    // The verifier checks the proof to see if it is valid
    mpz_class left, right;
    left = proof.first * proof.second;
    right = g;
    right = right.pow(challenge);
    right = right * y;
    right = right.pow(100 - challenge);

    bool is_proof
      
      
      
      
   // algo 2 ;
  
      #include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

// This struct represents a block in the blockchain
struct Block
{
    // The data contained in the block
    std::vector<int> data;

    // The hash of the previous block in the chain
    std::string prev_hash;

    // The hash of the current block
    std::string hash;
};

// This function calculates the hash of a block
std::string calculate_hash(const Block& block)
{
    // In this example, we just concatenate the data values and the previous hash, and return the result
    std::string hash = "";
    for (int value : block.data)
        hash += std::to_string(value);
    hash += block.prev_hash;
    return hash;
}

// This function represents the statement that we want to prove to the verifier
bool statement(const Block& block, int value)
{
    // In this case, we want to prove that the value is present in the block's data
    return std::find(block.data.begin(), block.data.end(), value) != block.data.end();
}

// This function generates a random challenge value
int generate_challenge()
{
    // Seed the random number generator
    srand(time(nullptr));

    // Generate a random number between 0 and the size of the block's data - 1
    return rand() % block.data.size();
}

// This function represents the proof that we provide to the verifier
int provide_proof(const Block& block, int challenge)
{
    // We return the value at the index specified by the challenge
    return block.data[challenge];
}

// This function verifies the proof
bool verify_proof(const Block& block, int value, int challenge, int proof)
{
    // The proof is valid if the value of the proof at the index specified by the challenge is equal to the value
    return block.data[challenge] == value;
}

int main()
{
    // Create the first block in the chain
    Block genesis;
    genesis.data = {1, 2, 3};
    genesis.prev_hash = "";
    genesis.hash = calculate_hash(genesis);

    // Create a map to store the blocks in the chain
    std::unordered_map<std::string, Block> blocks;
    blocks[genesis.hash] = genesis;

    // The prover and verifier engage in the Zero Knowledge Proof protocol

    // The prover wants to prove that the value 2 is present in the genesis block
    int value = 2;

    // The verifier generates a challenge value
    int challenge = generate_challenge();

    // The prover provides a proof in response to the challenge
    int proof = provide_proof(genesis, challenge);

    // The verifier checks the proof to see if it is valid
    bool is_proof_valid = verify_proof(genesis, value, challenge, proof);

    // If the proof is valid, the verifier can be convinced that the statement is true 
  
  
  //zkp test 2.0 
   

      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
