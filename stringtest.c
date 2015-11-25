//
//  stringtest.c
//  
//
//  Created by Derek Schanze on 11/24/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student Struct
typedef struct student{
    char first_name[50]; //change to string
    char last_name[50]; //change to string
    int id;
    int math_grade;
    int music_grade;
    int pe_grade;
} Student;

int main(void){
    Student student_array[100];
    char choice;
    
    printf("Enter name and id (P to print): ");
    scanf("%c ", &choice);
    if(choice == 'P'){
        scanf("%s %s %d", student_array[0].first_name, student_array[0].last_name, &student_array[0].id);
        printf("%s %s %d\n", student_array[0].first_name, student_array[0].last_name, student_array[0].id);
    }
    else printf("\nYou didn't choose to print\n");
    
    return 0;
}