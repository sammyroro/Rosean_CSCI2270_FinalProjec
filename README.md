# Rosean_CSCI2270_FinalProject

DairyApp

Summary:

Contains a password protected linear diary, and search method for finding occurences of words. This is achieved three fold. A linked list that contains each entry as it is added linearly, and a binary search tree that holds an array of pointers for each unique word, where the pointers lead to entries where the word occurs. So if you want to see entries where you used the word "cat" you can easily search for it. All of these entries, along with a one time chosen pasword will be saved to a text file, and read back into the program upon starting, so it doesn't delete everything each time. The Diary entries will contain a date, and a message of any length.

Interface:

This program's interface will be fairly simple, and is pretty much identical to what we've done before in class. It will display a menu like this first

=======Password======= 

(Or ask for a new password if one hasn't been set yet)


And then, if entered correctly, will lead to this menu

======Main Menu===== 
1. New Entry 
2. Search for Word
3. Review All Entries
4. Search by Date 
5. Quit

How To Run:

There are four files actually used by the program. FinalProject.cpp (The Main), Diary.cpp and Diary.h (The Graph/Stucts/Functions), and DiaryStorage.txt (The home of the diary data).

To use, just create an empty project using Codeblocks, and add the FinalProject.cpp, Diary.cpp, and Diary.h files in. Then put the DiaryStorage on the Desktop and you're set, since DiaryStorage is defaulty set up to call it as an adress on the desktop. 

Alternativly you can use DiaryStorage as a command line argument, the ability to do so is just commented out in FinalProject.cpp. Find the five blue lines and un-comment them. Then comment out whats inbetween the blue lines (Just three lines, all marked "Whats Inbetween"). Then, it should run with DiaryStorage.txt as the first command line argument.

Also, if you forget the password after initially setting it up, it can always be reset by deleting the contents offirst line of DiaryStorage, making sure to leave the empty line there.; This is where the password is stored, and the Set Password function is called whenever the first line of Storage is empty. 

Dependancies:

There will be no extra libraries needed for this program, just a functioning copy of Code Block software. Theoretically it should work in any CPP ready programming software cappable of building multiple files simultaneously.

System Requirements:

Since CodeBlocks can work on Linux/Microsoft/Apple there should be no system requirements.

Contributors:

1.
2.
3.


Open Issuses/Bugs:

There are two problems that come and go.

1. When the program is exited, the entries are reprinted onto DiaryStorage, and sometimes a random space is added to the front of the beginning of the entry, this kills the program and requires a manual fix. Either fixing it to be able to remove any starting space, or finding where that space comes from would solve the issue.

2. Sometimes when the program is exited, entries are printed into storage twice. I do not know what causes this.  

Possible Improvements:

Right now the word splitting function is rather rudemntary, only splitting around ? ! , . and on spaces. It also can't detect writing errors. Anything to make this a more robust function would be quite the improvement.
