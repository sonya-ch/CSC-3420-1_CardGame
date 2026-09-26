/*
Name: Saranya Chotsiri
Project: CardGame - PokerPal
Course: Data Structures and Algorithms I
Description: This file is the main menu and call constructor.
Date: 9/22/2026
*/
#include <iostream>
#include "CardGame.h"

using namespace std;

int
main ()
{

//create an object "game"
  CardGame game;

  int choice;

  cout << endl;
  cout << "====================================" << endl;
  cout << "======== Hello! Wellcome to ========" << endl;
  cout << "======= PokerPal Application =======" << endl;
  cout << "====================================" << endl;
//  cout << endl;

  do
    {
      game.displayMenu ();
      cin >> choice;


      cout << endl;
      cout << "====================================" << endl;

      game.handleMenuOption (choice);

    }
  while (choice != 5);

  return 0;
}
