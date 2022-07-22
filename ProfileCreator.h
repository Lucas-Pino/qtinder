//
// Created by Lucas Pino on 16-07-22.
//

#include "Person.h"
#include <vector>
#include <string>

#define MIN_AGE 18
#define MAX_AGE 25
#define N_PROFILES 37

using namespace std;


#ifndef USM_MATCH_PROFILECREATOR_H
#define USM_MATCH_PROFILECREATOR_H


class ProfileCreator {
    vector<string> MaleNames;
    vector<string> FemaleNames;
    vector<string> LastNames;
    vector<string> Genders;
    vector<string> Majors;
    vector<string> Likes;

    vector<Person> DummyProfiles;

public: 
    //ProfileCreator(string maleCSV, string femaleCSV,string lastnamesCSV,string majorsCSV,string likesCSV);
    ProfileCreator(string maleCSV, string femaleCSV, string lastnameCSV,string majorCSV, string likesCSV);
    vector<Person> createDummies();
    vector<Person> getDummies();
};


#endif //USM_MATCH_PROFILECREATOR_H
