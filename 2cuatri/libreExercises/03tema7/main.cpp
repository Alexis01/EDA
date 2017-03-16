#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <list>
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
void printSol(vector<string> sol){
    int i = 0;
    while( i < sol.size() ){
        cout << sol[i] << endl;
        i++;
    }
    cout << "---" << endl;
}
void getDataFromLine( string line, int &horas, int &minutos, int &segundos){
    vector<string> hour = split(line, ':');
    horas = atoi(hour[0].c_str());
    minutos = atoi(hour[1].c_str());
    segundos = atoi(hour[2].c_str());
}
void solve( list<Hours*> trenes, Hours *buscamos, vector<string> &sol ){
    int i = 0;
    bool found = false;
    list<Hours*>::iterator it = trenes.begin();
    while( it != trenes.end() && !found){
        ostringstream stream;
        Hours *_tmp = (*it);
        if( *buscamos < *_tmp || *buscamos == *_tmp ){
            stream << *(_tmp);
            sol.push_back( stream.str() );
            found = true;
        }
        //delete _tmp;
        it++;
    }
    if(!found){
        sol.push_back( "NO" );
    }
}
void cleanTrenes( list<Hours*> trenes ){
    list<Hours*>::iterator it = trenes.begin();
    while( it != trenes.end() ){
        ostringstream stream;
        Hours *_tmp = (*it);
        delete _tmp;
        it++;
    }
}


int main(){
    int numTrenes, numHoras; 
    cin >> numTrenes;
    cin >> numHoras;
    while( numTrenes != 0 && numHoras!=0 ){
        vector<string> sol;
        list<Hours*> listTrains;
        string linea;
        int j = 0;
        while( j < numTrenes ){
            int horas, minutos, segundos;
            cin >> linea;
            getDataFromLine(linea, horas, minutos, segundos);
            Hours *hora = new Hours(horas, minutos, segundos);
            listTrains.push_back(hora);
            j++;
        }
        j = 0;
        while(j < numHoras){
            
            int horas, minutos, segundos;
            cin >> linea;
            getDataFromLine(linea, horas, minutos, segundos);
            try{
                Hours *hora;
                hora = new Hours(horas, minutos, segundos);
                solve(listTrains, hora, sol);
                delete hora;
            }catch (ExcepcionTAD& e){
                //cout << "ERROR: " << e.msg() << endl;
                sol.push_back( "ERROR" );
            }
            j++;
        }
        cleanTrenes(listTrains);
        printSol(sol);
        cin >> numTrenes;
        cin >> numHoras;
    }
    return 0;
}

/*
int horas, minutos, segundos;
vector<string> trains = split(linea, ' ');
vector<string>::iterator it;
for(it=trains.begin() ; it < trains.end(); it++) {
    string hour = *it;
    getDataFromLine(hour, horas, minutos, segundos);
}*/
/*cin.get(c);
getline(cin,linea);*/