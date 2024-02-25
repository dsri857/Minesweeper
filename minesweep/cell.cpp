#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

// this class acts more as a structure than a class
class cell
{
// properties of each cell;
  public:
  bool is_mine;
  RectangleShape structure;
  int value;
  bool state=false;
  std::string text;
 // sf::Time time_to_exp;
 int time_to_exp;
  bool doomed;
  int doom_decrementer;
  bool initiator;
  //true -> tapped    false -> untapped  
};

class cell2
{
  public:
  bool is_mine;
  RectangleShape structure;
  //int value;
  bool state=false;
  std::string text;
 // sf::Time time_to_exp;
 int time_to_exp;
  bool doomed;
  //true -> tapped    false -> untapped
};
 
