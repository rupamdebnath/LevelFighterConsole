#pragma once
#include <iostream>
#include <unistd.h>
//#include "/home/runner/TheAncientLord/include/Player.hpp"
#include "Level.hpp"
using namespace std;

Player *hero = new Hero("Rama", 150, 30); 

//Menu class for displaying statistics and storyline
class Menu
{
  public:
  void Intro()
  {
    cout << "Prologue..." << endl;
    sleep(1);
    cout << "Hello Player,\nWelcome to this singleplayer adventure game called The Ancient Lord based on the mythological story of Ramayana!" << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(2);
    cout << "You will play this game as Lord Rama, \U0001f466 a prince who lived in the Kingdom of Ayodhya, son of King Dasharatha. But he was banished to the Firewood Forest \U0001f332 unfortunately, where he started living with his wife Sita \U0001f467.\nOne fine day, Ravana, the king of Lanka, \U0001f47d invades the Forest for firewood and finds the small house where Rama and Sita were living. He gets mesmerised with Sita's beauty and looks for an opportunity to take her with him. One morning when Rama was out hunting for food, Ravana takes the opportunity and kidnaps Sita. He takes her to his kingdom of Lanka. You come back to discover what had happened.\nYou sit down crying, when Mitra, \U0001f468 the keeper of the forest appears..." << endl;
    cout << "-----------------------------------------------" << endl;
    sleep (2);
    cout << "Mitra: Hello Rama, please don't cry. We who live in this Forest are oppressed by Ravana a lot. But there has been an ancient prophecy that a Hero will come one day to kill Ravana. We want to destroy Ravana once and for all.\nWe believe in you, please stand up and fight..." << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(1);
    cout << "You: OK Mitra, but how can I defeat this fierce demon?" << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(1);
    cout << "Mitra: It will not be easy, You will need to cross this forest till the very end, then cross the seas and finally you will reach Lanka. Along the way, there will be other demons to fight, as you defeat them, you will gain special powers and weapons that will ultimately help you in killing Ravana. You will need a Sword, Shield, Magic Armor and a Bow to successfully beat him." << endl;
    cout << "-----------------------------------------------" << endl;
    sleep(2);
    cout << "Mitra: Using the powers vested in me by this Forest, \U0001f332 I will help you by giving you a health boost..." << endl;
    sleep(1);
    cout << "++++" << endl;
    sleep(1);
    cout << "++++++++++++" << endl;
    sleep(1);
    cout << "Your health has increased to 150. You decide to fight your way up to Ravana..\nYou: OK Mitra, thank you for your help, I will go to Lanka and rescue my wife.." << endl;
    sleep(1);
    cout << "Mitra: Good Luck!! I will be whispering in your ear every step of the way to help you. Remember your health or abilities will increase with each level, and also be rewarded with new weapons.." << endl;
    cout << "============================END OF PROLOGUE=====================" << endl;
    sleep(2);
    cout << "=========================================================================" << endl;
    sleep(1);
  }

  void ShowHeroTurn()
  {
    cout << "Your stats" << endl;
    cout << "=======================" << endl;    
    cout << "Health : " << hero->getHealth() << endl;
    cout << "Melee Attack power : " << hero->getMeleeDamage() << endl;
    cout << "Ranged Attack power : " << hero->getRangedDamage() << endl;   
   
    cout << "=======================" << endl;  
    cout << "\na: Punch Left and right \U0001F91C \U0001F91B" << endl;
    cout << "\nd: Heal some health by folding your arms \U0001F64F in the range of 0 to 10 randomly.." << endl;
    cout << "\nw: Use your sword for heavy damage \U0001F5E1 this turn, you will need the Sword weapon from Level 2 to activate this. This gives you a critical hit probability of 10% to all enemies" << endl;
    cout << "\ns: Use your shield ability \U0001F6E1 this turn with a 10% chance to block all attacks You will get this reward after level 3" << endl;
    cout << "\nz: Use your armour ability \U0001F9E5 this turn with a 10% chance to heal back dsome health, You will get this reward after level 4" << endl;
    cout << "\nx: Use your Bow and Arrow \U0001F3F9 ability this turn with a 10% chance for enemy to miss next turn, You will get this reward after level 5" << endl;
    cout << "\nq: Force Quit the Game!! \U0001F97A" << endl;
    cout << "Your turn: " << endl;
  }

  void DisplayStats(Player *_player1, Player *player2)
  {
    // cout << "Latest Stats in this level:" << endl;
    // cout << "==================================" << endl;
    cout << "Health of " << _player1->getName() << " is" << _player1->getHealth() << endl;

    cout << "Health of " << player2->getName() << " is" << player2->getHealth() << endl;
  }

  void ShowLevel1()
  {
    cout << "Starting Level 1: .......\nYou make the long journey through the forest. But suddenly a demon named Tataka appears \U0001f9db who lives in the Dark Valleys of this forest.\n---------------------------------\nMitra: Tataka was a beautiful woman who was transformed into a demon (rakshasi) when she tried to seduce the rishi Agastya. As a demon, she drinks the blood of living creatures and kills anything she can see.\nShe has a health of 100 and melee damage of 35. She can randomly either defend or attack you each turn!!\nHer special ability : she can drink blood of animals to restore health every turn as well!!" << endl;
    sleep(2);
    cout << "Tataka: \U0001F5e3 He He he ! Who do we have here... Mister Rama, Today is the day I shall drink your blood..\n\n" << endl;
    sleep(2);
  }

  void ShowLevel2()
  {
    cout << "Starting Level 2: .......\nYou finally reach the end of the forest and see the ocean. And appears the 2 guard demons \U0001f9db Banka and \U0001f9db Danka who guard the passageway to the ocean.\n---------------------------------\nMitra: These 2 stupid demons are pawns for Ravana. They have been ordered to keep a watch at whoever tried to cross the ocean.\nThey each have a health of 80 and melee damage of 20. They can randomly either defend or attack you each turn!!\nThey have no special ability so should be easy to kill!!\nYou will receive the sword for heavy damage if you can kill them!" << endl;
    sleep(2);
    cout << "Banka: \U0001F5e3 Well Hello there, seems like someone wants to cross the ocean..\nDanka: Haha, many have tried before but failed. Turn back or else we will make pieces of you and feed the fishes with it.\n" << endl;
    sleep(2);
  }

  void ShowLevel3()
  {
    cout << "Starting Level 3: .......\nMitra: Glad that both the stupid demons are dead. Thank you. In return, I will give you this boat to help you cross the ocean. Also your health, healing value and damage has increased. Consider this a blessing from the Forest animals.\nYou start the journey through the ocean. And just when you are in the middle of it,  3 water demons appear \U0001f9db Marichi \U0001f9db Danava \U0001f9db Dhadhichi and Dusharu who live in these waters.\n---------------------------------\nMitra: These demons kill any humans who try to cross this ocean and eat them for lunch.\nThey each have a health of 100 and melee damage of 20. They can randomly either defend or attack you each turn!!\nThey have no special ability !\nYou will receive the Shield for activating blocking ability if you can kill them!" << endl;
    sleep(2);
    cout << "Danava: \U0001F5e3 He who tried to cross this ocean shall die in vain..\nDhadhichi: Haha, we shall kill you and eat you.\n" << endl;
    cout << "Dusharu: AAAAAA..." << endl;
    sleep(2);
  }

};