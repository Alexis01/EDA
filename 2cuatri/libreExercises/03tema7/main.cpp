#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include "Hours.h"

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void getDataFromLine( string line, int &horas, int &minutos, int &segundos){
    vector<string> hour = split(line, ':');
    horas = atoi(hour[0].c_str());
    minutos = atoi(hour[1].c_str());
    segundos = atoi(hour[2].c_str());
}
int main(){
    int numTrenes, numHoras;
    string linea;
    stack<Hours*> stackTrains;
    char c;
    cin >> numTrenes;
    cin >> numHoras;
    /*cin.get(c);
    getline(cin,linea);*/
    while( numTrenes != 0 && numHoras!=0 ){
        int j = 0;
        while( j != numTrenes ){
            int horas, minutos, segundos;
            cin >> linea;
            getDataFromLine(linea, horas, minutos, segundos);
            Hours *hora = new Hours(horas, minutos, segundos);
            stackTrains.push(hora);
            j++;
        }

        /*
        int horas, minutos, segundos;
        vector<string> trains = split(linea, ' ');
        vector<string>::iterator it;
        for(it=trains.begin() ; it < trains.end(); it++) {
            string hour = *it;
            getDataFromLine(hour, horas, minutos, segundos);
        }*/
        
        cin >> numTrenes;
        cin >> numHoras;
        /*cin.get(c);
        getline(cin,linea);*/
    }
    while( !stackTrains.empty() ){
       Hours *_tmp = stackTrains.top();
       cout << *(_tmp) << endl;
       delete _tmp;
       stackTrains.pop();
    }
    return 0;
}