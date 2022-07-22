//
// Created by Lucas Pino on 16-07-22.
//

#include "ProfileCreator.h"
#include <vector>
#include <random>


ProfileCreator::ProfileCreator(string maleCSV, string femaleCSV, string lastnamesCSV, string majorCSV,string likesCSV){
    ifstream maleNames;
    ifstream femaleNames;
    ifstream lastNames;
    ifstream majors;
    ifstream likes;

    maleNames.open(maleCSV);
    while(maleNames.good()){
        //cout<<"looking for male names\n";
        string name;
        getline(maleNames,name,'\n');
        MaleNames.push_back(name);
    }
    maleNames.close();


    femaleNames.open(femaleCSV);
    while(femaleNames.good()){
        //cout<<"looking for female names\n";
        string name2;
        getline(femaleNames,name2,'\n');
        FemaleNames.push_back(name2);
    }
    femaleNames.close();


    lastNames.open(lastnamesCSV);
    while(lastNames.good()){
        //cout<<"looking for lastnames\n";
        string name3;
        getline(lastNames,name3,'\n');
        LastNames.push_back(name3);
    }
    lastNames.close();

    majors.open(majorCSV);
    while(majors.good()){
        //cout<<"looking for majors\n";
        string name4;
        getline(majors,name4,'\n');
        Majors.push_back(name4);
    }
    majors.close();

    likes.open(likesCSV);
    while(likes.good()){

        string name5;
        getline(likes,name5,'\n');
        Likes.push_back(name5);
    }
    majors.close();

    Genders={"Masculino","Femenino","No Binario"};
/*
    cout << "se tomaron " << MaleNames.size()<<" nombres m"<< endl;
    for(int i=0; i<MaleNames.size(); i++){
        cout<< MaleNames[i]<< endl;
    }
    cout<<endl;
    cout << "se tomaron " << FemaleNames.size()<<" nombres f "<< endl;
    for(int i=0; i<FemaleNames.size();i++){
        cout<<FemaleNames[i]<< endl;
    }
    cout<< endl;
    cout << "se tomaron " << LastNames.size()<<" apellidos"<< endl;
 
    for(int i=0; i<LastNames.size();i++){
        cout<<LastNames[i]<< endl;
    }
    cout<< endl;
  */  
    
}

vector<Person> ProfileCreator::createDummies()
{
    int aux = 0;
    string name;
    string lastname;
    string fullname;
    string gender;             // how????
    string major;
    vector<string> like;
    vector<string> dislike;
    int age;


    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator

    for(int i=0; i<N_PROFILES; i++){
        if(aux==0){
            std::uniform_int_distribution<> distr1(0, MaleNames.size()-1); // range for m names
            name = MaleNames[distr1(gen)];
            aux = 1;
        }
        else{
            std::uniform_int_distribution<> distr2(0, FemaleNames.size()-1); // range for f names
            name = FemaleNames[distr2(gen)];
            aux = 0;
        }

        std::uniform_int_distribution<> distr3(0, LastNames.size()-1); // range for lastnames
        lastname = LastNames[distr3(gen)];
        

        std::uniform_int_distribution<> distr4(MIN_AGE, MAX_AGE); // range for age
        age = distr4(gen);

        std::uniform_int_distribution<> distr5(0, Majors.size()); // range for majors
        major = Majors[distr5(gen)];

        std::uniform_int_distribution<> distr8(0, Genders.size()); // range for majors
        gender = Genders[distr8(gen)];

        //adding likes and dislikes
        for(int ii=0;ii<3;ii++){
            std::uniform_int_distribution<> distr6(0, Likes.size()); // range for majors
            like.push_back(Likes[distr6(gen)]);

            std::uniform_int_distribution<> distr7(0, Likes.size()); // range for majors
            dislike.push_back(Likes[distr7(gen)]);


        }




        Person dummy = Person(name, lastname, gender, age, major);
        dummy.setLikes(like);
        dummy.setDislikes(dislike);
        DummyProfiles.push_back(dummy);
/*
        cout << dummy.getName()<< endl;
        cout << dummy.getLastName()<< endl;
        cout << dummy.getAge()<< endl;
        cout << dummy.getMajor()<< endl;
        cout << endl;
        //cout<<"toString de la función; "<<endl;
        //dummy.toString();
*/

/*
        //debugging
        cout<< "name is -> " << name << endl;
        cout<< "lastname is -> " <<lastname << endl;
        cout<< "NOMBRE COMPLETO ES ->"<< name << lastname << endl;
        cout<< "age is -> " << age << endl;
        cout<< "major is -> "<< major << endl;
        cout << endl;
        cout<<"EN EL PERFIL SE TIENE" << endl;
        dummy.toString();

        string a = "hello";
        string b = "WORLD";
        string c = a+ " " +b;
        Person dummy2 = Person(c, gender, age, major);
        DummyProfiles.push_back(dummy2);
        cout << "Name dummy2: " << dummy2.getName() <<  endl;
*/
    }
    return DummyProfiles;
}

vector<Person> ProfileCreator::getDummies()
{
    return DummyProfiles;
}
