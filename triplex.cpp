#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty) 
{
    //prompt
    std::cout << "Yo you awake?" << std::endl;
    std::cout << "You are a secret agent breaking in a level " << Difficulty << std::endl;    
    std::cout << "Can you help me?" << std::endl;

}
bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);
    //code numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The numbers add up to " << CodeSum << std::endl;
    std::cout << "The numbers multiply up to " << CodeProduct << std::endl;

    std::cout << "Enter the numbers here" << std::endl;

    //user's guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check
    if (CodeSum == GuessSum && CodeProduct == GuessProduct) 
    {
        std::cout << "Correct! " << std::endl;
        return true;
    }
    else{
        std::cout << "Incorrect try again" << std::endl;
        return false;
    }
}



int main() 
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxDifficulty = 10;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
        
    }
    std::cout << "\n Great work Agent! You've gotten out \n";
    
    
    return 0;
}