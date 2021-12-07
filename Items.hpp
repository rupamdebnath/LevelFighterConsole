#pragma once
#include <iostream>
using namespace std;

//writing a randoim function for the abilities of characters
int random(int min, int max) //range : [min, max]
{
  bool first = true;
  if (first) 
  {  
    srand(time(NULL)); //seeding for the first time only!
    first = false;
  }
  int _value = min + rand() % (( max + 1 ) - min);
  return _value;
}

class Items
{
  protected:
  int itemDamage;
  int itemHeal;
  int itemHealth;
  bool itemHitProbability;
  string name;

  public:
  virtual ~Items(){} //virtual destructor for base class
  int getItemHealth()
  {
    return itemHealth;
  }

  string getItemName()
  {
    return name;
  }

  int getHealingPower()
  {
    return itemHeal;
  }

  int getItemDamage()
  {
    return itemDamage;
  }

  int getItemHitProbability()
  {
    return itemHitProbability;
  }
  void displayStats()
  {
    cout << "==========Item Stats============" << endl;
    cout << "Item Damage = " << itemDamage << endl;
    cout << "Item Health = " << itemHealth << endl;
    cout << "Item Healing ability = " << itemHeal << endl;
    cout << "====================================" << endl;
  }

  virtual void ItemHit() = 0;

};

class Sword : public Items
{
  public:
  Sword()
  {
    itemHealth = 10;
    name = "Sword";
    itemDamage = 50;
    
    //itemHitProbability = (random(1,10) == 1)? true: false;
  }
  void ItemHit()
  {
    itemHitProbability = (random(1,10) == 1)? true: false;
  }
  ~Sword(){}
};

class Shield : public Items
{
  public:
  Shield()
  {
    itemHealth = 50;
    name = "Shield";
    itemDamage = random(0, 10);
  }
  void ItemHit();
  ~Shield(){}
};

class Armour : public Items
{
  public:
  Armour()
  {
    itemHealth = 80;
    name = "Armour";
    itemHeal = 10;
    itemDamage = random(0, 5);
  }
  void ItemHit(){}
  ~Armour(){}
};

class Bow : public Items
{
  public:
  Bow()
  {
    itemHealth = 10;
    name = "Bow";
    itemDamage = random(50, 80);
  }
  void ItemHit(){}
  ~Bow(){}
};