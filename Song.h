//DOCUMENT HERE

#ifndef SONG_H
#define SONG_H
#include<string>
#include<iostream>

using namespace std;

class Song{
	private: 
		string title;
		string artist;
		int memory;

		static const int MAX_MEM = 512;
	public:
		Song();
		Song(string artist, string title, int memory);
		string getTitle() const{
			return title;
		}
		string getArtist() const{
			return artist;
		}
		int getMemory() const{
			return memory;
		}
		void setTitle(string _title){
			title=_title;
		}
		void setArtist(string _artist){
			artist=_artist;
		}
		void setMemory(int _memory){
			if(_memory<0 || _memory>512)
				memory = MAX_MEM;
			else
				memory=_memory;
		}
		void swap(Song &p);
		bool operator >(Song const &rhs);
		bool operator ==(Song const &rhs);
		//ostream& operator << (ostream& out, const Song &s);

		~Song();


};


#endif