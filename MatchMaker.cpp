#include "MatchMaker.h"
#include <vector>

MatchMaker::MatchMaker(){}

MatchMaker::MatchMaker(Person user, vector<Person> profiles)
{
    string like1 = user.getLikes()[0];
    string like2 = user.getLikes()[1];
    string like3 = user.getLikes()[2];

    //dislikes

    vector<int>shares1;  //guarda las id de los perfiles que hacen comparten el Like
    vector<int>shares2;
    vector<int>shares3;

    int index = 0;

    for(Person dummy: profiles){
        if(user.getSexPref() == dummy.getGender()){     // quitamos quienes no tienen nada en común
            if(user.getDisLikes()[0] == dummy.getLikes()[0] || user.getDisLikes()[1] == dummy.getLikes()[1] || user.getDisLikes()[2] == dummy.getLikes()[2]){
                profiles.erase(profiles.begin() + index);

            }
            index++;
            Suggestions.push_back(dummy);

        }
        else{
            profiles.erase(profiles.begin() + index);
            index++;
        }
    }

//    for(Person dummy: profiles){         //evalua el grado de compatibilidad según intereses en común
//        Suggestions.push_back(dummy);
//    }
}



MatchMaker::MatchMaker(vector<Person> profiles) {
    Suggestions=profiles;
}


vector<Person> MatchMaker::getSuggestions(){
    return Suggestions;
}

Person MatchMaker::GetNextPerson() {
    Queued=Suggestions[Suggestions.size() - 1];
    return Queued;
}


void MatchMaker::Pass() {
    Liked.push_back(Queued);
    Suggestions.pop_back();
}

void MatchMaker::Like() {
    Liked.push_back(Queued);
    Suggestions.pop_back();
}
