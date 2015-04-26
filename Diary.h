#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


#ifndef DIARY_H
#define DIARY_H

struct entry
{
    std::string title;
    int year;
    int month;
    int day;
    entry *next;
    entry *prev;

    entry(){};

};

struct word
{
    std::string word2;

    word *parent;
    word *left;
    word *right;

    std::vector<entry*> locations;

    word(){};
};

class Diary
{
    public:

        Diary();
        std::string password;
        std::string filename;

        void insertEntry(std::string in_title, std::string date);
        entry* addDate(std::string date);
        void addWords(std::string content, entry *dateplace);
        void insertWord(std::string word1, entry *dateplace);
        void deleteEntry(std::string in_title);
        void linear();
        void printWords();
        void newEntry();
        void printWord(word *word);
        void searchWords(std::string word2);
        void printOut();

        entry *start;
        entry *finish;
        word *startWord;

    protected:
    private:
};

#endif // DIARY_H
