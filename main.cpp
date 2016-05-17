//libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//run this program using the console pauser or add your own getch, system("pause") or input loop

//default
using namespace std;

//Player class
class Player
{
private:
    string name;
    int playerScore;

public:
    void setName(string n);
    string getName();
    void setPlayerScore(int p);
    int getPlayerScore();
};

//prototypes
void getHighScores(Player scoresPlayer[]);
void sortArray(Player scoresPlayer[]);

//main function
int main(int argc, char** argv)
{
    //Player array
    Player scoresPlayer[20];

    //calling functions
    getHighScores(scoresPlayer);

    //header
    cout<<setw(12)<< "Name"<<setw(12)<<"Score"<<endl;

    //print
    for(int i=0;i<6;i++)
    {
        cout<<setw(12)<<scoresPlayer[i].getName();
        cout<<setw(12)<<scoresPlayer[i].getPlayerScore()<<endl;
    }

    //return
    return 0;
}

//setName
void Player :: setName(string n)
{
    name = n;
}

//getName
string Player :: getName()
{
    return name;
}

//setPlayerScore
void Player :: setPlayerScore(int p)
{
    playerScore = p;
}

//getPlayerScore
int Player :: getPlayerScore()
{
    return playerScore;
}

//getHighScores
void getHighScores(Player scoresPlayer[])
{
    //variables
    int numScore=0, curScore;
    string curName;
    ifstream myReadFile;
    myReadFile.open("scores.txt");

    //reading file and loading array
    while(myReadFile >> curName)
    {
        myReadFile >> curScore;
        scoresPlayer[numScore].setName(curName);
        scoresPlayer[numScore].setPlayerScore(curScore);
        ++numScore;
    }

    sortArray(scoresPlayer);
    myReadFile.close();
}

//sortArray
void sortArray(Player scoresPlayer[])
{
    Player temp;

    for(int i = 0; i<6; i++)
    {
        for(int j = i +1; j <6; j++)
        {
            if(scoresPlayer[i].getPlayerScore() < scoresPlayer[j].getPlayerScore())
            {
                temp = scoresPlayer[j];
                scoresPlayer[j] = scoresPlayer[i];
                scoresPlayer[i] = temp;
            }
        }
    }
}
