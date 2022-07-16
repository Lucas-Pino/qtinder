//
// Created by Lucas Pino on 12-07-22.
//

#include "Person.h"

//CONSTRUCTORS
int Person::PersonCounter=0;

Person::Person(): Name(), Gender(), Age(), Id(), Major(), SexPreference(), AgePreference(), Likes(), Dislikes(), ApprovedList(), RejectedList(){
}

Person::Person(string name, string gender, int age, string major) {
    PersonCounter++;
    Id=PersonCounter;
    Name = name;
    Gender = gender;
    Age = age;
    Major = major;
}

//DESTRUCTOR
Person::~Person() {

}


//GETTERS
string Person::getName(){
    return Name;
}

string Person::getGender() {
    return Gender;
}

int Person::getAge() {
    return Age;
}

int Person::getId() {
    return Id;
}

string Person::getMajor() {
    return Major;
}

string Person::getSexPref() {
    return SexPreference;
}

int* Person::getAgePref() {
    return AgePreference;
}

string* Person::getLikes() {
    return Likes;
}

string* Person::getDislikes() {
    return Dislikes;
}

vector<int> Person::getApprovedList() {
    return ApprovedList;
}

vector<int> Person::getRejectedList() {
    return RejectedList;
}



//SETTERS
void Person::setName(string name) {
    Name=name;
}

void Person::setGender(string gender) {
    Gender=gender;
}

void Person::setAge(int age) {
    Age=age;
}

void Person::setMajor(string major) {
    Major=major;
}

void Person::setSexPref(string sexPref) {
    SexPreference=sexPref;
}

void Person::setAgePref(int agePref[2]) {
    AgePreference[0]=agePref[0];
    AgePreference[1]=agePref[1];

}

void Person::setLikes(string likes[5]) {
    //Likes[0]=likes[0];
    int arrLen=sizeof(Likes)/sizeof(Likes[0]);
    for(int i=0;i<arrLen;i++){
        Likes[i]=likes[i];
    };
}

void Person::setDislikes(string dislikes[5]) {
    //Dislikes[0]=dislikes[0];
    int arrLen=sizeof(Dislikes)/sizeof(Dislikes[0]);
    for(int i=0;i<arrLen;i++){
        Dislikes[i]=dislikes[i];
    };
}

//METHODS

void Person::approve(int liked) {
    ApprovedList.push_back(liked);
}

void Person::reject(int disliked) {
    RejectedList.push_back(disliked);
}

int Person::matchLevel(Person person2) {
    //ENTREGA EL NIVEL DE MATCH QUE TIENEN LAS PERSONAS
    int level=0;
    //LEVEL 1
    if(SexPreference==person2.getGender()
        && person2.getSexPref()==Gender){

        level++;

    //LEVEL 2
       if(AgePreference[0]>=person2.getAge()
             && person2.getAge()<=AgePreference[1]
             && person2.getAgePref()[0]>= Age
             && Age <=person2.getAgePref()[1]) {
           level++;
    //LEVEL 3
            //if(){

            //};

        };
    };
    return level;
}

