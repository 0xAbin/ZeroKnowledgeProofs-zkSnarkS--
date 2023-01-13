#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <gmpxx.h>
#include <vector>
#include <unordered_map>


bool statement(mpz_class g, mpz_class y, mpz_class p, mpz_class x)
{
    mpz_class left, right;

   
    mpz_powm(left.get_mpz_t(), g.get_mpz_t(), x.get_mpz_t(), p.get_mpz_t());

 
    right = y;

    
    return left == right;
}

// gc
int generate_challenge()
{
    
    srand(time(nullptr));

    
    return rand() % 100;
}


std::pair<mpz_class, mpz_class> provide_proof(int challenge, mpz_class g, mpz_class y, mpz_class p, mpz_class x)
{
    //  g^(c*x)
    mpz_class g_to_cx;
    mpz_powm_ui(g_to_cx.get_mpz_t(), g.get_mpz_t(), challenge * x.get_ui(), p.get_mpz_t());

    mpz_class y_to_c;
    mpz_powm_ui(y_to_c.get_mpz_t(), y.get_mpz_t(), challenge, p.get_mpz_t());

    // Return the pair (g^(c*x), y^c)
    return std::make_pair(g_to_cx, y_to_c);
}

int main()
{
    //  values of g, y, p, and x
    mpz_class g, y, p, x;
    g = 2;
    y = 8;
    p = 13;
    x = 3;

   
    int challenge = generate_challenge();

   
    std::pair<mpz_class, mpz_class> proof = provide_proof(challenge, g, y, p, x);

   
    mpz_class left, right;
    left = proof.first * proof.second;
    right = g;
    right = right.pow(challenge);
    right = right * y;
    right = right.pow(100 - challenge);

    bool is_proof
      
      
      
      
   // algo 2 ;
  
//  block in the blockchain
struct Block
{
 
    std::vector<int> data;

  
    std::string prev_hash;

  
    std::string hash;
};


std::string calculate_hash(const Block& block)
{
    
    std::string hash = "";
    for (int value : block.data)
        hash += std::to_string(value);
    hash += block.prev_hash;
    return hash;
}


bool statement(const Block& block, int value)
{

    return std::find(block.data.begin(), block.data.end(), value) != block.data.end();
}

int generate_challenge()
{
   
    srand(time(nullptr));

    return rand() % block.data.size();
}


int provide_proof(const Block& block, int challenge)
{
 
    return block.data[challenge];
}

//  verifies the proof
bool verify_proof(const Block& block, int value, int challenge, int proof)
{
   
    return block.data[challenge] == value;
}

int main()
{
   
    Block genesis;
    genesis.data = {1, 2, 3};
    genesis.prev_hash = "";
    genesis.hash = calculate_hash(genesis);

    std::unordered_map<std::string, Block> blocks;
    blocks[genesis.hash] = genesis;

   
    int value = 2;

    
    int challenge = generate_challenge();

   
    int proof = provide_proof(genesis, challenge);

 
    bool is_proof_valid = verify_proof(genesis, value, challenge, proof);


  
  
  //zkp test 2.1
   // smart contract
   

      //Snarkzk
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
