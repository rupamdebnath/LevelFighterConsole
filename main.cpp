
#include "PlayTurn.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include <iostream>


char RunMove(int level, int nEnemies, Menu display, bool IsHavingSword, bool IsHavingShield, bool IsHavingArmour, bool IsHavingBow)
{
  int enemyChoice;
  char userInput;
  Player *enemy[nEnemies-1];
  if (level == 1)  
  enemy[nEnemies-1] = new Tataka("Tataka");
  else
  {
    for(int i = 0; i < nEnemies; i++)
    {
      string nameEnemy = "Rakshasa"+to_string(i+1);
      enemy[i] = new Rakshasa(nameEnemy, 30,40,30);
    }
  }
  RestartLevel: 
  PlayTurn play;
  do
  {
    for(int i = 0; i < nEnemies; i++)
    enemy[i]->PlayerStat();  
    display.ShowHeroTurn();  
    cin>>userInput;
    switch(userInput)
    {
      case 'a':
      NextEnemy:
      for(int i = 0; i < nEnemies; i++)
      {        
        enemyChoice = play.EnemyChoice(enemy[i], hero);
        play.HeroAttack(enemyChoice, enemy[i]);
        if (enemy[i]->getHealth() < 1)
        {
          nEnemies--; 
          if (nEnemies > 0)  
          goto NextEnemy;
          else
          goto LevelCleared;            
        }      
      }      
      break;

      case 'd':
      play.HeroHealing();
      for(int i = 0; i < nEnemies; i++)
      {
        play.EnemyChoice(enemy[i], hero);
      }
      break;

      case 'w':
      if (IsHavingSword)
      { 
        NextEnemy1:
        for(int i = 0; i < nEnemies; i++)
        {        
          enemyChoice = play.EnemyChoice(enemy[i], hero);
          play.HeroSwordAttack(enemyChoice, enemy[i]);
          if (enemy[i]->getHealth() < 1)
          {
            nEnemies--; 
            if (nEnemies > 0)  
            goto NextEnemy1;
            else
            goto LevelCleared;            
          }      
        }      
      break;
      }
      else
      {
        cout << "You don't have the sword yet, Invalid move." << endl;
        sleep(2);
        break;
      }  

      case 's':
      if (IsHavingShield)
      { 
        //NextEnemy2:
        for(int i = 0; i < nEnemies; i++)
        {      
          play.HeroShieldUp(enemy[i]);  
          enemyChoice = play.EnemyChoice(enemy[i], hero);
          if (enemyChoice != 1)
          {
            cout << "You used shield but Enemy didn't attack this turn, tough Luck!!" << endl;
          }
          play.HeroShieldDown(enemy[i]);
          // if (enemy[i]->getHealth() < 1)
          // {
          //   nEnemies--; 
          //   if (nEnemies > 0)  
          //   goto NextEnemy2;
          //   else
          //   goto LevelCleared;            
          // }      
        }     
        break;
      }
      else
      {
        cout << "You don't have the Shield yet, Invalid move." << endl;
        sleep(2);
        break;
      }     

      case 'q':
      //goto QuitGame;
      break;

      default:
      cout << "Invalid selection!!" << endl;
      break;
    }
  }while(userInput != 'q' && hero->getHealth() > 0 && nEnemies>0);
  if (userInput == 'q') 
  return 'q'; 
  else if (hero->getHealth() < 1)
  {
    cout << "Oops, you are dead, restarting this level" << endl;
    cout << "........." << endl;
    sleep(1);
    cout << "..............." << endl;
    sleep(1);
    hero->Reset();
    for(int i = 0; i < nEnemies; i++)
    {
      enemy[i]->Reset();
    }
    goto RestartLevel;
  }
  else
  LevelCleared:
  cout <<"Awesome, all enemies are dead, Level is cleared" << endl;
  return 'l';
}

int main() 
{
  int nOfEnemies, level;
  bool IsHavingSword, IsHavingShield, IsHavingArmour, IsHavingBow;
  Menu display;
  PlayTurn play;
  
  //Player *enemy[5];  

  //Starting Level 1
  level = 1;
  display.ShowLevel1();
  nOfEnemies = 1;
  IsHavingSword = false;
  IsHavingShield = false;
  IsHavingArmour = false;
  IsHavingBow = false;
  char result = RunMove(level, nOfEnemies, display, IsHavingSword, IsHavingShield, IsHavingArmour, IsHavingBow);
  if(result == 'q')
  goto QuitGame;
  else if (result == 'l')
  {
    cout << "You have received the map of Lanka from Tataka." << endl;
    cout << "you are proceeding to next level........." << endl;
    sleep(1);
    cout << "........" << endl;
    sleep(1);
    level++;
    hero->Reset();
  }

  //Starting Level 2
  display.ShowLevel2();
  nOfEnemies = 2;
  result = RunMove(level, nOfEnemies, display, IsHavingSword, IsHavingShield, IsHavingArmour, IsHavingBow);
  if(result == 'q')
  goto QuitGame;
  else if (result == 'l')
  {
    cout << "You have received the weapon Sword as a reward. This gives you a new critical attack possibility going forwards." << endl;
    level++;
    hero->Reset();
    IsHavingSword = true;
  }

  //Starting Level 3
  display.ShowLevel3();
  nOfEnemies = 3;
  result = RunMove(level, nOfEnemies, display, IsHavingSword, IsHavingShield, IsHavingArmour, IsHavingBow);
  if(result == 'q')
  goto QuitGame;
  else if (result == 'l')
  {
    cout << "You have received the weapon Shield as a reward. This gives you a new ability to block the opponents attack (10% chance)" << endl;
    level++;
    hero->Reset();
    IsHavingShield = true;
  }
  
  

  
  QuitGame:
  cout << "You have quit, Thank you for playing" << endl; 

} 