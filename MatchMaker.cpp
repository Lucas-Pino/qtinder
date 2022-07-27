#include "MatchMaker.h"
#include <vector>

MatchMaker::MatchMaker(){}

MatchMaker::MatchMaker(Person user, vector<Person> profiles)
{
    int index = 0;

    for(Person dummy: profiles){
        if(user.getSexPref() == dummy.getGender()){     // filtro por genero
            cout<< "genero preferido-> "<<user.getSexPref()<<endl;
            cout<< "genero dummy-> "<<dummy.getGender()<<endl;
            if(user.getDisLikes()[0] == dummy.getLikes()[0] || user.getDisLikes()[1] == dummy.getLikes()[1] || user.getDisLikes()[2] == dummy.getLikes()[2]){
                profiles.erase(profiles.begin() + index);       //filtro por hobbies

            }
            index++;
            Suggestions.push_back(dummy);

        }
        else{
            profiles.erase(profiles.begin() + index);
            index++;
        }
    }
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
    Passed.push_back(Queued);
    Suggestions.pop_back();
}

void MatchMaker::Like() {
    Liked.push_back(Queued);
    Suggestions.pop_back();
}
