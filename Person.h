//
// Created by Lucas Pino on 12-07-22.
//

#ifndef QTINDER_PERSON_H
#define QTINDER_PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person {
private:

//PersonCounter++
    static int PersonCounter;

//Individual Attributes
    string Name;
    string Gender;
    int Age;
    int Id;
    string Major;

//Preferences
    string SexPreference;
    int AgePreference[2];
    string Likes[5];
    string Dislikes[5];

//ApprovedList and RejectedList Lists
    std::vector<int> ApprovedList;
    std::vector<int> RejectedList;


public:

//GETTERS
    string getName();
    string getGender();
    int getAge();
    int getId();
    string getMajor();
    string getSexPref();
    int* getAgePref();
    string* getLikes();
    string* getDislikes();
    vector<int> getApprovedList();
    vector<int> getRejectedList();

//SETTERS
    void setName(string name);
    void setGender(string gender);
    void setAge(int age);
    void setMajor(string major);
    void setSexPref(string sexPref);
    void setAgePref(int agePref[2]);
    void setLikes(string likes[]);
    void setDislikes(string dislikes[]);

//CONSTRUCTORS
    Person();
    Person(string name, string gender,int age,string major);

//DESTRUCTORS
    ~Person();

//METHODS
    int matchLevel(Person person2);
    string* commonLikes(Person person);

    void approve(int liked);
    void reject(int disliked);




//OVERLOADING
    bool operator == (Person person2){
        //RETORNA TRUE SI ES QUE LOS 2 SON UNA PAREJA PERFECTA
        if (SexPreference==person2.getGender()
        && person2.getSexPref()==Gender
        && AgePreference[0]>=person2.getAge()
        && person2.getAge()<=AgePreference[1]
        && person2.getAgePref()[0]>= Age
        && Age <=person2.getAgePref()[1]
        && Likes==person2.getLikes()
        && Dislikes!=person2.getDislikes()){
            return true;
        }

        else return false;
    };

    bool operator != (Person person2){
        //RETORNA TRUE CUANDO:
        //LA PERSONA2 tiene ALGO EN SUS LIKES QUE A LA PERSONA1 NO LE GUSTA

        int arrLen = sizeof(Dislikes)/sizeof(Dislikes[0]);
        int arrLen2 = sizeof(person2.getLikes())/sizeof(person2.getLikes()[0]);
        for(int i=0;i<arrLen;i++){
            for(int ii=0;i<arrLen2;i++){
                if(Dislikes[i]==person2.getLikes()[ii]){
                    return true;
                }
            };
        };
        return false;
    };




};


#endif //QTINDER_PERSON_H
