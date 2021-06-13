/*
Write a program that reads a file consisting of students’ test scores in the range 0–200. 
It should then determine the number of students having scores in each of the following ranges: 
0–24, 25–49, 50–74, 75–99, 100–124, 125–149, 150–174, and 175–200. 
Output the score ranges and the number of students. 
(Run your program with the following input data: 
76, 89, 150, 135, 200, 76, 12, 100, 150, 28, 178, 189, 167, 200, 175, 150, 87, 99, 129, 149, 176, 200, 87, 35, 157, 189.)
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int maxCategory = 8; 
int getCategory(int);
void initialize(int student[]);
void getStudent(int category, int student[]);
void printArray(int category, int student[]);

int main()
{
   int category;
   int score;
   int student[maxCategory];
   ifstream infile;
   infile.open("score.txt");

   if(!infile)
   {
      cout << "Cannot open input file." << endl;
      system("pause");
      return 0;
   }
   initialize(student);
   infile>>score;

   while (!infile.eof())
   {
      category = getCategory(score);
      getStudent(category, student);

      infile>>score;
   }
   infile.close();
   printArray(category, student);

   system("pause");
   return 0;
}

void initialize(int student[])
{
   int j;
   for(j = 0; j < maxCategory; j++) 
   {
      student[j] = 0;
   }
}

void getStudent(int c, int s[])
{
   if (c < maxCategory)
   {
      s[c]++;
   }
}
void printArray(int category, int student[])
{
   string scoreRange;
   cout << "Score Range" << " ";
   cout << "Number of Students" << endl;

   for (category = 0; category < maxCategory; category++) 
   {
      switch(category)
      {
         case 0:
         scoreRange="0-24";
         break;
         case 1:
         scoreRange="25-49";
         break;
         case 2:
         scoreRange="50-74";
         break;
         case 3:
         scoreRange="75-99";
         break;
         case 4:
         scoreRange="100-124";
         break;
         case 5:
         scoreRange="125-149";
         break;
         case 6:
         scoreRange="150-174";
         break;
         case 7:
         scoreRange="175-200";
         break;
      }
      cout << scoreRange << " ";
      cout << student[category] << endl;
   }
}

int getCategory(int score)
{
   int scoreRange;

   if (score>=0 && score<25)
      scoreRange=0;
   else if (score>=25 && score<50)
      scoreRange=1;
   else if (score>=50 && score<75)
      scoreRange=2;
   else if (score>=75 && score<100)
      scoreRange=3;
   else if (score>=100 && score<125)
      scoreRange=4;
   else if (score>=125 && score<150)
      scoreRange=5;
   else if (score>=150 && score<175)
      scoreRange=6;
   else if (score>=175 && score<=200)
      scoreRange=7;
   else
      cout << "Out of range 0-200\n"; 
   return scoreRange;
}