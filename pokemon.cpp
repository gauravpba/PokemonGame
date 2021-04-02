#include "pokemon.h"

Pokemon::Pokemon()
{
    m_next = nullptr;
    m_index= 0;
    m_name = "";
    m_type = "";
    m_strong = "";
    m_health = 9;
}

Pokemon::Pokemon(int _index, string _name, string _type, string _strength)
{
    m_index = _index;
    m_name = _name;
    m_type = _type;
    m_strong = _strength;
     m_next = nullptr;
     m_health = 9;
}
Pokemon* Pokemon::GetNext()
{
    return m_next;
}
string Pokemon::GetName()
{
    return m_name;
}

int Pokemon::GetIndex()
{
    return m_index;
}

string Pokemon::GetType()
{
    return m_type;
}
string Pokemon::GetStrong()
{
    return m_strong;
}
int Pokemon::GetHealth()
{
    return m_health;
}
void Pokemon::SetHealth(int _health)
{
    m_health = _health;
}
void Pokemon::SetNext(Pokemon*  _pokemon)
{
    m_next = _pokemon;
}
ostream &operator<<( ostream &output, Pokemon &P)
{    
    output << setw(6) <<  "Index:" << setw(3) << left <<  P.GetIndex()  <<  setw(6) <<left << "\t Name:" <<  setw(10) << P.GetName()  << setw(6) << "\t Type: " << setw(5) << P.GetType() << setw(8) << "\t Health: " << P.GetHealth();
    return output;
}