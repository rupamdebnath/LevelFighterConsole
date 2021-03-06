#pragma once
#include "Items.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;
int RavanaSp = 0;
//The Base class Player from which all the other characters will be inherited
class Player
{
  protected:
  int health;
  int mDamage;
  int rDamage; 
  int shield;
  string name;
  friend class PlayTurn;

  public:
  virtual ~Player(){} //virtual destructor for base class

  void PlayerStat()
  {
    cout << "==================================" << endl;
    cout << "Health of " << name << " : " << health << endl;
    cout << "Melee Attack power of " << name << " : " << mDamage << endl;
    cout << "Ranged Attack power of " << name << " : " << rDamage << endl;
    cout << "Shielding Power of " << name << " : " << shield << " This value is random for the opponent every new game and this reduces your damage by the said amount." << endl;
    cout << "==================================" << endl;
  }

  int getHealth()
  {
    return health;
  }
  int getMeleeDamage()
  {
    return mDamage;
  }
  int updateHealth(int damage)
  {
      this->health = this->health - damage;
      return this->health;
  }
  void setMeleeDamage(int mdamage)
  {
      this->mDamage = mdamage;
  }  
  int getRangedDamage()
  {
    return rDamage;
  }
  void Heal(int healValue)
  {
    cout << name << " is healing this turn!! \U0001F49E \U0001F49E" << endl;
    health = health + healValue;
  }
  void TakeDamage(int damagevalue)
  {
    health = health - damagevalue;
  }
  int getShield()
  {
    return shield;
  }

  string getName()
  {
    return name;
  }

  //virtual functions for different abilities based on characters
  virtual void Reset() = 0;
  virtual void LevelUp(int health, int mDamage, int rDamage, int shield) = 0;
  //virtual void RangedAttack(Player *player) = 0;
  virtual void SpecialAbility() = 0;
  virtual void SpecialAbility(Player *player) = 0;
  //virtual void Heal() = 0;
};

class Hero : public Player
{
  public:
  Hero(string name, int health, int mDamage)
  {
    this->name = name;
    this->health = health;
    this->mDamage = mDamage;
  }
  ~Hero()
  {

  }
  void Reset()
  {
    health = 150;
  }
  void LevelUp(int health, int mDamage, int rDamage, int shield)
  {
    this->health = health;
    this->mDamage = mDamage;
    this->rDamage = rDamage;
    this->shield = shield;
  }
  void SpecialAbility(){}
  void SpecialAbility(Player *player)
  {
    int spDamage = random(40,70);
    cout << "Rama uses his Bow and Arrow to strike lighting from the skies...\U0001F3F9 \U0001F329 \U0001F329 \U0001F329" << endl;
    player->TakeDamage(spDamage);
  }
};

class Rakshasa : public Player
{
  public:
  Rakshasa(string name, int shieldMax, int health, int mDamage)
  {
    this->health = health;
    this->mDamage = mDamage;
    shield = random(7, shieldMax);
    this->name = name;    
  }
  
  ~Rakshasa()
  {
    // cout << name << " is dead." << endl;
  }
  void Reset()
  {
    health = 80;
    shield = random(7, 15);
  }
  void SpecialAbility()
  {
    cout << name << " drinks blood to recover some health from 0 to 5" << endl;
    health = health + random(0,5);
  }
  void SpecialAbility(Player *player){}
  void LevelUp(int health, int mDamage, int rDamage, int shield){}
};

class Tataka : public Player
{
  public:
  Tataka(string name)
  {
    health = 100;
    mDamage = 35;
    rDamage = 0;
    shield = random(5, 10);
    this->name = name;
  }
  void Reset()
  {
    health = 100;
    shield = random(5, 10);
  }
  void SpecialAbility()
  {
    cout << "Tataka drinks nearby deer's blood to restore health in the range of 5 to 10.." << endl;
    sleep(1);
    cout << "Tataka: Gobble.. Gobble...." << endl;
    sleep(1);
    int rand = random(5,10);
    Heal(rand);
  }
  void SpecialAbility(Player *player){}
  void LevelUp(int health, int mDamage, int rDamage, int shield){}
  ~Tataka()
  {
    // cout << "Congratulations, You have successfully killed Tataka!!" << endl;
    // cout << "You have received the Map of Lanka." << endl;
  }  

};

class Ravana : public Player
{
  int getDamageValueHero;
  public:
  Ravana()
  {
    health = 300;
    name = "Ravana";
    mDamage = 30;
    rDamage = 15;
    shield = random(20, 30);
    this->name = name;
  }
  void Reset()
  {
    health = 300;
    shield = random(20, 30);
  }
  void SpecialAbility()
  {    
    int rr = random(1,5);
    if (rr == 1)
    {
      cout << "Ravana uses Brahmic Regeneration to recover a lot of health between 20 and 50" << endl;
      health = health + random(20,50);
      cout << "Healing ...++++.OM BRAHMA.++++" << endl;
      sleep(1);
      cout << "Healing ...++++.OM BRAHMA.++++" << endl;
      sleep(1);
    }
  }
  void SpecialAbility(Player *player)
  {

    RavanaSp = random(1,2);

    switch (RavanaSp)
    {
      case 1:
      cout << "Ravana uses Skull Slash, doing a lot of damage..." << endl;
      player->TakeDamage(random(50,70));
      sleep(2);
      break;

      case 2:
      cout << "Ravana uses Speed Dash, you will miss the next turn.., Ravana gets 2 turns consecutively..." << endl;
      sleep(2);
      break;
    }

  }
  void LevelUp(int health, int mDamage, int rDamage, int shield){}
  ~Ravana()
  {

  }  

};