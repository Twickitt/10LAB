#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Generate_And_Print_List.h"


int Generate_List(Student* arr, int n){


    
    const char *names[] = {
        "Aleksandr", "Dmitriy", "Mikhail", "Pavel", "Artem",
        "Denis", "Igor", "Vladimir", "Stanislav", "Andrei",
        "Grigoriy", "Vitaliy", "Anton", "Nikita", "Vadim",
        "Roman", "Artyom", "Maksim", "Yaroslav", "Sergey",
        "Timofey", "Yegor", "Oleg", "Konstantin", "Ruslan",
        "Bogdan", "Stepan", "Gleb", "Evgeniy", "Semyon",
        "Vasiliy", "Boris", "Viktor", "Alexey", "Valentin",
        "Leonid", "German", "Mark", "Fedor", "Yuriy",
        "Arkadiy", "Kirill", "Anatoliy", "Ilya", "Platon",
        "Ignat", "Rodion", "Nazar"
    };
    
    const char *surnames[] = {
        "Ivanov", "Petrov", "Sidorov", "Smirnov", "Fedorov",
        "Pavlov", "Gusev", "Nikolaev", "Borisov", "Egorov",
        "Klimenko", "Zaitsev", "Sokolov", "Karpov", "Tarasov",
        "Melnikov", "Frolov", "Kazakov", "Yakovlev", "Gorshkov",
        "Korneev", "Semyonov", "Grachev", "Krylov", "Belyaev",
        "Kuzmin", "Mironov", "Tkachev", "Sorokin", "Filippov",
        "Belov", "Kuznetsov", "Gavrilov", "Polyakov", "Romanov",
        "Savin", "Lebedev", "Panin", "Volkov", "Orlov",
        "Titov", "Stepanov", "Vinokurov", "Zhdanov", "Chernov",
        "Loginov", "Shestakov", "Bogdanov"
    };

    
    const char *patronymics[] = {
        "Andreevich", "Sergeevich", "Vladimirovich", "Nikolaevich", "Olegovich",
        "Dmitrievich", "Igorevich", "Viktorovich", "Konstantinovich", "Petrovich",
        "Alekseevich", "Pavlovich", "Yurievich", "Evgenievich", "Leonidovich",
        "Valentinovich", "Anatolievich", "Alexeevich", "Fedorovich", "Borisovich",
        "Romanovich", "Grigorievich", "Timofeevich", "Bogdanovich", "Arkadievich",
        "Vasilievich", "Semenovich", "Platonovich", "Yaroslavovich", "Rodionovich",
        "Nazarovich", "Glebovich", "Germanovich", "Ignatovich", "Markovich",
        "Kirillovich", "Olegovich", "Stepanovich", "Denisovich", "Ruslanovich",
        "Georgievich", "Stanislavovich", "Andrianovich", "Maximovich", "Svyatoslavovich",
        "Vadimovich", "Ilyich", "Artemovich"
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

