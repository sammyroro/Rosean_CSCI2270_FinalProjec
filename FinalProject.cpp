#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Diary.h"

using namespace std;

int main(int argc, char *argv[])
{

    int x = 0;
    Diary diary = Diary();
    ifstream in;
    //string filename = argv[1];
    //diary.filename = filename;

	in.open("/home/user/Desktop/DiaryStorage.txt"); // Whats Inbetween
	diary filename = "/home/user/Desktop/DiaryStorage.txt"; // Whats Inbetween

	//in.open(filename);


    if (in.is_open())
    {

        int onlyFirstLine = 0;
        string line;
		while(getline(in, line))
		{

            if(line.empty() && onlyFirstLine == 0)
            {

                in.close();
                ofstream out;
                out.open("/home/user/Desktop/DiaryStorage.txt");
                string UserInput;
                cout<<"=====Set Your Password====="<<endl;
                cin>>UserInput;
                out<<UserInput;
                out.close();

            }
            onlyFirstLine++;
		}
    }
    ifstream in2;
    //string filename = argv[1];

	in2.open("/home/user/Desktop/DiaryStorage.txt"); // Whats Inbetween

	//in2.open(filename);

    if(in2.is_open())
	{

		string line;
		while(getline(in2, line))
		{
		    if(x == 0)
            {
                diary.password = line;
                bool pass = false;
                while(pass==false)
                {
                    string UserInput;
                    cout<<"=====Password====="<<endl;
                    cin>>UserInput;
                    if(UserInput == line)
                    {

                        pass = true;

                    }
                    else
                    {
                        cout<<"Try Again"<<endl;


                    }

                }
                x++;
            }
            else
            {


                int finder = 0;
                string place;
                for(int i = 0; i < line.length(); i++)
                {

                    bool found = false;
                    if(line[i] == ',' && found == false)
                    {

                        finder = i;
                        string date = line.substr(0, i);
                        string content = line.substr(i+1, line.length()-i);
                        found = true;

                        diary.insertEntry(content, date);

                    }
                }

            }
		}

	}



    bool going = true;

    while(going == true)
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. New Entry"<<endl;
        cout<<"2. Search for Word"<<endl;
        cout<<"3. Review Entries"<<endl;
        cout<<"4. Print All Words"<<endl;
        cout<<"5. Quit"<<endl;
        string input;
        cin>>input;
        int userInput = atoi(input.c_str());
        if(userInput == 1)
        {

            diary.newEntry();

        }
        if(userInput == 2)
        {

            cout<<"Enter the Word You're Looking For:"<<endl;
            string testString;
            cin>>testString;
            diary.searchWords(testString);

        }
        if(userInput == 3)
        {

            diary.linear();

        }
        if(userInput == 4)
        {

            diary.printWords();

        }
        if(userInput == 5)
        {

            going = false;
            cout<<"Goodbye!"<<endl;
            diary.printOut();

        }
    }








}
