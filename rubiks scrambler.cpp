#include <iostream>
#include <time.h>

typedef unsigned long long int ulong;
ulong lastRand;

ulong getRand() {
    ulong key[] = { lastRand/2, lastRand/3, lastRand/4, lastRand/5, lastRand/6, lastRand/7, lastRand/8, lastRand/9, lastRand/10 };
    ulong v = lastRand & 0xFFFFFFFFFFFFul;
    ulong v0 = (v >> 24) & 0xFFFFFFu;
    ulong v1 = (v & 0xFFFFFFu);
    ulong sum = 0u;
    for (int i = 0; i < 32; ++i)
    {
        v0 += (((v1 << 3) ^ (v1 >> 4)) + v1) ^ (sum + key[sum & 3]);
        v0 &= 0xFFFFFFu;
        sum += 0xF1BBC; // floor((sqrt(5) - 2) * pow(2, 22))
        sum &= 0xFFFFFFu;
        v1 += (((v0 << 3) ^ (v0 >> 4)) + v0) ^ (sum + key[(sum >> 8) & 3]);
        v1 &= 0xFFFFFFu;
    }
    return lastRand = ((ulong)v0 << 24) + v1;
}

int main() {
    lastRand = time(NULL);

    const char moves[6] = { 'U', 'F', 'B', 'D', 'R', 'L' };
    const char* invert[2] = { "", "'" };
    int randindex;
    int previndex{};
    int invertindex;
    int move2;
    const char* rotate2;
    int move_number;
    int scramblecount;
    int tot_scrambles = 0;
    puts("How many scrambles would you like: ");
    scanf("%i", &scramblecount);

    while (tot_scrambles++ < scramblecount) {
        move_number = 0;
        while (move_number++ < 20) {
            randindex = getRand() % 6;
            invertindex = getRand() % 2;
            while (randindex == previndex)
                randindex = getRand() % 6;
            if (invertindex == 0) {
                move2 = getRand() % 2;
                if (move2 == 1)
                    rotate2 = "2 ";
                else rotate2 = " ";
            }
            else rotate2 = "";

            printf("%c%s%s", moves[randindex], invert[invertindex], rotate2);
            previndex = randindex;
        }
        puts("\r\n");
    }
}
