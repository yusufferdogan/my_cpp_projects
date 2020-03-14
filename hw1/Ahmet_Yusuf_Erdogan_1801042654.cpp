/*
 * AHMET YUSUF ERDOGAN
 * 1801042654
 */

// used libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

//using statements
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::string;
using std::stoi;

/*
 * this function is used for searching elements int the array
 * this function used in creating random numbers
 * in this function ->(CreateUniq_Number)
 */

bool Search(const int arr[],int key,int length)
{
    bool found = false;
    for (int i = 0; i < length; ++i)
    {
        if(key == arr[i])
            found =  true;
    }
    return found;
}

/*
 * string version of the Search function
 * if same character exist in the string
 * it returns true
 * */

bool Search(const string& str,char c)
{
    for (char x : str){
        if (x == c)
            return true;
    }
    return false;
}

/*
 * this function is used for creating unique number
 */

int CreateUniq_Number(int length)
{
    int Currrentlenth = 0;  // counter of the length
    int temp;
    int arr[length];

    /* array is used for searching numbers
     * when i pick a number in the random part
     * i put this number in this array
     */

    while (Currrentlenth < length){
        do{

            /*
             * while we pick up numbers we compare this number with the array
             * if this number exist in the array program pick another number
             * this continue till number does not exist in the array
             * and picked number sent to array
             */

            temp = rand()%10 ;
        } while(Search(arr,temp,length) || (Currrentlenth == length - 1 && temp == 0));
        arr[Currrentlenth] = temp;
        Currrentlenth++;
    }

    /*
     * this part is creating integer with the selected numbers which is in the array
     * multiply with 10 and sum it to create integers
     */

    int uniqueNumber = 0;
    for (int i = 0; i < length; i++)
    {
        uniqueNumber += pow(10,i)*arr[i];
    }
    return uniqueNumber;
}
void Compare(int arr[],int MagicNumber,int Guess){
    /* converting numbers to string */

    string magic = to_string(MagicNumber);
    string guess = to_string(Guess);

    /*
     * assigning default values
     */

    int Cexact = 0;
    int Cmisplaced = 0;

    /*
     * counting digits if they are correct place (counter = Cmisplaced) ;
     */

    for (size_t i = 0; i < magic.length(); i++) {
        if (magic[i] == guess[i])
            Cexact++;
    }

    /*
     * counting ; digits in the guessed number if digits exist in the Magic number counter( Cmisplaced ) increases
     */

    for (size_t j = 0; j < magic.length(); ++j) {
        if (Search(magic,guess[j]))
            Cmisplaced++;
    }

    /*
     * substracting counter (which is in exact place) from counter (if exist)
     */

    Cmisplaced -= Cexact;
    arr[0] = Cexact;
    arr[1] = Cmisplaced;
}
bool isUnique(string Number)
{
    /*
     * this function is used for checking numbers is unique or not
     */
    for (size_t j = 0; j < Number.length(); ++j)
    {
        for (size_t i = j+1; i < Number.length(); ++i)
        {
            if (Number[j] == Number[i])
                return false;
        }
    }
    return true;
}
bool isNumber(string s)
{
    /*
     * checking given number has anything unwanted (like . or char (a,b,c.....z))
     */

    // starts in first char of the string ends in the last char
    for (size_t  i = 0; i < s.length(); i++)
        // if char is not digit returns false
        if (isdigit(s[i]) == false && s[0] != '-')
            return false;
    return true;
}
void MasterMind(int argc, char const *argv[]){

    //checking parameter count
    if (argc != 3)
    {
        cout << "E0\n";
        exit(1);
    }

    /*
     * initializing default values to variables
     */

    // guess variable as string
    string guess;
    // taking input as int
    int Guess;
    // to control how many moves has been
    int turn = 0;
    // to keep values of Cexact and Cmisplaced
    int Counts[2];
    // to keep value of generated random number
    int MagicNumber;
    // to count value of the digit which is in the correct place
    int Cexact;
    // to count value of the digit which is exist but not in the correct place
    int Cmisplaced;
    // digit count of the number
    int lengthofnumber;
    // maximum guess number
    const int MAX_TURN_NUMBER = 100;
    /*-------------------------------------------------------------------------------------*/
    // looking second parameters second char
    char c          = argv[1][1];
    switch (c){
        /*
         * if user enters -r case 'r' occurs
         * if user enters -u case 'u' occurs
         */
        case 'r' :
            // converting to integer and put it to the lengthofnumber variable
            lengthofnumber =  atoi(argv[2]);

            /*
             * if length is more than 9 or less or equal than 0 or has anything unwanted prints and exit program
             */

            if (lengthofnumber > 9 || lengthofnumber <= 0 || !isNumber(argv[2]))
            {
                cout << "E0\n";
                exit(1);
            }

            /*
             * if everything is ok creates number
             */

            else{
                MagicNumber    =  CreateUniq_Number(lengthofnumber);
            }
            break;

        case 'u' :

            /*
             * checks given string as Magicnumbers lenght and put it to the lenghtofnumber variable
             * and converts this number to integer and put it to the MagicNumber variable
             */

            lengthofnumber  = strlen(argv[2]);
            MagicNumber     = atoi(argv[2]);

            /*
             * if number is not unique  or first digit is 0 or number is smaller than 0
             * or has anything unwanted prints and exit program
             */

            if (!isUnique(argv[2]) || argv[2][0] == '0' || MagicNumber <= 0 || !isNumber(argv[2]))
            {
                cout << "E0\n";
                exit(1);
            }
            break;

        default:
           cout << "E0\n";
           exit(1);
    }
    /*-------------------------------------------------------------------------------------*/

    do{
        // taking input from user for guessing
        cin  >> guess;
        // converting string to int
        Guess = stoi(guess);

        /*
         * Guess is a integer if user try to enter something different than int
         * prints e2 and exit
         */

        if (!isNumber(guess))
        {
            cout << "E2\n";
            exit(1);
        }

        /*
         * if user enters a number which lesser or greater than is should be
         * prints e1 and exit
         */

        if (static_cast<size_t>(lengthofnumber) != guess.length() || guess[0] == '0' || !isUnique(guess) ||  Guess <= 0 )
        {
            cout << "E1\n";
            exit(1);
        }

        /*
         * if user's guess lesser than 0 or not unique
         * prints 0 and exit
         */

        /*
         * calculating Cexact and Cmisplaced
         */

        Compare(Counts,MagicNumber,Guess);
        Cexact      = Counts[0] ;
        Cmisplaced  = Counts[1] ;

        //increasing turn count
        turn++;

        /*
         * if every digit is in the correct place game ends
         * print found and turn count and exit
         */

        if (Cexact == lengthofnumber)
        {
            cout << "FOUND " << turn << endl;
        }

        /*
         * if user can not find the magic number within the maximum trial count
         * prints Failed and exit
         */

        else if(turn >= MAX_TURN_NUMBER)
        {
            cout << "FAİLED\n";
        }

        /*
         * prints Cexact and Cmisplaced seperated by space
         */

        else {
            cout << Cexact <<  " "  << Cmisplaced  << endl;
        }

    } while(Cexact != lengthofnumber && turn < MAX_TURN_NUMBER);
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    MasterMind(argc,argv);
    return 0;
}
