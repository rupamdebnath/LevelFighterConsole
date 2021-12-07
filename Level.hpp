#pragma once
#include <iostream>
#include "Items.hpp"
#include "Player.hpp"

class Level
{
  
  public:
  Level()
  {
    // public:

  }
};

class Level1 : public Level
{

  public:
  void Intro()
  {
    cout << "Starting Level 1: .......\nYou make the long journey through the forest. But suddenly a demon named Tataka appears \U0001f9db who lives in the Dark Valleys of this forest.\n---------------------------------\nMitra: Tataka was a beautiful woman who was transformed into a demon (rakshasi) when she tried to seduce the rishi Agastya. As a demon, she drinks the blood of living creatures and kills anything she can see.\nShe has a health of 100 and melee damage of 35. She can randomly either defend or attack you each turn!!\nHer special ability : she can drink blood of animals to restore health every turn as well!!" << endl;
    sleep(2);
    cout << "Tataka: \U0001F5e3 He He he ! Who do we have here... Mister Rama, Today is the day I shall drink your blood..\n\n" << endl;
    sleep(2);
  }
};

class Level2 : public Level
{
  public:
  void Intro()
  {
    cout << "Starting Level 2: .......\nYou finally reach the end of the forest and see the ocean. And appears the 2 guard demons \U0001f9db Banka and \U0001f9db Danka who guard the passageway to the ocean.\n---------------------------------\nMitra: These 2 stupid demons are pawns for Ravana. They have been ordered to keep a watch at whoever tried to cross the ocean.\nThey each have a health of 80 and melee damage of 20. They can randomly either defend or attack you each turn!!\nThey have no special ability so should be easy to kill!!\nYou will receive the sword for heavy damage if you can kill them!" << endl;
    sleep(2);
    cout << "Banka: \U0001F5e3 Well Hello there, seems like someone wants to cross the ocean..\nDanka: Haha, many have tried before but failed. Turn back or else we will make pieces of you and feed the fishes with it.\n" << endl;
    sleep(2);
  }
};