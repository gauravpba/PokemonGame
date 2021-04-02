#include "Game.h"

Game::Game(string _fileName)
{
    m_filename = _fileName;
    m_list = new PokemonList;
    m_userPocket = new PokemonList;
    m_enemyPocket = new PokemonList;
}

Game::~Game()
{    
}
void Game::LoadFile()
{
    // Open file and read the contents
    ifstream infile;
     infile.open("../" +m_filename);
    
     if (!infile.is_open()) 
    {
        cout <<"File could not be opened" << endl;
        return ;         
    }
	string line;
    Pokemon prevPokemon;
    
    while (getline(infile, line))
    {
        istringstream iss(line);
        string details[4] ;
        int i = 0;
        string token;
       while(getline(iss, token, ',')) 
       {
           if(i >=4)
               break;
            else
            {
                details[i] = token;
                i++;
            }
        }
        int index = atoi(details[0].c_str());
        string name = (string)details[1];
        string _type = (string)details[2];
        string strength = (string)details[3];
        strength.erase(strength.size() - 1);
        Pokemon* newPokemon = new Pokemon(index,name,_type,strength); 
        m_list->InsertEnd(newPokemon);
    }
    
    infile.close();
}
void Game::ChooseTeam()
{
    int left = NUM_TEAM;
    while(left > 0)
    {
        cout << "Here is a list of Pokemon you can choose from: " << endl;
        cout << "------------------------------------------------------------------------------ " << endl;    
        m_list->Display() ;
    
        
        cout << "Pick a pokemon by entering the index (" << left << " left)" << endl;
        int index;
        while(true)
        {
            cout << "Your current team is : " << endl;
            cout << "------------------------------------------------------------------------------ " << endl;    
            m_userPocket->Display();
            cin >> index;
            if(index > 151 || index < 1)
            {
                cout << "Please enter a valid index" << endl;
            }
            else
                break;
        }
        if(m_list->Exist(index))
        {
            m_list->Transfer(index, m_userPocket);        
            left --;
            cout << "Your current team is: " << endl;
            m_userPocket->Display();
        }
        else
        {
             cout << "The pokemon is not present in the remaining list" << endl;
        }        
    }    
    
    cout << "Choosing a random team for CPU" << endl;
    left = NUM_TEAM;
    srand (time(NULL));
    while(left > 0)
    {
        int randIndex = (rand() % 151) + 1;
        if(m_list->Exist(randIndex))
        {
            m_list->Transfer(randIndex, m_enemyPocket);        
            left --;            
        }
    }
     cout << "CPU team is : " << endl;
    cout << "------------------------------------------------------------------------------ " << endl;    
    m_enemyPocket->Display();
  
}
int Game::Menu()
{
    cout << "Menu: " << endl;
    cout << "1. Attack" << endl;
    cout << "2. Swap" << endl;
    cout << "3. Forfeit" << endl;
    
    int choice;
    while(true)
    {
        cin >> choice;
        
        if(choice <1 || choice > 3)
        {
            cout << "Please give a valid choice" << endl;
        }
        else
        { 
            return choice;
        }
    }
    
    return 0;
}
int Game::Battle()
{
    int round = 1;
    while(true)
    {
        cout << "Round: " << round << endl;
        Pokemon* cpuHead = m_enemyPocket->GetHead();
        Pokemon* userHead = m_userPocket->GetHead();
        
        cout << "CPU's Pokemon: " << cpuHead->GetName() << " (" << cpuHead->GetType() <<": " << cpuHead->GetHealth() << " health remaining)" << endl;
        cout << "Your Pokemon: " << userHead->GetName() << " (" << userHead->GetType() <<": " << userHead->GetHealth() << " health remaining)" << endl;
        
         int userChoice = Menu();
         
         if(userChoice == 1)
         {
             int result = m_userPocket->Attack(m_enemyPocket);
             if(result == 2)
             {
                 cout << "CPU's Pokemon has been defeated" << endl;
                 m_enemyPocket->Remove(cpuHead->GetIndex());
                 cout << "CPU has " << m_enemyPocket->GetSize() << " Pokemon remaining" << endl;                 
                 if(m_enemyPocket->GetSize() == 0)
                     return 2;
             }
             else if(result == 1)
             {
                 cout << "Your Pokemon has been defeated" << endl;
                 m_userPocket->Remove(userHead->GetIndex());
                 cout << "You have " << m_userPocket->GetSize() << " Pokemon remaining" << endl;
                 if(m_userPocket->GetSize() == 0)
                     return 1;
             }             
              round++;
         }
         else if(userChoice == 2)
         {
             int swapChoice;
             cout << "Give the index of the pokemon you want to switch" << endl;
             cout << "Your current team is : " << endl;
             cout << "------------------------------------------------------------------------------ " << endl;    
             m_userPocket->Display();
             while(true)
             {
                cin >> swapChoice;
                 if(m_userPocket->Exist(swapChoice))
                 {
                    m_userPocket->SwapPokemon(swapChoice);
                    break;
                 } 
                else
                {
                    cout << "Give a valid pokemon index" << endl;
                }             
             }
         }
         
         else if(userChoice == 3)
         {
             cout << "You Forfeit the match !" << endl;
             return 1;
         }
    }
    return 0;
}
int Game::Start()
{
    cout << "Welcome to the game" << endl;
    ChooseTeam();
    
    int result = Battle();
    if(result == 1)
        cout << "CPU WON !" << endl;
    else if(result == 2)    
        cout << "YOU WON !!" << endl;
        
return result;
}

