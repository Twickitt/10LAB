#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Generate_And_Print_List.h"


int Generate_List(Student* arr, int n){


    
    const char *names[] = {
        "Aleksandr", "Dmitriy", "Mikhail", "Anna", "Pavel",
        "Ekaterina", "Artem", "Olga", "Denis", "Igor",
        "Maria", "Vladimir", "Tatiana", "Stanislav", "Irina",
        "Andrei", "Grigoriy", "Elena", "Vitaliy", "Yulia",
        "Anton", "Darya", "Nikita", "Veronika", "Vadim",
        "Alina", "Roman", "Kristina", "Artyom", "Marina",
        "Elizaveta", "Denis", "Anastasiya", "Pavel", "Viktoriya",
        "Igor", "Yana", "Maksim", "Darya", "Anton",
        "Ekaterina", "Andrei", "Olga", "Mikhail", "Anna",
        "Denis", "Irina", "Pavel"
    };
    
    const char *surnames[] = {
        "Ivanov", "Petrov", "Sidorov", "Kozlova", "Smirnov",
        "Volkova", "Fedorov", "Morozova", "Pavlov", "Gusev",
        "Kuznetsova", "Nikolaev", "Orlova", "Borisov", "Egorova",
        "Klimenko", "Zaitsev", "Vinogradova", "Sokolov", "Belova",
        "Karpov", "Golubeva", "Tarasov", "Kovaleva", "Melnikov",
        "Savchenko", "Frolov", "Gavrilova", "Kazakov", "Polyakova",
        "Yakovleva", "Gorshkov", "Bogdanova", "Korneev", "Romanova",
        "Semyonov", "Kulikova", "Grachev", "Potapova", "Krylov",
        "Filippova", "Belyaev", "Davydova", "Kuzmin", "Sorokina",
        "Tkachev", "Kiseleva", "Mironov"
    };

    
    const char *patronymics[] = {
        "Andreevich", "Sergeevich", "Vladimirovich", "Nikolaevna", "Olegovich",
        "Dmitrievna", "Igorevich", "Viktorovna", "Konstantinovich", "Petrovich",
        "Alekseevna", "Andreevich", "Sergeevna", "Dmitrievich", "Olegovna",
        "Nikolaevich", "Vladimirovich", "Pavlovna", "Igorevich", "Mikhailovna",
        "Vadimovich", "Andreevna", "Sergeevich", "Dmitrievna", "Olegovich",
        "Nikolaevna", "Vladimirovich", "Igorevna", "Pavlovich", "Viktorovna",
        "Andreevna", "Sergeevich", "Dmitrievna", "Olegovich", "Nikolaevna",
        "Vladimirovich", "Igorevna", "Petrovich", "Alekseevna", "Dmitrievich",
        "Sergeevna", "Nikolaevich", "Vladimirovna", "Igorevich", "Pavlovna",
        "Olegovich", "Andreevna", "Viktorovich"
    };
    
    const char *faculties[] = {
        "CS", "Math", "SE", "EE", "ME", "CE", "ChE", "DS", "AI", "IT",
        "IS", "Robotics", "Physics", "Stats", "Bioinformatics", "Cybersecurity", "Aerospace",
        "Econ", "BA", "Fin", "Mktg", "Mgmt", "IR", "PolSci", "Sociology", "Psych",
        "Phil", "Linguistics", "Lit", "Hist", "Fine Arts"
    };
    
    const char *groups[] = {
        "201", "202", "203", "204", "205", "206",
        "211", "212", "213", "214", "215", "216",
        "221", "222", "223", "224", "225", "226",
        "231", "232", "233", "234", "235", "236",
        "241", "242", "243", "244", "245", "246"};


    int na = sizeof(names)/sizeof(names[0]);
    int sur = sizeof(surnames)/sizeof(surnames[0]);
    int patr = sizeof(patronymics)/sizeof(patronymics[0]);
    int fac = sizeof(faculties)/sizeof(faculties[0]);
    int gr = sizeof(groups)/sizeof(groups[0]);
    
    for(int i =0; i <n; i++){

        const char* gen_name = names[rand() % na];
        const char* gen_surname = surnames[rand() % sur];
        const char* gen_partonymic = patronymics[rand() % patr];
        
        snprintf(arr[i].name, sizeof(arr[i].name), "%s %s %s", gen_surname, gen_name, gen_partonymic);

        strcpy(arr[i].faculty, faculties[rand() % fac]);
        strcpy(arr[i].group, groups[rand() % gr]);

        arr[i].GPA = 4.0 + (float)(rand() % 601) / 100.0;
        
    }
}

void Print_List(Student arr[], int size){
    for(int i = 0; i < size; i++){
        printf("------------------------------------------------------------------------------------\n");
        printf("%-12d%-30s | %-15s | %-11s | %-5.2f\n", i + 1, arr[i].name, arr[i].faculty, arr[i].group, arr[i].GPA);
    }
}

