

#include "cell.cpp"
#include <iostream>

using namespace sf;

class assign_value
{
    
   public:
    int mine=0;
     //static Text text;
     void process( std::vector <std::vector <cell>> &vec, int (& grid)[10][10], sf::RenderWindow &window );
}; 

// this is a static_process function . everyting happens once and this is called a single time 
void assign_value::process( std::vector <std::vector <cell>> &vec, int (& grid)[10][10], sf::RenderWindow &window )
 {
    int c=0, w=60;
      for(int i=0; i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
         vec[i][j].doomed=false;
         vec[i][j].initiator=false;
        // vec[i][j].structure.setOutlineThickness(2.5f);
        // vec[i][j].structure.setOutlineColor(sf::Color::Red);
          if((j+c)%2==0)
          {
              vec[i][j].structure.setFillColor(sf::Color(170,215,81));
              //vec[i][j].structure.setFillColor(sf::Color::Green);
          }   
          else
          {
               vec[i][j].structure.setFillColor(sf::Color(162,209,73));
              // vec[i][j].structure.setFillColor(sf::Color::Cyan);
          }
           
        }
        c++;
      }
 // randomly generating mine cells
  for(int i = 0; i<10; i++)
        for (int j = 0; j < 10; j++) 
        {
            if (rand() % 6 == 0) 
            {
              vec[i][j].is_mine = true;
              mine++;
            }
            else vec[i][j].is_mine = false;
        }
  // setting value ---------------------------------------------------------------
      for(int i = 0; i<10; i++)
       {
        for (int j = 0; j <10; j++) {
              if (vec[i][j].is_mine) grid[i][j] = 9;
            else grid[i][j] = 0;
        }
       }



    for (int i = 0; i <10; i++)
        for (int j = 0; j<10; j++) {
            int n = 0;
            if (grid[i][j] == 9) continue;
            if (grid[i + 1][j] == 9) n++;
            if (grid[i][j + 1] == 9) n++;                // ek chutiyap ya ARR OUT OF B
            if (grid[i - 1][j] == 9) n++;
            if (grid[i][j - 1] == 9) n++;
            if (grid[i + 1][j + 1] == 9) n++;
            if (grid[i - 1][j - 1] == 9) n++;
            if (grid[i - 1][j + 1] == 9) n++;
            if (grid[i + 1][j - 1] == 9) n++;
            grid[i][j] = n;
        }
      
     sf::Font font;
     sf::Text text_t;

      if(!font.loadFromFile("C:\\Users\\Hp\\Downloads\\font_file\\fontfilex.ttf"))
      {
        std::cout<<"load error ";
      }

      text_t.setFont(font);
      text_t.setCharacterSize(60); 

      for(int i = 0; i<10; i++)
      {
        for (int j = 0; j <10; j++) 
        {
          vec[i][j].value=grid[i][j] ; 
        // assign text mf here
         
       switch (vec[i][j].value)
       {
        case 0:
        text_t.setString("0");
        break;
       case 1:
            text_t.setString("1");
            break;
        case 2:
            text_t.setString("2");
            break;
        case 3:
            text_t.setString("3");
            break;
        case 4:
            text_t.setString("4");
            break;
        case 5:
            text_t.setString("5");
            break;
        case 6:
            text_t.setString("6");
            break;
        case 7:
            text_t.setString("7");
            break;
        case 8:
            text_t.setString("8");
            break;
        case 9:
            text_t.setString("9");
             break;
       }

         vec[i][j].text=text_t.getString();
      }
    }

      //   for(int i=0; i<10;i++)
      // {
      //   for(int j=0;j<10;j++)
      //   {
      //      if(vec[i][j].is_mine)
      //      vec[i][j].structure.setFillColor(sf::Color::Black);
      //   }
      // }
  // value has been assigned ---------------------------------------------------

  // setting cell position 
   for(int i=0; i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
          vec[i][j].structure.setPosition(i * w,  j * w);
          vec[i][j].structure.setSize(Vector2f(60.f,60.f));
        }
      }
 }
