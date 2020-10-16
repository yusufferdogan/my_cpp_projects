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

private:
    vector<double>Val;
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
    //string name = "/home/yusuf/CLionProjects/Hw2/";
    //name += Name;
    //temp.open(Name);
    string comment;
    // opening file
    file.open(Name);
    // checking opening is succesfull
    if (file.is_open()){
        // taking ppm infos from file
        file >> Type;
        file >> comment;
        file >> Width;
        file >> Height;
        file >> Max_Color_value;
        
        cout << getType() << endl << getWidth() << " " << getHeight() << endl << getMaxColorValue() << endl;

        if(!CheckInfos()){
            cout << "Wrong PPM infos\n";
            exit(1);
        }
        setSize();
        Val.resize(getSize());

        for (int i = 0; i < getSize(); i++) {
            file >> Val[i];
        }

        file.close();
    }
    else{
        exit(1);
    }
}

void PPM::save(const string& Name ){
    if(Val.empty()){
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
                if(Val[k] < 9){
                    file  << Val[k] << "   ";
                    //cout  << Val[k] << "   ";
                }
                else if(Val[k] < 99){
                    file   << Val[k] << "  ";
                    //cout   << Val[k] << "  ";
                }
                else {
                    file   << Val[k] << " ";
                    //cout   << Val[k] << " ";
                }
                if(((k+1) % (3*(getWidth()))) == 0){
                    file << endl;
                    //cout << endl;
                }
                else if (((k+1) % 3) == 0){
                    file << " ";
                    //cout << " ";
                }
            }
            file.close();
        }
        else{
            exit(1);
        }
    }
}
// menu function
void PPM::menu(){
    string name;
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
                cin >> name;
                open(name);
            }
            else if (!(choice == 0 || choice == 1)){
                exit(1);
            }
            break;
        case 2:
            cout << "SAVE IMAGE DATA MENU\n0 - UP\n"
                    "1 - Enter A File Name\n";
            cin >> choice;
            if (choice == 1){
                cin >> name;
                save(name);
                choice = 2;
            }
            else if (!(choice == 0 || choice == 1)){
                exit(1);
            }
            break;
        case 3:
            cout << "SCRIPTS MENU\n0 - UP\n"
                    "1 - Convert To Grayscale(D)\n";
            cin >> choice;
            if (choice == 1){
                do{
                    cout << "CONVERT TO GRAYSCALE MENU\n0 - UP\n"
                            "1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";
                    cin >> choice;
                    if (choice == 1){
                        cin >> r >> g >> b;
                        GrayScale(r,g,b);
                    }
                    if (choice == 0){
                        choice = 3;
                        break;
                    }
                    else if (!(choice == 0 || choice == 1)){
                        exit(1);
                    }

                } while(choice == 1 || choice == 0);
            }
            else if (!(choice == 0 || choice == 1)){
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
    Val.resize(0);
    setHeight(0);
    setWidth(0);
    setType("no type");
    setMaxColorValue(255);
}
// turning image to grayscale
void PPM::GrayScale(double c_r, double c_g, double c_b) {
    const double MAX_COLOR_VAL = 255.0;
    if(Val.empty()){
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
