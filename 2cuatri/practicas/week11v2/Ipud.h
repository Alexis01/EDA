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
struct InfoSong{
	Can name;
	Art singer;
	Dur dur;
	bool isInPl;
	bool isInHist;
	list<Can>::iterator refPlayList;
	list<Can>::iterator refHist;
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
		void addSong(const Can& song, const Art& artist, const Dur& dur );
		void addToPlaylist(const Can& song);
		Can current() const;
		Can play();
		int totalTime() const;
		list<Can> recent(unsigned int& n) const;
		void deleteSong(const Can& song);
		~Ipud();
};
Ipud::Ipud(){
	_totalPlayList = 0;
}
Ipud::~Ipud(){}

void Ipud::addSong( const Can& song, const Art& artist, const Dur& dur ){
	
	if( !_ipud.contains( song ) ){
		InfoSong info;
		info.name = song;
		info.singer = artist;
		info.dur = dur;
		info.isInPl = false;
		info.isInHist = false;
		_ipud.insert(song, info );
	}else{
		throw invalid_argument("addSong");
	}
}
void Ipud::addToPlaylist(const Can& song){
	_Iter it = _ipud.find(song);
	if( it == _ipud.end() ) throw invalid_argument("addToPlaylist");
	else{
		list<Can>::iterator itPl = _playList.end();
		InfoSong info = it.value();
		if( !info.isInPl ){
			itPl = _playList.insert( itPl, song);
			it.value().refPlayList = itPl;
			it.value().isInPl = true;
			_totalPlayList += it.value().dur;
		}
				
	}	
}
Can Ipud::current() const{
	if( _playList.empty() ) throw invalid_argument("current");
	return _playList.front();
}
Can Ipud::play(){
	Can song;
	if( !_playList.empty() ){
		//pillo del playlist y la elimino tb
		song = _playList.front();
		_Iter it = _ipud.find( song );
		it.value().isInPl = false;
		it.value().refPlayList = _playList.end();
		//la añado a history
		if(it.value().isInHist){
			//elimino de la historia y la inserto
			_playList.erase( it.value().refHist );	
		}
		it.value().isInHist = true;
		//solo la inserto
		list<Can>::iterator itHist = _history.begin();
		itHist =  _history.insert( itHist, song ); 
		it.value().refHist = itHist;
		_totalPlayList -= it.value().dur;
		_playList.pop_front();
	}else{
		throw invalid_argument("play");
	}
	return song;
}
int Ipud::totalTime() const{
	return _totalPlayList;
}
list<Can> Ipud::recent( unsigned int& n ) const{
	list<Can> auxList;
	if (_history.size() == 0) {
		n = 0;
	}
	else if (n > _history.size()) {
		return _history;
	}
	else {
		list<Can>::const_iterator it = _history.cbegin();
		for (unsigned int i = 0; i < n; i++) {
			auxList.push_back(*it);
			++it;
		}
	}

	return auxList;
}
void Ipud::deleteSong(const Can& song){
	_Iter it = _ipud.find(song);
	if( it == _ipud.end() ) throw invalid_argument("ERROR addToPlaylist");
	else{
		_ipud.erase( it.key() );
		if(it.value().isInPl) _playList.erase(it.value().refPlayList);
		if(it.value().isInHist) _playList.erase(it.value().refHist);
	}
}