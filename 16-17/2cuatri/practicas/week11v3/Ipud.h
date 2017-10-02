#include <iomanip>
#include <iostream>
#include <string>
#include "HashMap.h"
#include <list>
#include <stdexcept>
using namespace std;
//Typedefs 
typedef string Can;
typedef string Art;
typedef int Dur;
typedef list<Can>::iterator IterPl;
typedef list<Can>::iterator IterHi;
struct InfoSong{
	Can name;
	Art singer;
	Dur dur;
	bool isInPl;
	bool isInHist;
	IterPl refPlayList;
	IterHi refHist;
};
typedef HashMap<Can, InfoSong>::Iterator _Iter;

class Ipud{
	private:
		int _totalPlayList;
		HashMap<Can, InfoSong> _ipud;
		list<Can> _playList;
		list<Can> _history;

	public:
		Ipud();
		void addSong(Can song, Art artist, Dur dur );
		void addToPlaylist(Can song);
		Can current();
		void play();
		int totalTime();
		list<Can> recent(int n);
		void deleteSong(Can song);
		~Ipud();
};
Ipud::Ipud(){
	_totalPlayList = 0;
}
Ipud::~Ipud(){}

void Ipud::addSong( Can song, Art singer, Dur dur ){
	_Iter it = _ipud.find( song );
	if( it == _ipud.end() ){
		InfoSong info;
		info.name = song;
		info.singer = singer;
		info.dur = dur;
		info.isInPl = false;
		info.isInHist = false;
		//tiene que ir con end
		_ipud.insert(song, info );
	}else{
		throw invalid_argument("ERROR addSong");
	}
}
void Ipud::addToPlaylist(Can song){
	_Iter it = _ipud.find(song);
	if( it == _ipud.end() ) throw invalid_argument("ERROR addToPlaylist");
	else{
		list<Can>::iterator itPl = _playList.end();
		InfoSong info = it.value();
		it.value().refPlayList = _playList.insert( itPl, song);
		it.value().isInPl = true;
		/*
		if( info.isInPl ){
			_playList.erase( inf2o.refPlayList );
			it.value().refPlayList = _playList.insert( itPl, song);
		}else{
			it.value().refPlayList = _playList.insert( itPl, song);
		}*/
		_totalPlayList += it.value().dur;		
	}	
}
Can Ipud::current(){
	if( _playList.empty() ) throw invalid_argument("ERROR current");
	list<Can>::iterator itPl = _playList.begin();
	Can result = (*itPl);
	return result;
}
void Ipud::play(){
	if( _playList.empty() ){
		cout << "No hay canciones en la lista" << endl;
		return;
	}
	//pillo del playlist y la elimino tb 
	list<Can>::iterator itPl = _playList.begin();
	Can played = (*itPl);
	_playList.erase(itPl);
	//la añado a history
	_Iter it = _ipud.find( played );
	list<Can>::iterator itHist = _history.begin();
	if(it.value().isInHist){
		//elimino de la historia y la inserto
		_playList.erase( it.value().refHist );
		it.value().refHist = _playList.insert( itHist, played);
	}else{
		//solo la inserto
		it.value().refHist = _history.insert( itHist, played ); 
	}
	it.value().isInHist = true;
	it.value().isInPl = false;
	_totalPlayList -= it.value().dur;
	cout << "Sonando " << played << endl;
}
int Ipud::totalTime(){
	return _totalPlayList;
}
list<Can> Ipud::recent( int n ){
	int cont = 0;
	list<Can> result;
	list<Can>::iterator itHist = _history.begin();
	bool end = false;
	while(itHist != _history.end() && !end ){
		result.push_back((*itHist));
		cont++;
		if( cont == n ){
			end = true;
		}
		itHist++;
	}
	return result;
}
void Ipud::deleteSong(Can song){
	_Iter it = _ipud.find(song);
	if( it == _ipud.end() ) throw invalid_argument("ERROR addToPlaylist");
	else{
		_ipud.erase( it.key() );
		if(it.value().isInPl) _playList.erase(it.value().refPlayList);
		if(it.value().isInHist) _playList.erase(it.value().refHist);
	}
}