#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class PPM{
public:
    PPM();

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);

    int getMaxColorValue() const;

    const string &getType() const;

    void setType(const string &type);

    void open(const string& Name );

    void save(const string& Name );

    void GrayScale(double ,double , double);

    void menu();

    void setMaxColorValue(int maxColorValue);

    int getSize() const;

    void setSize();

    PPM operator+(const PPM& other);

    PPM(const PPM& other);

    PPM & operator=(const PPM & other);

     ~PPM();


private:
    double *Val = nullptr;
    int Height;
    int Width;
    int Size;
    int Max_Color_value ;
    string Type;

    bool CheckInfos();
};
int main() {
    PPM p1;
    p1.menu();
    return 0;
}

int PPM::getHeight() const {
    return Height;
}

void PPM::setHeight(int height) {
    Height = height;
}

int PPM::getWidth() const {
    return Width;
}

void PPM::setWidth(int width) {
    Width = width;
}

void PPM::setMaxColorValue(int maxColorValue) {
    Max_Color_value = maxColorValue;
}

int PPM::getMaxColorValue() const {
    return Max_Color_value;
}

const string &PPM::getType() const {
    return Type;
}

void PPM::setType(const string &type) {
    Type = type;
}

int PPM::getSize() const {
    return Size;
}

void PPM::setSize() {
    Size = getHeight()*getWidth()*3;
}
bool PPM::CheckInfos(){
    return (Type == "P3" && Width > 0 && Height > 0 && Max_Color_value == 255);
}
void PPM::open(const string& Name){
    //creating fstream object
    fstream file;
    // opening file
    file.open(Name);
    // checking opening is succesfull
    if (file.is_open()){
        // taking ppm infos from file
        file >> Type;
        file >> Width >> Height;
        file >> Max_Color_value;
        if(!CheckInfos()){
            cout << "Wrong PPM infos\n";
            exit(1);
        }
        setSize();
        Val = new double [getSize()];

        for (int i = 0; i < getSize(); i++) {
            file >> Val[i];
        }

        file.close();
    }
    else{
        cout << "could not opened\n";
        exit(1);
    }
}

void PPM::save(const string& Name){
    if(Val == nullptr){
        cout << "You dont open a file\n";
        exit(1);
    }
    else{
        //creating fstream object
        fstream file;
        // opening file
        file.open(Name);
        // checking opening is succesfull
        if (file.is_open()){
            // writing ppm infos to file
            file << getType() << endl << getWidth() << " " << getHeight() << endl << getMaxColorValue() << endl;
            // writing every pixel's (r g b) values
            for (int k = 0; k < getSize(); k++) {
                if(Val[k] <= 9){
                    file  << Val[k] << "   ";
                }
                else if(Val[k] <= 99){
                    file  << Val[k] << "  ";

                }
                else if(Val[k] >= 100 && Val[k] <= 255){
                    file << Val[k] << " ";
                }
                if(((k+1) % (3*(getWidth()))) == 0){
                    file << endl;
                }
                else if (((k+1) % 3) == 0){
                    file << " ";
                }
            }
            file.close();
        }
        else{
            cout << "could not opened\n";
            exit(1);
        }
    }
}
// menu function
void PPM::menu(){
    string name;
    PPM OBJECT2;
    PPM OBJECT1 = *this;
    PPM sum;
    double r ,g ,b;
    int choice = 0;
    do{
        switch (choice){
            case 0:
                cout << "MAIN MENU\n0 - Exit\n1 - Open An Image(D)\n"
                        "2 - Save Image Data(D)\n3 - Scripts(D)\n";
                cin >> choice;
                if(choice == 0){
                    exit(0);
                }
                break;
            case 1:
                cout << "OPEN AN IMAGE MENU\n0 - UP\n"
                        "1 - Enter The Name Of The Image File\n";
                cin >> choice;
                if (choice == 1){
                    cout << "Enter name of the image1\n";
                    cin >> name;
                    OBJECT1.open(name);
                    cout << "Enter name of the image2\n";
                    cin >> name;
                    OBJECT2.open(name);

                }
                else if (!(choice == 0 || choice == 1)){
                    exit(1);
                }
                break;
            case 2:
                cout << "SAVE IMAGE DATA MENU\n0 - UP\n"
                        "1 -  Enter A File Name\n";
                cin >> choice;
                if (choice == 1){
                    do
                    {
                        cout << "0 - For up Menu\n"
                                    "1 - For Image1\n"
                                        "2 - For Image2\n";
                        cin >> choice;

                        if (choice == 1)
                        {
                            cout << "Enter file name to save image1\n";
                            cin >> name;
                            OBJECT1.save(name);
                        }

                        else if (choice == 2)
                        {
                            cout << "Enter file name to save image2\n";
                            cin >> name;
                            OBJECT2.save(name);

                        }

                        else if (!(choice == 0 || choice == 1 || choice == 2)){
                            exit(1);
                        }

                    }
                    while (choice == 1 || choice == 2);
                    choice = 2;
                }
                else if (!(choice == 0 || choice == 1)){
                    exit(1);
                }
                break;
            case 3:
                cout << "SCRIPTS MENU\n0 - UP\n"
                            "1 - Convert To Grayscale(D)\n"
                                "2 - Sum of Products\n";
                cin >> choice;
                if (choice == 0) {
                  choice = 0;
                  break;
                }
                if (choice == 1){
                    do{
                        cout << "CONVERT TO GRAYSCALE MENU\n0 - UP\n"
                                "1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";
                        cin >> choice;
                        if (choice == 0) {
                          choice = 3;
                          break;
                        }
                        if (choice == 1){
                            do
                            {
                                cout << "0 - For up Menu\n"
                                            "1 - For Image1\n"
                                                "2 - For Image2\n";
                                cin >> choice;
                                if (choice == 1)
                                {
                                    cout << "Enter Coefficients For Image1.\n";
                                    cin >> r >> g >> b;
                                    OBJECT1.GrayScale(r,g,b);
                                }

                                else if (choice == 2)
                                {
                                    cout << "Enter Coefficients For Image2.\n";
                                    cin >> r >> g >> b;
                                    OBJECT2.GrayScale(r,g,b);
                                }

                                else if (!(choice == 0 || choice == 1 || choice == 2 || choice == 3)){
                                    exit(1);
                                }
                            }
                            while (choice == 1 || choice == 2);


                           if (!(choice == 0 || choice == 1)){
                                exit(1);
                           }
                        }
                    } while(choice == 1 || choice == 0);
                    choice = 3;
                    break;
                }
                if (choice == 2){
                    do
                    {
                        cout << "0 - For up Menu\n"
                                    "1 - Sum of Products\n";
                        cin >> choice;
                        if (choice == 1)
                        {
                            string savefile;
                            sum = OBJECT1 + OBJECT2;
                            cout << "Enter a filename to save sum of two image\n";
                            cin >> savefile;
                            sum.save(savefile);
                        }
                        else if (!(choice == 0 || choice == 1 )){
                            exit(1);
                        }
                    }
                    while (choice == 1 );
                    choice = 3;
                }
                else if (!(choice == 0 || choice == 1 || choice == 2)){
                    exit(1);
                }
                break;
            default:
                exit(1);
        }
    } while (choice == 0 || choice == 1 || choice == 2 || choice == 3 );
}
// default constructor
PPM::PPM()
{
    Val = nullptr;
    setHeight(0);
    setWidth(0);
    setType("no type");
    setMaxColorValue(255);
}
// turning image to grayscale
void PPM::GrayScale(double c_r, double c_g, double c_b) {
    const double MAX_COLOR_VAL = 255.0;
    if(this->Size == 0){
        // if user tries to grayscale even open an image exits
        cout << "You dont open a file\n";
        exit(1);
    }
    else {
        double R = 0,G = 0, B = 0;
        double temp;
        for (int i = 0; i < getSize(); ++i) {
            // grouping numbers by 3
            if((i)%3 == 0){
                // saving old values
                R = Val[i];
                G = Val[i+1];
                B = Val[i+2];
                // initializing new value
                temp = R * c_r + G * c_g + B *c_b;
                if (temp > MAX_COLOR_VAL){
                    temp = 255.0;
                }
                Val[i] =  Val[i+1] =  Val[i+2] = temp;
            }
        }
    }
}

PPM PPM::operator+(const PPM& other) {

    if(getSize() != other.getSize())
    {
        cout << "sizes are not equal\n";
        exit(1);
    }

    PPM sum;

    sum.Type            = Type;
    sum.Width           = Width;
    sum.Height          = Height;
    sum.Max_Color_value = Max_Color_value;
    sum.Size = Size;
    sum.Val = new double [getSize()];

    // summing images pixel by pixel
    for (int i = 0; i < getSize(); ++i)
    {
        sum.Val[i] = Val[i] + other.Val[i];
        if (sum.Val[i] > sum.Max_Color_value){
            sum.Val[i] = 255.0;
        }
    }
    return sum;
}
// copy constructor overloading
PPM::PPM(const PPM& other){
// assigning fields to the other object
    Type            = other.Type;
    Width           = other.Width;
    Height          = other.Height;
    Max_Color_value = other.Max_Color_value;
    setSize();
    Val = new double [getSize()];
    Val = other.Val;

}
// assigment operator overloading
PPM& PPM::operator=(const PPM & other)
{
  // assigning fields to the other object
    if(this == &other){
      return *this;
    }
    else {
        Type            = other.Type;
        Width           = other.Width;
        Height          = other.Height;
        Max_Color_value = other.Max_Color_value;
        setSize();
        Val = other.Val;
        return *this;
    }
}
//destructor
PPM::~PPM() {
    delete[] Val;
}
