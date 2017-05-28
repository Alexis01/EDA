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
		int totalDuracionPlayList;
		HashMap<Can, InfoSong> _ipud;
		list<Can> _playList;
		list<Can> _history;

	public:
		Ipud();
		void addSong(Can song, Art artist, Dur dur );
		void addToPlaylist(Can song);
		~Ipud();
		

	
};
Ipud::Ipud(){}
Ipud::~Ipud(){}
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
	if( it == _ipud.end() ) throw invalid_argument("ERROR addToPlaylist");
	else{
		list<Can>::iterator itPl = _playList.find( song );
		if( itPl != _playList.end() ) throw invalid_argument("ERROR addToPlaylist");
		else{
			_playList.push_back(song);
		}
	}	
}
