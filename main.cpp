#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAX_COUNTRY = 20;


struct country {
    char countryName[20];
    char continent[10];
    int people;
    void print() const {
        cout << " Pais: " << countryName << " - ";
        cout << " Continente: "<< continent << " - ";
        cout << " Personas: "<< people << endl;
    }
};


//void splitLineOfCountry(string const line, string countryArray []){
//    string newLine;
//    int len, space;
//    space  = line.find(" ");
//    len  = line.length();
//    countryArray[0] = line.substr(0, space);
//    space = line.find(" ");
//    newLine = line.substr(space + 1, len+1);
//    countryArray[1] = newLine.substr(0 ,newLine.find(" "));
//    space = newLine.find(" ");
//    len = newLine.length();
//    countryArray[2] = newLine.substr(space,len);
//};
//
//void readCountryFile(ifstream &file, struct country countries[]){
//    string countryArray[3];
//    string line;
//    int i;
//    for (i = 0; i < MAX_COUNTRY; i++) {
//        getline(file, line);
//        splitLineOfCountry(line, countryArray);
//        countries[i].countryName = countryArray[0];
//        countries[i].continent = countryArray[1];
//        countries[i].people = atoi(countryArray[2].c_str());
//        countries[i].print();
//    };
//}
//
//void openFile(FILE **file, const char* filename, const char* const mode) {
//    *file = fopen(filename, "rb");
//}


int main() {
    FILE *countryFile;
    country countries,countries_2[20];
    cout << "Generando Archivos..." << endl;
    countryFile = fopen("/home/manu/UTN/TP1New/Paises2.txt", "rw+");
    string countries_names[20] = {"Venezuela","Bolivia","Peru","Argentina","Uruguay","Paraguay","Colombia","España","Paris","Italia","Portugal","Mexico","Panama","China","Japon","Rusia","Canada","Brasil","Chile","Inglaterra",};
    string continet[20] = {"America","America","America","America","America","America","America","Europa","Europa","Europa","Europa","America","America","Asia","Asia","Asia","America","America","America","Europa",};
    int i;
//    for (i = 0; i< 20; i++) {
//        strcpy(countries_2.countryName, countries_names[i].c_str());
//        strcpy(countries_2.continent, continet[i].c_str());
//        countries_2.people = 3000;
//        fwrite(&countries_2, sizeof(country), 1, countryFile);
//        fwrite("\n", sizeof("\n"), 1, countryFile);
//    }
    if (countryFile != NULL){
        while (!feof(countryFile)){
          fread(&countries_2[i], sizeof(country), 1, countryFile);
          countries_2[i].print();
          i++;
        }
    }
    fclose(countryFile);
    return 0;
}
