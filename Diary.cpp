#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Diary.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

Diary::Diary()
{
    start = NULL;
    finish = NULL;
    startWord = NULL;

}

void Diary::insertEntry(std::string in_title, std::string date)
{
    entry *dateplace = addDate(date);


    dateplace->title = in_title;
    if(start==NULL)
    {

        start = dateplace;
        start->next = NULL;
        start->prev = NULL;


    }
    else
    {


        entry *finder = start;
        while(finder->next != NULL)
        {

            finder = finder->next;

        }
        finder->next = dateplace;
        dateplace->prev = finder;
        dateplace->next = NULL;


    }
    entry *here = start;

    addWords(in_title, dateplace);


}
void Diary::addWords(std::string content, entry *dateplace)
{

    int startFinder = 0;
    int finder = 0;
    std::string place;
    for(int i = 0; i < content.length(); i++)
    {

        if(content[i] == ',' || content[i] == '.' || content[i] == '!' || content[i] == '?')
        {
            startFinder = finder;
            finder = i;
            insertWord(content.substr(startFinder, i-startFinder), dateplace);

            finder++;
            finder++;
            i++;

        }
        else if(content[i] == ' ')
        {

            startFinder = finder;
            finder = i;
            insertWord(content.substr(startFinder, i-startFinder), dateplace);

            finder++;

        }
        else if(i == (content.length()-1))
        {
            startFinder = finder;

            insertWord(content.substr(startFinder, content.length()), dateplace);

            finder++;
        }

    }


}
void Diary::insertWord(std::string word1, entry *dateplace)
{

    if(startWord == NULL)
    {

        word *add = new word;
        add->word2 = word1;
        add->parent = NULL;
        add->left = NULL;
        add->right = NULL;
        add->locations.push_back(dateplace);
        startWord = add;

    }
    else
    {
        word *finderlag = startWord;
        word *finder = startWord;
        bool added = false;
        while(added == false)
        {
            if(word1 > finder->word2)
            {
                finderlag = finder;
                finder = finder->right;
                if(finder == NULL)
                {
                    word *add = new word;
                    add->word2 = word1;
                    finderlag->right = add;
                    add->parent = finderlag;
                    add->left = NULL;
                    add->right = NULL;
                    add->locations.push_back(dateplace);
                    added = true;
                }


            }
            else if(word1 < finder->word2)
            {
                finderlag = finder;
                finder = finder->left;
                if(finder == NULL)
                {
                    word *add = new word;
                    add->word2 = word1;
                    finderlag->left = add;
                    add->parent = finderlag;
                    add->left = NULL;
                    add->right = NULL;
                    add->locations.push_back(dateplace);
                    added = true;

                }


            }
            else if(word1 == finder->word2)
            {
                  finder->locations.push_back(dateplace);
                  added = true;


            }
        }



    }


}
entry* Diary::addDate(std::string date)
{
    entry *dateplace = new entry;
    int finder = 0;
    int ending = 0;
    int counter = 0;
    for(int i = 0; i < date.length(); i++)
    {

        if(date[i] == '/')
        {
            finder = ending;
            ending = i;
            if(counter == 0)
            {
                dateplace->day = atoi(date.substr(finder, i - finder).c_str());
                counter++;
                ending++;
            }
            else if(counter == 1)
            {
                dateplace->month = atoi(date.substr(finder, i - finder).c_str());
                counter++;
                ending++;
            }
            if(counter == 2)
            {
                finder = ending;
                dateplace->year = atoi(date.substr(finder, date.length() - finder).c_str());
            }

        }
    }
    return dateplace;

}
void Diary::linear()
{
    if(start == NULL)
    {

        std::cout<<"You need to make an entry first!"<<std::cout;
        return;
    }

    entry *finder = start;
    entry *previous = finder;
    bool going = true;
    while(going)
    {
        if(finder != NULL)
        {
            std::cout<<std::endl;
            std::cout<<finder->day<<"/"<<finder->month<<"/"<<finder->year<<", "<<finder->title<<std::endl;
            std::cout<<"1 = Next"<<std::endl;
            std::cout<<"2 = Last"<<std::endl;
            std::cout<<"3 = Quit"<<std::endl;
            std::string input;
            std::cin>>input;
            int userInput = atoi(input.c_str());
            if(userInput == 1)
            {

                previous = finder;
                finder = finder->next;

            }
            if(userInput == 2)
            {
                previous = finder;
                finder = finder->prev;

            }
            if(userInput == 3)
            {

                going = false;

            }
        }
        else
        {
            std::cout<<"No Entries This Way"<<std::endl;
            std::cout<<"1 = Go Back"<<std::endl;
            std::cout<<"2 = Quit"<<std::endl;
            std::string input;
            std::cin>>input;
            int userInput = atoi(input.c_str());
            if(userInput == 1)
            {

                finder = previous;

            }
            if(userInput == 2)
            {

                going = false;

            }
        }


    }


}
void Diary::printWords()
{
    printWord(startWord);



}
void Diary::printWord(word *word)
{
    if(word != NULL)
    {
        std::cout<<"Appearances: "<<word->locations.size()<<"/ Word: "<<word->word2<<std::endl;
        printWord(word->left);
        printWord(word->right);


    }

}
void Diary::newEntry()
{
    std::cout<<"What's the date? (day/month/year form)"<<std::endl;
    std::string date;
    std::cin>>date;

    std::cout<<"Give us your entry"<<std::endl;
    std::string entry;
    getline(std::cin, entry);
    getline(std::cin, entry);

    insertEntry(entry, date);
}
void Diary::searchWords(std::string word1)
{
    if(start == NULL)
    {
        std::cout<<"You need to make an entry first!"<<std::cout;
        return;
    }
    word *finderlag = startWord;
    word *finder = startWord;
    bool added = false;
    while(added == false)
    {
        if(word1 > finder->word2)
        {
            finderlag = finder;
            finder = finder->right;
            if(finder == NULL)
            {
                std::cout<<"Word Not Found"<<std::endl;
                return;
            }

        }
        else if(word1 < finder->word2)
        {
            finderlag = finder;
            finder = finder->left;
            if(finder == NULL)
            {
                std::cout<<"Word Not Found"<<std::endl;
                return;
            }


        }
        else if(word1 == finder->word2)
        {

            std::cout<<"Instances of Your Word:"<<std::endl;

            std::cout<<std::endl;

            for(int i = 0; i < finder->locations.size(); i++)
            {
                std::cout<<"Appeared on: "<<finder->locations[i]->day<<"/"<<finder->locations[i]->month<<"/"<<finder->locations[i]->year<<std::endl;

                std::cout<<finder->locations[i]->title<<std::endl;

                std::cout<<std::endl;

            }
            return;
        }

    }



}

void Diary::printOut()
{

    std::ofstream out;

    //string filename = argv[1];

	//in2.open(filename);
    out.open(filename);
    //in2.open(filename);

    out<<password+"\n";
    entry *finder = start;
    while(finder != NULL)
    {
        int day = finder->day;
        std::stringstream ss;
        ss << day;
        std::string str = ss.str();

        int month = finder->month;
        std::stringstream ss1;
        ss1 << month;
        std::string str1 = ss1.str();

        int year = finder->year;
        std::stringstream ss2;
        ss2 << year;
        std::string str2 = ss2.str();

        out<<str+"/"+str1+"/"+str2<<","+finder->title+"\n";
        finder = finder->next;

    }
    out.close();
}

void Diary::resetDiary(){

    std::ofstream out;
    out.open(filename);

    out<<"\n";

    out.close();
}
