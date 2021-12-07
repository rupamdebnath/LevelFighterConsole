
#include "PlayTurn.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include <iostream>


char RunMove(int level, int nEnemies, Menu display, bool IsHavingSword, bool IsHavingShield, bool IsHavingArmour, bool IsHavingBow)
{
  bool defence = false;
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
        defence = play.EnemyChoice(enemy[i], hero);
        play.HeroAttack(defence, enemy[i]);
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
          defence = play.EnemyChoice(enemy[i], hero);
          play.HeroSwordAttack(defence, enemy[i]);
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
        break;
      }     
      break;

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
    IsHavingSword = true;
  }


  
  QuitGame:
  cout << "You have quit, Thank you for playing" << endl; 

} 