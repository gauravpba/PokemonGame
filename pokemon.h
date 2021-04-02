#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

                                                                                                                                                            
const int MAX_HEALTH = 9; 

class Pokemon {
public:
                                                                                                                       
  Pokemon();
                                                                                                           
  Pokemon(int, string, string, string);
                                                                                                              
  Pokemon* GetNext();
                                                                                                                                  
  string GetName();
                                                                                                                                   
  int GetIndex();
                                                                                                                                     
  string GetType();
                                                                                        
  int GetHealth();
                                                      
  string GetStrong();
                                                                                 
  void SetHealth(int);
                                                                           
  void SetNext(Pokemon*);
                                                    
  friend ostream &operator<<( ostream &output, Pokemon &P);

private:
  string m_name; //Name of Pokemon                                                                                                       
  int m_index; //Index of Pokemon                                                                                                        
  string m_type; //Type of Pokemon                                                                                                       
  string m_strong; //Type of Pokemon this Pokemon is strong against (5 damage)                                                           
  int m_health; //Health of Pokemon                                                                                                      
  Pokemon* m_next = nullptr; //Pointer to next Pokemon in list                                                                           
};
#endif