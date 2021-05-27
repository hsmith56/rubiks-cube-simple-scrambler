#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

int main() 
{
    srand (time (NULL));
    const char moves[6] = {'U', 'F', 'B', 'D', 'R', 'L'};
    const string invert[2] ={"","' "};
    int randindex;
    int previndex;
    int invertindex;
    int move2;
    string rotate2;
    int move_number;
    int scramblecount;
    int tot_scrambles = 0;

    cout <<"How many scrambles would you like: ";
    cin >> scramblecount;

    while (tot_scrambles++ < scramblecount)
    {
        move_number = 0;
        while (move_number++ < 20) 
        {
            randindex = rand() % 6;
            invertindex = rand() % 2; 
            while (randindex == previndex)
            {
                randindex = rand() % 6;
            }
            if (invertindex == 0)
            {
                move2 = rand() % 2;
                if (move2 == 1) 
                {
                    rotate2 = "2 ";
                }
                else rotate2 = " "; 
            }
            else { rotate2 = ""; }
            cout << moves[randindex] << invert[invertindex] << rotate2; 
            previndex = randindex;
        }
        cout << endl;
    }
}