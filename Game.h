#ifndef GAME_H
#define GAME_H
#include "pokemon.h"
#include "pokemon_list.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//**Constants**                                                                                                                                                                      
const int NUM_TEAM = 5; //Number of Pokemon on each team                                                                                                                             

class Game {
public:
                                                                                                         
  Game(string);
                                                                                                  
  ~Game();
                                                                                                                    
  void LoadFile();
                                                                                                               
  void ChooseTeam();
                                                                                                                                               
  int Menu();
                                                                                      
  int Battle();
                                                                      
  int Start();
private:
  PokemonList* m_list; //Master list of all Pokemon in game                                                                              
  PokemonList* m_userPocket; //Users list of Pokemon                                                                                     
  PokemonList* m_enemyPocket; //CPU's list of Pokemon                                                                                    
  string m_filename; //Name of the file passed from main                                                                                 
};
#endif