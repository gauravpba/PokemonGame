#ifndef POKEMONLIST_H
#define POKEMONLIST_H
#include <iostream>
#include <string>
#include "pokemon.h"
using namespace std;

                                                                                                                                                                  
const int DAMAGE2USER = 3; //Damage that an enemy does to user Pokemon                                                                                                               
const int DAMAGE2ENEMY = 2; //Damage that a user Pokemon does to enemy                                                                                                               
const int STRONG_DAMAGE = 5; //Damage done to a vulnerable Pokemon                                                                                                                   

class PokemonList{
public:
                                                                                                              
  PokemonList();
                                                                                                          
  ~PokemonList();
                                                                                                          
  void InsertEnd(Pokemon* pokemon);
                                                                                                                        
  void Display();
                                                                                                                                                                
  void Transfer(int, PokemonList*);
                                                                                                                               
  void Remove(int);
                                                                           
  int GetSize();
                                                             
  Pokemon* GetHead();
                                                        
  int Attack(PokemonList* );
                                                   
  void SwapPokemon(int);
                                                                      
  bool Exist(int);
private:
  Pokemon* m_head; //Node pointer pointing to first node in linked list                                                          
  int m_size; //Size of the linked list                                                                                                  
};
#endif