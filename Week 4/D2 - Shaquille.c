#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    char array[10][10];
    int i = 0;
    int j = 0;
    char k = 65;
    int try = 0;
    int time_ = time(0);
    srand(time(0));
    //printf("%d\n", time_);

     //Vul array met '.'
    for (int i=0; i < 10; i++){
        for (int j=0; j < 10; j++){
            array[i][j] = '.';
        }
    }

    //Zet 0,0 op A. Dit is beginpunt
    array[0][0] = 65;


    for (k = 'A'; k < 'Z';){
        int richting = rand() % 4;
        int links = j;
        links--;
        int boven = i;
        boven--;
        int beneden = i;
        beneden++;
        int rechts = j;
        rechts++;
        switch (richting){
        case 0:
            if (array[beneden][j] == '.' && beneden < 10){
            i++;
            k++;
            array[i][j] = k;
            try = 0;
            break;
            }
            else{break;}
        case 1:
            if (!(boven < 0) && array[boven][j] == '.' && boven < 10){
                i--;
                k++;
                array[i][j] = k;
                try = 0;
                break;
            }
            else{break;}
        case 2:
            if(array[i][rechts] == '.' && rechts < 10){
            j++;
            k++;
            array[i][j] = k;
            try = 0;
            break;
            }
            else{break;}
        case 3:
            if(!(links < 0) && array[i][links] == '.' && links < 10){
                j--;
                k++;
                array[i][j] = k;
                try = 0;
                break;
            }
            else {break;}
        default:
            break;
        }
        try++;
        if (try >= 20){
            break;
        }

    }
    //Wijs array zodat we het kunnen zien
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}
