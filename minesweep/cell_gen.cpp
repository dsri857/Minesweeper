
#pragma once
#include "cell.cpp"
#include<iostream>
// i write good c++
class generator
{
    public:
  void open_cells( int xcoord, int ycoord, std::vector <std::vector <cell>> &vec, int (&grid)[10][10], sf::RenderWindow &window);
  void explode( std::vector <std::vector <cell>> &vec, sf::RenderWindow &window, int x, int y  ) ;
  void open_cells2( int x, int y, std::vector <std::vector <cell>> &vec,  int (& grid)[10][10]);
  void destruct( int x, int y, std::vector <std::vector <cell>> &vec, int factor, int &latency );
  //static void assign_text( cell &check_cell );
};
        //opening logic  
  void generator::open_cells( int xcoord, int ycoord, std::vector <std::vector <cell>> &vec,  int (&grid)[10][10], sf::RenderWindow &window)
    { 
        int i=xcoord, j=ycoord;

        if (vec[i][j].value == 0)  
         generator::open_cells2(  i, j, vec, grid );

        vec[i][j].state=true;
       // generator::assign_text(vec[i][j]);

        if(vec[i][j].is_mine)
         generator::explode(vec, window, i, j);        
    }
  
  //this will be recursive function  
   void generator::open_cells2( int i, int j, std::vector <std::vector <cell>> &vec, int (& grid)[10][10] )
   {    
      if(i<0 || j<0 || i>9 || j>9) return;
      if(vec[i][j].value==9 || vec[i][j].state==true)
         return ;
          if(vec[i][j].value==0)
          {
           vec[i][j].state=true;
         //  generator::assign_text(vec[i][j]);
              open_cells2( i+1, j, vec, grid);
              open_cells2( i, j+1, vec, grid);
              open_cells2( i-1, j, vec, grid);
              open_cells2( i+1, j-1, vec, grid);

              open_cells2( i+1, j+1, vec, grid);
              open_cells2( i-1, j-1, vec, grid);
              open_cells2( i-1, j+1, vec, grid);
              open_cells2( i+1, j-1, vec, grid);
          }
        if(grid[i][j]<9)
        {
          vec[i][j].state=true;
        //  generator::assign_text(vec[i][j]);
        }            
   }
 
    void generator::explode ( std::vector <std::vector <cell>> &vec, sf::RenderWindow &window , int i, int j)
   {
    std::cout<<"called";
   
     vec[i][j].doomed=true;
     vec[i][j].initiator=true;
     vec[i][j].time_to_exp=1000;
     vec[i][j].doom_decrementer=200;
 // shaking once 
          for(int i=0; i<4; i++)
           {// Generate random displacement
            float displacementX = static_cast<float>(std::rand() % 10 - 5);
            float displacementY = static_cast<float>(std::rand() % 10 - 5);

            // Apply the displacement to the window's position
            window.setPosition(sf::Vector2i(window.getPosition().x + static_cast<int>(displacementX),
                                             window.getPosition().y + static_cast<int>(displacementY)));

            // Display the changes
               window.display();
              window.setPosition(sf::Vector2i(window.getPosition().x - static_cast<int>(displacementX),
                                             window.getPosition().y - static_cast<int>(displacementY)));
            // Introduce a small delay to control the shake speed
            sf::sleep(sf::milliseconds(5)); // Adjust as needed}
           }
        sf::sleep(sf::milliseconds(20));
     int x=i, y=j, outer=0, inner=0, k=1, latency=10;
 //                                                                EXPLOSION TIME CONTROL     
    // int top_left = i-k, j-k; 
     while(outer<10)
       { 
        int latency_correction=latency;
       // TOP LEFT TO TOP RIGHT
        for (int zz = i-k; zz <= i+k; ++zz) 
            generator::destruct(zz, j-k, vec, k, latency+=3);
        
        // TOP RIGHT TO BOTTOM RIGHT
        for (int zz = j-k; zz <= j+k; zz++) 
            generator::destruct(i+k, zz, vec, k, latency+=2);
        
        // TOP RIGHT TO BOTTOM RIGHT
        for( int zz= j-k; zz<=j+k; zz++)
            generator::destruct(i-k, zz, vec, k, latency+=3);
       
        //BOTTOM LEFT TO BOTTOM RIGHT
        for( int zz= i-k; zz<= i+k; zz++)
            generator::destruct(zz, j+k, vec, k, latency+=2);

        k++; outer++; 
        latency -= (int) ((latency - latency_correction) *(0.35)) ;
        //latency++;
       }// outer while
     }


  void generator::destruct( int x, int y, std::vector <std::vector <cell>> &vec, int factor, int &latency)
  {
    
     if(x<0 || y<0 || x>9 || y>9) return;
     vec[x][y].doomed=true;
    //   next layer explosion should start at 75% of completion of first layer
    //   next explosion should be timed differently from previous i.e random value should be of greater magnitude
    //   
     vec[x][y].time_to_exp= 1100+ latency ;
     latency += rand()%20 +50;
     vec[x][y].doom_decrementer= 80 + rand()%20;
     
  }
