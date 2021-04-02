#include "pokemon_list.h"

PokemonList::PokemonList()
{
    m_head = NULL;
}

PokemonList::~PokemonList()
{
}
void PokemonList::InsertEnd(Pokemon* pokemon)
{
    Pokemon* newNode = pokemon;
    Pokemon* nodePtr;
    newNode->SetNext(NULL);

    if (m_head == NULL)
    {
        m_head = newNode;        
    }
    else
    {
        nodePtr = m_head;
        while (nodePtr->GetNext())
            nodePtr = nodePtr->GetNext();
        nodePtr->SetNext(newNode);
    }
    m_size++;
}
void PokemonList::Display()
{
    if(m_size >0)
    {
        Pokemon *nodePtr;

        nodePtr = m_head;

        while (nodePtr)
        {
            cout << *nodePtr << endl;
            nodePtr = nodePtr->GetNext();
        }        
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}
void PokemonList::Transfer(int _index, PokemonList*  _pokemonList)
{
        Pokemon* nodePtr = m_head;
        
        while (nodePtr)
        {
           if(nodePtr->GetIndex() == _index)
           {
               int index = nodePtr->GetIndex();
               string name = nodePtr->GetName();
               string _type = nodePtr->GetType();
               string strong = nodePtr->GetStrong();
               Pokemon* copyPokemon = new Pokemon(index,name,_type,strong); 
               _pokemonList->InsertEnd(copyPokemon);
               Remove(_index);
               return;
           }
           nodePtr = nodePtr->GetNext();
        }        

}
void PokemonList::Remove(int index)
{
    Pokemon *nodePtr;
    Pokemon *previousNode;

    if (!m_head)
        return;

    if (m_head->GetIndex() == index)
    {
        nodePtr = m_head->GetNext();
        delete m_head;
        m_head = nodePtr;
    }

    else
    {
        nodePtr = m_head;

        while (nodePtr != NULL && nodePtr->GetIndex() != index)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->GetNext();
        }

        if (nodePtr)
        {
            previousNode->SetNext(nodePtr->GetNext());
            delete nodePtr;
        }
    }
    m_size --;
}
int PokemonList::GetSize()
{
    return m_size;
}
Pokemon* PokemonList::GetHead()
{
    return m_head;
}

int PokemonList::Attack(PokemonList* _pokemonlist)
{
    Pokemon* computerHead = _pokemonlist->m_head;
    
    if(m_head->GetStrong() == computerHead->GetType())
    {      
        computerHead->SetHealth(computerHead->GetHealth() - 5);
        cout << "CPU's pokemon took 5 damage" << endl;
        if(computerHead->GetHealth() <= 0)
            return 2;
        m_head->SetHealth(m_head->GetHealth() - DAMAGE2USER);
        cout << "Your pokemon took "<< DAMAGE2USER << " damage" << endl;
        if(m_head->GetHealth() <= 0)
            return 1;
    }
    else if( computerHead->GetStrong() == m_head->GetType())
    {
        computerHead->SetHealth(computerHead->GetHealth() - DAMAGE2ENEMY);
        cout << "CPU's pokemon "<< DAMAGE2ENEMY << " damage" << endl;
        if(computerHead->GetHealth() <= 0)
            return 2;
            
        m_head->SetHealth(m_head->GetHealth() - 5);
        cout << "Your pokemon took 5 damage" << endl;
        
         if(m_head->GetHealth() <= 0)
            return 1;
    }
    else
    {
        computerHead->SetHealth(computerHead->GetHealth() - DAMAGE2ENEMY);
        cout << "CPU's pokemon "<< DAMAGE2ENEMY << " damage" << endl;
        if(computerHead->GetHealth() <= 0)
            return 2;
            
        m_head->SetHealth(m_head->GetHealth() - DAMAGE2USER);
        cout << "Your pokemon took "<< DAMAGE2USER << " damage" << endl;        
         if(m_head->GetHealth() <= 0)
            return 1;
    }
    return 0;
}
void PokemonList::SwapPokemon(int _index)
{
    Pokemon *previous = m_head;
    Pokemon *current=m_head;    

    if(m_head->GetIndex() == _index)
    {
        cout << "Pokemon already at the head" << endl;
        cout << "Give an index of the pokemon in your pocket" << endl;
        return;
    }
    
    while (current)
    {        
        if(current->GetIndex() == _index)
        {
            previous->SetNext(current->GetNext());
            current->SetNext(m_head);
            m_head=current;           
        }
        previous = current;
        current=current->GetNext();        
    }
}
bool PokemonList::Exist(int _index)
{
    Pokemon *nodePtr;

    nodePtr = m_head;

    while (nodePtr)
    {
        if(nodePtr->GetIndex() == _index)
            return true;
        nodePtr = nodePtr->GetNext();
    }
    return false;
}
