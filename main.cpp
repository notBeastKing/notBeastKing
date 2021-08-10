#include<iostream>
#include<stdio.h>
#include<chrono>
#include<thread>
#include<ctime>

using namespace std;
using namespace chrono;
using namespace this_thread;

struct players
{
  string name;
  int health;
  int mana;

  int yes()
  {
    cout<<"name = "<<name<<endl;
    cout<<"health = "<<health<<endl; 
    cout<<"mana = "<<mana<<endl;  
    return 0;  
  }
};

int attack(int*);
int defend(int*);
int breserker(int*, int*, int* );
int bot(int*, int*, int*, int*);




int main()
{
  int b;
  string a;
  string k;

cout<<"eneter your name:";
cin>>a;

cout<<"\n";

players player1;
player1.name = a;
player1.health = 10;
player1.mana = 100;
player1.yes();

players bots;
bots.name = "bot";
bots.health = 10;
bots.mana = 100;

cout<<"\n";

  cout<<"rules of the game are "<<endl;
  sleep_for(500ms);
  cout<<"1) there are 3 options attack , defend, breserker"<<endl;
  sleep_for(500ms);
  cout<<"2) attack does 2 hearts of damage"<<endl;
  sleep_for(500ms);
  cout<<"3) defend makes you take 0 hearts of damage but if breserker is used against you you will still take 1 heart of damage"<<endl;
  sleep_for(500ms);
  cout<<"4) breserk does 3 hearts of damage to the enemy and you take 1 heart of damage as well"<<endl;
  sleep_for(500ms);

  cout<<"\n";
  
  cout<<"you have only 10 round good luck"<<endl;
  sleep_for(500ms);

  cout<<"\n";

cout<<"games begins in"<<endl;
  sleep_for(10s);
  for(int i=0; i<10;i++)
  {
    cout<<i+1<<endl;
    sleep_for(1s);
  }

  for(int j =1 ;j<11 ;j++)
  {
    srand(time(0));
    b = (rand()%3);
    cout<<a<<":";
    cin>>k;

    if(k == "attack")
    {
      attack(&bots.health);
      bot(&b, &bots.mana, &player1.health, &bots.health);
      cout<<"your health is : "<<player1.health<<endl;
      cout<<"bot's heatlh is : "<<bots.health<<endl;
    }
    else
    {
      if(k=="defend")
      {
          defend(&player1.health);\
          bot(&b, &bots.mana, &player1.health, &bots.health);
          cout<<"your health is : "<<player1.health<<endl;
          cout<<"bot's heatlh is : "<<bots.health<<endl;
      }    
      else
      {
       if(k == "breserker")
       {
            breserker(&player1.mana, &player1.health, &bots.health);
              bot(&b, &bots.mana, &player1.health, &bots.health);
              cout<<"your health is : "<<player1.health<<endl;
              cout<<"bot's heatlh is : "<<bots.health<<endl; 
       }
       
      }
    }
    if(bots.health<=0)
    {
      cout<<"you won the game"<<endl;
       break;
    }
    else
    {
    if(player1.health<=0)
    {
       cout<<"you LOST the game"<<endl;    
       break;
    }
    }
  }

  

 
return 0;
}


int attack(int* h2)
{
  *h2 = *h2 - 2;
  
  return 0;
}

int defend(int* h1)
{
  
  
  return 0;
}

int breserker(int* M, int* h1, int* h2 )
{
  if(*M==100)
  {
    *h1 = *h1 - 1;
    *h2 = *h2 - 3;
    *M = *M -100;
    cout<<"your mana = "<<*M<<endl;
  }
   else{
     cout<<"you can't use breserker this round"<<endl;
   }
   return 0;
}

int bot(int*p, int*M, int*h1, int*h2)
{
  if(*p == 1)
  {
    *h1 = *h1 - 2;
 
  }
  else
  {
    if(*p = 2)
    {
      *h2 = *h2;
    }
    else 
    {
       if(*p == 3)
      {
        *h2 = *h2 - 1;
        *h1 = *h1 - 3;
         *M = *M -100;
         cout<<"enemy mana = "<<*M<<endl;
      }
       else
       {
         if(*M<=0)
         {
           {
            cout<<"bot tried to use breserker with 0 mana"<<endl;
           }
         }

       }
       
    }
  }
  return 0;
}

