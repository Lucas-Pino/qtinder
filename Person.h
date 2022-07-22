//
// Created by Lucas Pino on 12-07-22.
//

#ifndef USM_MATCH_PERSON_H
#define USM_MATCH_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person{
private:
    //Individual Attributes
    string Name;
    string Lastname;
    string Gender;
    int Age;
    int Id;
    string Major;

    vector<string> Likes;
    vector<string> Dislikes;
//PersonCounter++
    static int PersonCounter;


 /*
    string Name;            //had to make them public for inheretance
    string Lastname;
    string Gender;
    int Age;
    int Id;
    string Major;
*/
//Preferences

    string SexPreference;
    int AgePreference[2];
//ApprovedList and RejectedList Lists
    std::vector<Person> ApprovedList;
    std::vector<Person> RejectedList;


public:



    
//GETTERS
    string getName();
    string getLastName();
    string getGender();
    int getAge();
    int getId();
    string getMajor();
    string getSexPref();
    int* getAgePref();
    vector<string>getLikes();
    vector<string>getDisLikes();
    vector<Person>getApprovedList();
    vector<Person>getRejectedList();

    void toString();

//SETTERS
    void setName(string name);
    void setLastName(string lastname);
    void setGender(string gender);
    void setAge(int age);
    void setMajor(string major);
    void setSexPref(string sexPref);
    void setAgePref(int agePref[2]);
    void setLikes(vector<string> likes);
    void setDislikes(vector<string> dislikes);

//CONSTRUCTORS
    Person();
    Person(string name,string lastname, string gender,int age,string major);

//DESTRUCTORS
   // ~Person();

//METHODS
    int matchLevel(Person person2);


    void approve(Person liked);
    void reject(Person disliked);




//OVERLOADING
    bool operator == (Person person2){
        if(Id==person2.getId()){
            return true;
        } else return false;
    }

    bool operator != (Person person2){
        if(Id==person2.getId()){
            return false;
        } else return true;
    }



    /* bool operator == (Person person2){
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

 */


};


#endif //USM_MATCH_PERSON_H
