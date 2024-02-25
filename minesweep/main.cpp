#include<SFML/graphics.hpp>
#include <iostream>
#include "cell.cpp"
#include <time.h>
#include <string>
#include "cell_gen.cpp"
#include "assign.cpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(600,680), "Minesweeper", sf::Style::Titlebar | sf::Style::Close );
    sf::Event ev;
     srand(time(0));
     int grid[10][10];
    int w =60;
    window.setFramerateLimit(20);

    std::vector <std::vector <cell>> vec(10,(std::vector<cell>(10))) ;
    std::vector <std::vector <cell2>> vec2(10,(std::vector<cell2>(10))) ;
    generator generate_cells_obj;
    assign_value perform;
    perform.process(vec, grid, window);
     int mines= perform.mine;
    while(window.isOpen())
    {
      while(window.pollEvent(ev))  // event handler basic
        {
            if(ev.type == sf::Event::Closed)
                window.close();
            if(ev.type == sf::Event::KeyPressed)  
            {
                if(ev.key.code== sf::Keyboard::Escape)
                 window.close();
            }
            if (ev.type == Event::MouseButtonPressed)
            {
               Vector2i pos = Mouse::getPosition(window);
                  int xcoord = pos.x / w;
                  int ycoord = pos.y / w; 
                  generate_cells_obj.open_cells( xcoord, ycoord, vec, grid, window); 
            }
        }
       //update 

       window.clear(sf::Color::Red) ;  //  clear old frame

       sf::RectangleShape header ; 
       header.setSize(sf::Vector2f(600, 80));
       header.setFillColor(sf::Color::Blue);
       header.setPosition(0, 600);                                         // c to 600
 
     //rendring cells >
       for(int i=0; i<10;i++)
      {
        for(int j=0;j<10;j++)
        { 
          if (vec[i][j].state) 
          vec[i][j].structure.setFillColor(sf::Color::Red);    
        }
      }

       sf::Font font, font2;
    if(!font.loadFromFile("C:\\Users\\Hp\\Downloads\\font_file\\fontfilex.ttf"))
      {
        std::cout<<"load error ";
      }

       if(!font2.loadFromFile("C:\\Users\\Hp\\Downloads\\font_file\\fontfile123.ttf"))
      {
        std::cout<<"load error ";
      }
     
     sf::Text text_t, numtext;

      text_t.setFont(font);
      text_t.setCharacterSize(40);                        // num text >
      numtext.setFont(font2);
      numtext.setString(std::to_string(mines));
      numtext.setCharacterSize(33);  
      numtext.setPosition(50, 617);  
      numtext.setFillColor(sf::Color::Black);
      numtext.Bold;

      for(int i=0; i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
          if(vec[i][j].doomed)
          {
            std::cout<<vec[i][j].time_to_exp;
            vec[i][j].time_to_exp-= vec[i][j].doom_decrementer;
            if(vec[i][j].initiator || vec[i][j].is_mine==true)
            vec[i][j].text="X";
          if(vec[i][j].time_to_exp<0)
          {
            vec[i][j].structure.setFillColor(sf::Color::Magenta);
            vec2[i][j].structure= vec[i][j].structure;
            window.draw(vec[i][j].structure); 
          }
         }    // if doomed 
                                                                   // DRAWS 
          window.draw(vec[i][j].structure);
                                                                   // TEXT
          if(vec[i][j].state || (vec[i][j].is_mine==true&& vec[i][j].time_to_exp<0))                        
          {
            if(vec[i][j].text=="0") continue;
            else if((vec[i][j].is_mine==true)&& vec[i][j].time_to_exp<0)
            {
                text_t.setFillColor(sf::Color::Black);
            }
             else 
               text_t.setFillColor(sf::Color::White);
            text_t.setString(vec[i][j].text);   
            text_t.setOrigin(text_t.getGlobalBounds().getSize() / 2.f + text_t.getLocalBounds().getPosition());
            text_t.setPosition(vec[i][j].structure.getPosition() + (vec[i][j].structure.getSize() / 2.f));
            window.draw(text_t);
          }     
        }
      } 
     
     sf::Text text_header;
     text_header.setFont(font);
     text_header.setString("MINESWEEPER");
     text_t.setCharacterSize(50);

     sf::Text text_mine;
     text_mine.setFont(font);
     text_mine.setString(std::to_string(mines));
     text_mine.setCharacterSize(50);

     text_mine.setOrigin(text_mine.getGlobalBounds().getSize() / 2.f + text_mine.getLocalBounds().getPosition());
            text_mine.setPosition(header.getPosition() + (header.getSize() / 1.f));

     text_header.setOrigin(text_header.getGlobalBounds().getSize() / 2.f + text_header.getLocalBounds().getPosition());
            text_header.setPosition(header.getPosition() + (header.getSize() / 2.f));

     window.draw(header);
     window.draw(numtext);
     window.draw(text_header);
     window.display() ;   
      }
   // window.close 
    return 0;
}
