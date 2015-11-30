#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Student Struct
typedef struct student{
    char first_name[50]; //change to string
    char last_name[50]; //change to string
    int id;
    float math_grade;
    float music_grade;
    float pe_grade;
} Student;


/*----Globals----*/
Student student_array[100];

int student_count = 0;
/*---------------*/


/*---Functions--*/
void add_student(char first_name[50] , char last_name[50], int id,
                 float math_grade, float music_grade, float pe_grade);
void export_data();
void generic_print(int i);
void goodstanding();
void import_data();
void list_students(); /* dummy test function*/
void mean();
void print_student(int student_id);
void read_data(int i_max); /* dummy test function*/
void remove_student(char search_string[50]);
void remove_student(int id);
void search(char search_string[50]);
/*--------------*/

int main(void) {

    char choice;

    for(;;) {

    scanf("%1c", &choice);

    switch(choice){
        // Declare variables
        char first_name[50];
        char last_name[50];
        int id;
        float math_grade;
        float music_grade;
        float pe_grade;

        char search_string[50];
        int student_id;

        case 'A':
            scanf(" %s %s %d %f %f %f", first_name, last_name, &id,
                                        &math_grade, &music_grade, &pe_grade
                 );
            add_student(first_name, last_name, id, math_grade, music_grade, pe_grade);
            break;
        case 'D':
            scanf(" %s", search_string);
            if (atoi(search_string) != 0) {
                // Input was a number
                remove_student(id);
            } else {
                // Input was not a number
                remove_student(search_string);
            }
            break;
        case 'E':
            export_data();
            break;
        case 'G':
            goodstanding();
            break;
        case 'I':
            import_data();
            break;
        case 'L':
            list_students();
            break;
        case 'M':
            mean();
            break;
        case 'P':
            scanf(" %d", &student_id);
            print_student(student_id);
            break;
        case 'Q':
            goto quit;
            break;
        case 'S':
            scanf(" %s", search_string);
            search(search_string);
            break;
        }
    }

quit:

    return 0;
}

// Create new student and add to student array
void add_student(char first_name[50] , char last_name[50], int id,
                 float math_grade, float music_grade, float pe_grade) {

    strcpy(student_array[student_count].first_name, first_name);
    strcpy(student_array[student_count].last_name, last_name);
    student_array[student_count].id = id;
    student_array[student_count].math_grade = math_grade;
    student_array[student_count].music_grade = music_grade;
    student_array[student_count].pe_grade = pe_grade;

    student_count++;

}

// List all created students
void list_students() {
    for(int i = 0; i < student_count; i++){
        generic_print(i);
    }
}

void export_data() {
    char output[100];

    for(int i = 0; i < student_count; i++){
        sprintf(output, "%s#%s#%.3d%.4d%.4d%.4d", student_array[i].first_name,
            student_array[i].last_name, student_array[i].id,
            (int)student_array[i].math_grade*100,
            (int)student_array[i].music_grade*100,
            (int)student_array[i].pe_grade*100);
        printf("%s", output);
    }

    printf("\n");
}

void import_data() {
    // Not sure what number to use here
    char input_string[10000];
    char * first_name;
    char * last_name;
    char * long_number;
    char id[4];
    char math_grade[5];
    char music_grade[5];
    char pe_grade[5];

    scanf(" %s", input_string);
    first_name = strtok(input_string, "#");
    while (first_name != NULL) {
        last_name   = strtok(NULL, "#");
        long_number = strtok(NULL, "#");

        strncpy(id, long_number, 3);
        id[3] = '\0';
        int id_int = atoi(id);

        strncpy(math_grade, long_number+4, 4);
        math_grade[4] = '\0';
        float math_grade_float  = atoi(math_grade) / 100.0f;

        strncpy(music_grade, long_number+8, 4);
        music_grade[4] = '\0';
        float music_grade_float = atoi(music_grade) / 100.0f;

        strncpy(pe_grade, long_number+12, 4);
        pe_grade[4] = '\0';
        float pe_grade_float    = atoi(pe_grade) / 100.0f;

        add_student(first_name, last_name, id_int,
                    math_grade_float, music_grade_float, pe_grade_float);

        first_name = strtok(NULL, "#");
    }
}

void goodstanding() {
    float total_math_points  = 0.00;
    float total_music_points = 0.00;
    float total_pe_points    = 0.00;
    for (int i = 0; i < student_count; i++) {
        total_math_points  += student_array[i].math_grade;
        total_music_points += student_array[i].music_grade;
        total_pe_points    += student_array[i].pe_grade;
    }

    float math_average  = total_math_points / student_count;
    float music_average = total_music_points / student_count;
    float pe_average    = total_pe_points / student_count;

    for (int i = 0; i < student_count; i++) {
        if (student_array[i].math_grade  > math_average &&
            student_array[i].music_grade > music_average &&
            student_array[i].pe_grade    > pe_average) {
            generic_print(i);
        }
    }
}

// Print the means of all created students for each subject
void mean() {
    float total_math_points  = 0.00;
    float total_music_points = 0.00;
    float total_pe_points    = 0.00;
    for (int i = 0; i < student_count; i++) {
        total_math_points  += student_array[i].math_grade;
        total_music_points += student_array[i].music_grade;
        total_pe_points    += student_array[i].pe_grade;
    }

    float math_average  = total_math_points / student_count;
    float music_average = total_music_points / student_count;
    float pe_average    = total_pe_points / student_count;

    printf("        MATH:   %4.2f\n", math_average);
    printf("        MUSIC:  %4.2f\n", music_average);
    printf("        PE:     %4.2f\n", pe_average);

}

void print_student(int student_id) {
    for (int i = 0; i < student_count; i++) {
        if (student_array[i].id == student_id) {
            generic_print(i);
        }
    }
}

void remove_student(char search_string[50]) {
    for (int i = 0; i < student_count; i++) {
        if (strstr(student_array[i].first_name, search_string) != NULL ||
            strstr(student_array[i].last_name, search_string)  != NULL) {

            Student blank_student = {0};

            // Check if student is the last student inserted, if so we can
            // remove safely
            if (i == student_count - 1) {
                student_array[i] = blank_student;
                student_count--;
            } else {

                // If student was not the last inserted, we need to shift all the
                // other students over

                // Remove the student
                student_array[i] = blank_student;

                // Shift other students over
                int j = i;
                while (j < student_count - 1) {
                    student_array[j] = student_array[j + 1];
                    j++;
                }

                // Delete the last student (they are now a duplicate)
                student_array[j] = blank_student;

                // Decrement student count
                student_count--;
            }
        }
    }
}
void remove_student(int id) {
    for (int i = 0; i < student_count; i++) {
        if (student_array[i].id == id) {

            Student blank_student = {0};

            // Check if student is the last student inserted, if so we can
            // remove safely
            if (i == student_count - 1) {
                student_array[i] = blank_student;
                student_count--;
            } else {

                // If student was not the last inserted, we need to shift all the
                // other students over

                // Remove the student
                student_array[i] = blank_student;

                // Shift other students over
                int j = i;
                while (j < student_count - 1) {
                    student_array[j] = student_array[j + 1];
                    j++;
                }

                // Delete the last student (they are now a duplicate)
                student_array[j] = blank_student;

                // Decrement student count
                student_count--;
            }
        }
    }
}

void search(char search_string[50]) {
    for (int i = 0; i < student_count; i++) {
        if (strstr(student_array[i].first_name, search_string) != NULL ||
            strstr(student_array[i].last_name, search_string)  != NULL) {
            generic_print(i);
        }
    }

}

// This functions handles all of the generic printing
void generic_print(int i) {
    printf("%s %s [%d]:\n", student_array[i].first_name, student_array[i].last_name, student_array[i].id);
    printf("        MATH:   %4.2f\n", student_array[i].math_grade);
    printf("        MUSIC:  %4.2f\n", student_array[i].music_grade);
    printf("        PE:     %4.2f\n", student_array[i].pe_grade);
    printf("                %4.2f\n", (student_array[i].math_grade + student_array[i].music_grade + student_array[i].pe_grade)/3.0f);
}
