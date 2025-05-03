#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int posY = (num % w == 0) ? num/w  : num/w + 1;
    int posX = 0;
    int temp = num - (w*(posY -1));
    if(posY % 2 == 0)
        posX = w + 1 - temp;
    else
        posX = temp;

    int topLevelY = (n % w == 0) ? n/w  : n/w + 1;
    int topLevelX = 0 ;
    temp = n - (w*(topLevelY -1));
    if(topLevelY % 2 == 0)
        topLevelX = w + 1 - temp;
    else
        topLevelX = temp;
    
    if(topLevelY % 2 == 0)
    {
        if( topLevelX <= posX)
            answer = topLevelY - posY + 1;
        else
            answer = topLevelY - posY;
    }
    else
    {
          if( topLevelX >= posX)
            answer = topLevelY - posY + 1;
        else
            answer = topLevelY - posY;
    }

    
    return answer;
}
