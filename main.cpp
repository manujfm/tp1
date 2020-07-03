#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
const int MAX_COUNTRY = 20;


struct country {
    string countryName;
    string continent;
    int people;
    void print() const {
        cout << " Pais: " << countryName << " - ";
        cout << " Continente: "<< continent << " - ";
        cout << " Personas: "<< people << endl;
    }
};


void splitLineOfCountry(string const line, string countryArray []){
    string newLine;
    int len, space;
    space  = line.find(" ");
    len  = line.length();
    countryArray[0] = line.substr(0, space);
    space = line.find(" ");
    newLine = line.substr(space + 1, len+1);
    countryArray[1] = newLine.substr(0 ,newLine.find(" "));
    space = newLine.find(" ");
    len = newLine.length();
    countryArray[2] = newLine.substr(space,len);
};


int main() {
    ifstream MyReadFile("/home/manu/UTN/TP1New/Paises.txt");
    string line;
    country countrys[MAX_COUNTRY];
    string countryArray[3];
    int i;

    cout << "Generando Archivos..." << endl;

    if (MyReadFile.is_open()){
        for ( i = 0; i < MAX_COUNTRY; i++ ){
            getline(MyReadFile,line);
            splitLineOfCountry(line, countryArray);
            countrys[i].countryName = countryArray[0];
            countrys[i].continent = countryArray[1];
            countrys[i].people = atoi(countryArray[2].c_str());
            countrys[i].print();
        };
        MyReadFile.close();
    } else {

        cout << "Unable to open file";
    }
    return 0;
}
