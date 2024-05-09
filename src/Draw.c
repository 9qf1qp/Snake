#include<stdio.h>
#include<stdlib.h>
int i,j,height=30;
int width=30, gameover, score;

void draw()
{
  for (i=0;i<height;i++){
    for (j = 0; j<width; j++){
      if (i==0 || i == width -1 || j == 0 || j == height -1) {
        printf("#");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  draw();
  return 0;
}