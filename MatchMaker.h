#ifndef MATCHMAKER_H
#define MATCHMAKER_H

#include "Person.h"
#include <vector>

#pragma once

class MatchMaker
{
private:
    vector<Person>Suggestions;
    Person Queued;
    vector<Person>Liked;
    vector<Person>Passed;

public:
    MatchMaker();
    MatchMaker(Person user, vector<Person> profiles);
    MatchMaker(vector<Person> profiles);

    vector<Person>getSuggestions();
    Person GetNextPerson();
    void Pass();
    void Like();

};

#endif
