#include <stdio.h>

 struct persoonsnaam{
    char voornaam[10];
    char achternaam[15];
 };
 
 struct student{
    struct persoonsnaam naam;
    int leeftijd;
    char geslacht;
 }student1, student2;

 int main(){
     student1.naam.voornaam = "Fred";
     student1.naam.achternaam = "Bakker";
     student1.geslacht = 'M';
     student1.leeftijd = 25;
 }