//  Trivia Game
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Question
{
    private:
        string questionText;
        string possibleAnswers[4];
        int correctAnswer;


    public:

        Question()
        { }


        string getQuestion()
        {
            return questionText;
        }

        string getPossAnswer1()
        {
            return possibleAnswers[0];
        }

        string getPossAnswer2()
        {
            return possibleAnswers[1];
        }

        string getPossAnswer3()
        {
            return possibleAnswers[2];
        }

        string getPossAnswer4()
        {
            return possibleAnswers[3];
        }

        int getCorrectNumber()
        {
            return correctAnswer;
        }

        string getCorrectAnswer()
        {
            return possibleAnswers[correctAnswer-1];
        }


        void setQuestionText(string q)
        {
            questionText = q;
        }

        void setPossAnswer1(string ans)
        {
            possibleAnswers[0] = ans;
        }

        void setPossAnswer2(string ans)
        {
            possibleAnswers[1] = ans;
        }

        void setPossAnswer3(string ans)
        {
            possibleAnswers[2] = ans;
        }

        void setPossAnswer4(string ans)
        {
            possibleAnswers[3] = ans;
        }

        void setCorrect(int correctNum)
        {
            correctAnswer = correctNum;
        }
};


void initQuestions(Question [], int);
void displayQuestion(Question);

int main()
{
    const int NUM_QUESTIONS = 10;
    int playerOnePoints = 0;
    int playerTwoPoints = 0;


    Question questions[NUM_QUESTIONS];


    initQuestions(questions, NUM_QUESTIONS);


    int questionNum = 0;
    while (questionNum < 10)
    {
        int answer;


        cout << "Question for PLAYER 1:\n";
        cout << "----------------------\n";
        displayQuestion(questions[questionNum]);
        cout << "Enter the correct answer: "; cin >> answer;


        if (answer == questions[questionNum].getCorrectNumber())
        {
            cout << "Correct!\n\n";
            playerOnePoints++;
        }
        else
        {
            cout << "Sorry, that's incorrect. The correct answer is "
                 << questions[questionNum].getCorrectNumber() << ". "
                 << questions[questionNum].getCorrectAnswer()
                 << endl << endl;
        }


        questionNum++;


        cout << "Question for PLAYER 2:\n";
        cout << "----------------------\n";
        displayQuestion(questions[questionNum]);
        cout << "Enter the correct answer: "; cin >> answer;


        if (answer == questions[questionNum].getCorrectNumber())
        {
            cout << "Correct!\n\n";
            playerTwoPoints++;
        }
        else
        {
            cout << "Sorry, that's incorrect. The correct answer is "
                 << questions[questionNum].getCorrectNumber() << ". "
                 << questions[questionNum].getCorrectAnswer()
                 << endl << endl;
        }


        questionNum++;
    }


    cout << "Game over. Here are the points:\n";
    cout << "PLAYER 1: " << playerOnePoints << endl;
    cout << "PLAYER 2: " << playerTwoPoints << endl << endl;
    if (playerOnePoints > playerTwoPoints)
    {
        cout << "PLAYER 1 WINS!\n"; } else if (playerTwoPoints > playerOnePoints)
    {
        cout << "PLAEYR 2 WINS!\n";
    }
    else
    {
        cout << "It's a tie!\n";
    }

    return 0;
}



void initQuestions(Question quest[], int size)
{
   const int SIZE = 500;
   char input[SIZE];
   fstream inputFile;
   int index = 0;


   inputFile.open("trivia.txt", ios::in);
   if (!inputFile)
   {
      cout << "ERROR: Cannot open trivia file.\n";
      exit(0);
   }


   inputFile.getline(input, SIZE);
   while (!inputFile.eof() && index < size)
   {

        quest[index].setQuestionText(input);


        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer1(input);


        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer2(input);


        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer3(input);


        inputFile.getline(input, SIZE);
        quest[index].setPossAnswer4(input);


        inputFile.getline(input, SIZE);
        quest[index].setCorrect(atoi(input));


        index++;


        inputFile.getline(input, SIZE);
   }
}



void displayQuestion(Question quest)
{
    cout << quest.getQuestion() << endl;
    cout << "ANSWERS:\n";
    cout << "1. " << quest.getPossAnswer1() << endl;
    cout << "2. " << quest.getPossAnswer2() << endl;
    cout << "3. " << quest.getPossAnswer3() << endl;
    cout << "4. " << quest.getPossAnswer4() << endl;
}
