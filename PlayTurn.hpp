#pragma once
#include <memory>
#include "Items.hpp"
#include "Menu.hpp"
#include <iostream>
#include <unistd.h>

 
class PlayTurn
{
  int countOfTurn = 0;
  int edamage;

  //creating unique pointers for Items
  unique_ptr<Items> sword{new Sword()};
  unique_ptr<Items> shield{ new Shield()};
  unique_ptr<Items> armour{ new Armour()};
  unique_ptr<Items> bow{ new Bow()};

  public:  
  void HeroAttack(int defenceChecker, Player *player)
  {
    if(defenceChecker == 2)    
    {
      cout << hero->getName() << " is melee attacking " << player->getName() << endl;
      cout << "But" << player->getName() << " is defending.." << endl;
      player->health = (player->health - hero->getMeleeDamage() + player->getShield());
    }
    else
    {
      cout << hero->getName() << " is melee attacking " << player->getName() << endl;
      sleep(1);
      cout << "Right Punch.....Pow!..\U0001F44A	\U0001F44A" << endl;
      sleep(1);
      cout << "Left Punch.....Pow!..\U0001F44A	\U0001F44A" << endl;
      sleep(1);
      player->health -= hero->getMeleeDamage();
    }
  }

  void HeroHealing()
  {     
    cout << hero->getName() << " is healing this turn" << endl;
    sleep(1);
    cout << "Healing +++++!! \U0001F64F ..\U0001F64F Om!" << endl;
    sleep(1);
    cout << "Healing +++++++ !! \U0001F64F ..Om! .\U0001F64F" << endl;
    sleep(1);
    hero->health += random(2, 12);   
  }  

  void HeroSwordAttack(int defenceChecker, Player *player)
  {
    if(defenceChecker == 2)    
    {
      
      sword->ItemHit();
      sword->displayStats();
      if (sword->getItemHitProbability())
      {
        cout << hero->getName() << " is critically attacking with sword \U0001F5E1 to " << player->getName() << endl;
        cout << "But" << player->getName() << " is defending.." << endl;
        player->health = (player->health - sword->getItemDamage()) + player->getShield();
        sleep(1);
      }
      else
      {
        cout << "Hero's sword attack \U0001F5E1 missed the enemy (10% chance only)" << endl;
        sleep(1);
      }
    }
    else
    {
      sword->ItemHit();
      sword->displayStats();

      if (sword->getItemHitProbability())
      {
        cout << hero->getName() << " is critically attacking with sword \U0001F5E1 to" << player->getName() << endl; 
        player->health = player->health - sword->getItemDamage();
        sleep(1);
      }      
      else
      {
        cout << "Hero's sword attack \U0001F5E1 missed the enemy(10% chance only)" << endl;
        sleep(1);
      }
    }
  } 
  
  void HeroShieldUp(Player *enemy)
  {
    shield->ItemHit();
    shield->displayStats();
    if (shield->getItemHitProbability())
    {
      cout << "Rama's Shield \U0001F6E1 is up this turn" << endl;
      edamage = enemy->getMeleeDamage();
      enemy->setMeleeDamage(0);
      sleep(1);
    }
    else
    {
      cout << "Rama's Shield \U0001F6E1 missed to block the enemy this turn (10% chance only)" << endl; 
      sleep(1);
    }
  } 

  void HeroShieldDown(Player *enemy)
  {
    enemy->setMeleeDamage(edamage);
    cout << "Rama's shield is down now" << endl;
    sleep(1);
  }

  void HeroUseArmour(Player *enemy)
  {
    armour->ItemHit();
    armour->displayStats();
    if (armour->getItemHitProbability())
    {
      cout << "Rama's armour \U0001F9E5 has successfully hit the enemy" << endl;
      enemy->health = enemy->health - armour->getItemDamage();
      hero->health = hero->health + armour->getHealingPower();
      sleep(1);
    }
    else
    {
      cout << "Hero's Armour \U0001F9E5 missed to hit the enemy this turn (10% chance only)" << endl; 
      sleep(1);
    }
  }

  void HeroBowShoot(Player *enemy)
  {
    shield->ItemHit();
    shield->displayStats();
    if (shield->getItemHitProbability())
    {
      cout << "Rama's shoots the Bow and arrow successfully \U0001F6E1 is up this turn" << endl;
      edamage = enemy->getMeleeDamage();
      enemy->setMeleeDamage(0);
      sleep(1);
      cout << "Enemy receives lot of damage from far" << endl;
      enemy->health = enemy->health - shield->getItemDamage();
      sleep(1);
      cout << "Enemy misses this turn.." << endl;
      sleep(2);
    }
    else
    {
      cout << "Rama's Bow and Arrow \U0001F3F9 missed to shoot the enemy this turn (10% chance only)" << endl; 
      sleep(1);
    }
  } 

  void HeroBowDown(Player *enemy)
  {
    enemy->setMeleeDamage(edamage);
    cout << "Rama's Bow and Arrow is down now.." << endl;
    sleep(1);
  }
  
  void EnemyAttack(Player *player)
  {    
    cout << player->getName() << " is melee attacking " << hero->getName() << endl;
    sleep(1);
    cout << "Right Punch .....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    cout << "Left Punch .....Pow!..\U0001F44A	\U0001F44A" << endl;
    sleep(1);
    hero->health -= player->getMeleeDamage();
  }

  void EnemyDefend(Player *pplayer, Player *pplayer2)
  {     
    cout << pplayer->getName() << " is defending this turn" << endl;
    sleep(1);
    cout << "Defend from Right.....Thud!! \U0001F646 ..Thud! \U0001F646" << endl;
    sleep(1);
    cout << "Defend from Left.....Thud!! \U0001F646 ..Thud! .\U0001F646" << endl;
    sleep(1);       
  }

  void EnemySpecialAttack(Player *pplayer)
  {
    pplayer->SpecialAbility();
    pplayer->SpecialAbility(hero);
  }

  int EnemyChoice(Player *enemy, Player *player)
  {    
    int r = random(1,3);
    switch(r)
    {
      case 1:
      EnemyAttack(enemy);
      break;

      case 2:
      EnemyDefend(enemy, hero);
      break;

      case 3:
      EnemySpecialAttack(enemy);            
      break;
    }
    return r;
  }
  
};