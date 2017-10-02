#include <string>
#include "HashMap.h"
#include <list>

using namespace std;

typedef string Can;
typedef string Art;
typedef int Dur;

struct InfoSong{
	Can name;
	Art singer;
	Dur dur;
	//bool estaEnPlayList
	//bool estaEnReproducidas
	//puntero en playlist a null
	//puntero en reproducidas a null
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
		Can play();
		int totalTime();
		list<Can> recent(int n);
		~Ipud();
		

	
};
Ipud::Ipud(){
	_totalPlayList = 0;
}
Ipud::~Ipud(){}
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
int Ipud::totalTime(){
	return _totalPlayList;
}
Can Ipud::play(){
	if( _playList.empty() ) throw invalid_argument("ERROR play empty");
	list<Can>::iterator itPl = _playList.begin();
	Can played = (*itPl);
	_playList.erase(itPl);
	//result
	list<Can>::iterator itHist = _history.begin();
	bool found = false;
	while(itHist != _history.end() && !found ){
		if( (*itHist) == played ){
			found = true;
			_history.push_front(played);
		}
		itHist++;
	}
	_Iter it = _ipud.find( played );
	_totalPlayList -= it.value().dur;
	return played;
}
Can Ipud::current(){
	if( _playList.empty() ) throw invalid_argument("ERROR current empty");
	list<Can>::iterator itPl = _playList.begin();
	Can result = (*itPl);
	//_playList.erase(itPl);
	return result;
}
void Ipud::addSong( Can song, Art singer, Dur dur ){
	_Iter it = _ipud.find( song );
	if( it == _ipud.end() ){
		InfoSong info;
		info.name = song;
		info.singer = singer;
		info.dur = dur;
		_ipud.insert(song, info );
	}else{
		throw invalid_argument("ERROR addSong");
	}
}
void Ipud::addToPlaylist(Can song){
	_Iter it = _ipud.find(song);
	if( it == _ipud.end() ) throw invalid_argument("ERROR addToPlaylist ipud");
	else{
		list<Can>::iterator itPl = _playList.begin();
		bool found = false;
		while(itPl != _playList.end() && !found ){
			if( (*itPl) == song ){
				found = true;
			}
			itPl++;
		}
		if( found ) throw invalid_argument("ERROR addToPlaylist playlist duplicada");
		else{
			_totalPlayList += it.value().dur;
			_playList.push_back(song);
		}
	}	
}
/*
g++ -std=c++11 main.cpp -o main
List<int>::Iterator it = l->begin();
	int sumaParcial = 0;
	while (it != l->end()){
		if ( it.elem() == sumaParcial ){
			//insertar at 
			l->insert(it.elem(),it);
			contCasos++;

		}
		sumaParcial += it.elem();
		it.next();
	}

*/