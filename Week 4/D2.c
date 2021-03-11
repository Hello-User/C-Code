#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    char array[10][10];
    int i = 0;
    int j = 0;
    char k = 65;
    int try = 0;
    srand(time(0));

     //Vul array met '.'
    for (int i=0; i < 10; i++){
        for (int j=0; j < 10; j++){
            array[i][j] = 46;
        }
    }

    //Zet 0,0 op A. Dit is beginpunt
    array[0][0] = 65;


    for (k = 65; k <= 89;){
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
            if (array[beneden][j] == 46 && beneden < 10){
            i++;
            k++;
            array[i][j] = k;
            try = 0;
            break;
            }
            else{break;}
        case 1:
            if (!(boven < 0) && array[boven][j] == 46 && boven < 10){
                i--;
                k++;
                array[i][j] = k;
                try = 0;
                break;
            }
            else{break;}
        case 2:
            if(array[i][rechts] == 46 && rechts < 10){
            j++;
            k++;
            array[i][j] = k;
            try = 0;
            break;
            }
            else{break;}
        case 3:
            if(!(links < 0) && array[i][links] == 46 && links < 10){
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
        if (try >= 10){
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

    system("PAUSE");
}
