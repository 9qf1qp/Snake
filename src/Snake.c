#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
int i,j,height=20,width=20,gameover,score;
int x,y,fruit,fruity,fruitx,flag;

/*Using rand()%20 because the size of the boundary is 
length = 20 and width = 20 so the fruit will generate
within the boundary.*/

void setup()
{
  gameover=0;
  x=height/2;
  y=width/2;
  label1:
    fruit=rand()%20;
    if (fruit==0)
    goto label1;
  label2:
    fruity=rand()%20;
    if (fruity==0)
      goto label2;
    score=0;
}

void draw() 
{ 
    system("cls"); 
    for (i = 0; i < height; i++) { 
        for (j = 0; j < width; j++) { 
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) { 
                printf("#"); 
            } 
            else { 
                if (i == x && j == y) {
                    printf("0");
                }
                else if (i == fruitx && j == fruity) {
                    printf("*"); 
                }
                else{
                    printf(" ");
            } 
            } 
        } 
        printf("\n"); 
    } 
        // Print the score after the 
    // game ends 
    printf("score = %d", score); 
    printf("\n"); 
    printf("press X to quit the game"); 
}

void input ()
{
  if (kbhit())
  {
    switch(getch())
    {
      case 'a':
        flag=1;
        break;
      case 's':
        flag=2;
        break;
      case 'd':
        flag=3;
        break;
      case 'w':
        flag=4;
        break;
      case 'x':
        gameover=1;
        break;
    }
  }
}

void logic() 
{ 
    Sleep(0.01); 
    switch (flag) { 
    case 1: 
        y--; 
        break; 
    case 2: 
        x++; 
        break; 
    case 3: 
        y++; 
        break; 
    case 4: 
        x--; 
        break; 
    default: 
        break; 
    } 
  
    // If the game is over 
    if (x < 0 || x > height 
        || y < 0 || y > width) 
        gameover = 1; 
  
    // If snake reaches the fruit 
    // then update the score 
    if (x == fruitx && y == fruity) { 
    label3: 
        fruitx = rand() % 20; 
        if (fruitx == 0) 
            goto label3; 
  
    // After eating the above fruit 
    // generate new fruit 
    label4: 
        fruity = rand() % 20; 
        if (fruity == 0) 
            goto label4; 
        score += 10; 
    } 
} 

void main() 
{ 

  int m,n;
    // Generate boundary 
    setup(); 
  
    // Until the game is over 
    while (!gameover) { 
  
        // Function Call 
        draw(); 
        input(); 
        logic(); 
    } 
} 