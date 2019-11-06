#include "Song.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include<string>

using namespace std;

	Song::Song(){
		title = "xxx";
		artist = "xxx";
		memory = 0;
	}
	Song::Song(string _artist, string _title, int _memory){
		title = _title;
		artist = _artist;
		memory = _memory;
	}
	void Song::swap(Song &s2){
		Song temp(s2.getArtist(), s2.getTitle(), s2.getMemory());
		s2.setTitle(title);
		s2.setArtist(artist);
		s2.setMemory(memory);
		title=temp.getTitle();
		artist=temp.getArtist();
		memory=temp.getMemory();
	}
	bool Song::operator >(Song const &rhs){
		if(artist<rhs.artist)
			return true;
		else if(rhs.artist<artist)
			return false;
		else if(title<rhs.title)
			return true;
		else if(rhs.title<title)
			return false;
		else if(memory<rhs.memory)
			return true;
		else if(rhs.memory<memory)
			return false;
		else
			return false;
	}
	bool Song::operator ==(Song const &rhs){
		if(title == rhs.title && artist == rhs.artist && memory == rhs.memory)
			return true;
		else 
			return false;
	}
	/*ostream& Song::operator << (ostream& out, const Song &s){
		out << "Title - " << s.getTitle() << ", Artist - " << s.getArtist() << ", Memory - " << s.getMemory();
		return out;
	}*/
	Song::~Song(){
	}
