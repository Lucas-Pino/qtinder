//
// Created by Lucas Pino on 12-07-22.
//

#include "Person.h"

//CONSTRUCTORS
int Person::PersonCounter=0;

//Person::Person(): Name(), Gender(), Age(), Id(), Major(), SexPreference(), AgePreference(), Likes(), Dislikes(), ApprovedList(), RejectedList(){
//}
Person::Person(){
    PersonCounter++;
    this->Id=PersonCounter;
    this->Name = "noname";
    this->Lastname = "nolastname";
    this->Gender = "nogender";
    this->Age = 0;
    this->Major = "civil";
}
Person::Person(string name, string lastname, string gender, int age, string major) {
    PersonCounter++;
    this->Id=PersonCounter;
    this->Name = name;
    this->Lastname = lastname;
    this->Gender = gender;
    this->Age = age;
    this->Major = major;
}

//DESTRUCTOR
//Person::~Person() {

//}

//GETTERS
string Person::getName(){
    return Name;
}

string Person::getLastName(){
    return Lastname;
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

vector<string> Person::getLikes() {
    return Likes;
}

vector<string> Person::getDisLikes() {
    return Dislikes;
}

vector<Person> Person::getApprovedList() {
    return ApprovedList;
}

vector<Person> Person::getRejectedList() {
    return RejectedList;
}

void Person::toString(){        //needs fixing: name not printing properly via cout
    cout <<"Name: "<<getName()<<", Lastname:  "<<getLastName()<< ", Age: "<<getAge()<<", Major: "<<getMajor()<<endl;
}

//SETTERS
void Person::setName(string name) {
    Name=name;
}

void Person::setLastName(string lastname){
    Lastname=lastname;
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

void Person::setLikes(vector<string> likes) {

    for(int i=0;i<likes.size();i++){
        Likes.push_back(likes[i]);
    };
}

void Person::setDislikes(vector<string> dislikes) {

    for(int i=0;i<dislikes.size();i++){
        Dislikes.push_back(dislikes[i]);
    };
}

//METHODS

void Person::approve(Person liked) {
    ApprovedList.push_back(liked);
}

void Person::reject(Person disliked) {
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

