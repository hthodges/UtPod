#include "Song.h"
#include "UTpod.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod::UtPod(){
      	songs = NULL;
      	memSize = MAX_MEMORY;
      	//SEED RNG
      	srand(time(NULL));
      }

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod::UtPod(int size){
      	songs = NULL;
      	if(size>0 && size<=512){
      		memSize = size;
      	}
      	else
      		memSize = MAX_MEMORY;
      	//SEED RNG
      	srand(time(NULL));
      }

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms -

       output parms -
      */

      int UtPod::addSong(Song const &s){
      if(s.getMemory() <= getRemainingMemory()){
      	/*Song temporary = new Song;
      	temporary = s;*/
      	SongNode *temp = new SongNode;
      	temp->s = s;
      	temp->next = songs;
      	songs=temp;
      	return SUCCESS;
      }
      else 
      	return NO_MEMORY;
  	  }


      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -2 if nothing is removed


         input parms -

         output parms -
      */

      int UtPod::removeSong(Song const &s){
      	SongNode *temp = songs;
      	SongNode *previous = NULL;
      	int result = 123;
      	if(songs == NULL){
      		result = NOT_FOUND;
      	}
      	else{
      		while((temp != NULL) && (result != SUCCESS)){
      			if(temp->s == s){
      				if(previous == NULL){
      					songs = temp->next;
      					delete(temp);
      				}
      				else{
      					previous->next = temp->next;
      					delete(temp);
      				}
      				result = SUCCESS;
      			}
      			else{
      				result = NOT_FOUND;
      			}
      			previous = temp;
      			temp = temp->next;
      		}
      		/*while((temp != NULL)&& !(temp->s==s)){
      			previous = temp;
      			temp = temp->next;
      		}
      		if(temp->s == s){
      			if(previous == NULL){
      				songs = temp->next;
      				delete(temp);
      			}
      			else if(temp != NULL){
      				previous->next = temp->next;
      				delete(temp);
      			}
      			return SUCCESS;
      		}
      		else
      			return NOT_FOUND;*/
      	}
      	return result;

      }


      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void UtPod::shuffle(){
      	if(songs == NULL){}
      	else{
      		int count = 0;
      		SongNode *temp = songs;
      		while(temp!=NULL){
      			temp = temp->next;
      			count++;
      		}
      		for(int j = 0; j<(count*2); j++){
      			int rand1 = rand()%(count);
      			int rand2 = rand()%(count);
      			cout<<"random number 1 "<<rand1; 
      			SongNode *swap1 = NULL;
      			SongNode *swap2 = NULL;
      			temp = songs;
      			int i = 0;
      			while(swap1==NULL || swap2==NULL){
      				if(i == rand1)
      					swap1 = temp;
      				if(i == rand2)
      					swap2 = temp;
      				temp = temp->next;
      				i++;
      			}
      			swap1->s.swap(swap2->s);
      		}

      	}
      }


      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

      void UtPod::showSongList(){
      	SongNode *temp = songs;
      	if(songs==NULL)
      		cout<<"Your UtPod is empty!"<<endl;
      	while(temp!=NULL){
      		cout << "Artist - " << temp->s.getArtist() << ", Title - " << temp->s.getTitle()  << ", Memory - " << temp->s.getMemory()<< endl;
      		temp = temp->next;
      	}
      }


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void UtPod::sortSongList(){
      	if(songs == NULL){}
      	else{
      		SongNode *best = songs;
      		SongNode *first = songs;
      		while(first->next != NULL){
      			SongNode *temp = first->next;
      			while(temp!=NULL){
      				if(temp->s > first->s){
      					best = temp;
      				}
      				temp = temp->next;
      			}
      			first->s.swap(best->s);
      			first = first->next;
      			best = first;
      		}
      	}
      }


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */
      void UtPod::clearMemory(){
      	SongNode *temp = songs;
		SongNode *previous = NULL;
		while(temp != NULL){
			previous = temp;
			temp = temp->next;
			delete(previous);
		}
		songs = NULL;		
      }



      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */

      int UtPod::getRemainingMemory(){
      	SongNode *temp = songs;
      	int memUsed = 0;
      	while(temp!=NULL){
      		memUsed = memUsed + temp->s.getMemory();
      		temp = temp->next;
      	}
      	return getTotalMemory()-memUsed;
      }


      UtPod::~UtPod(){
      }
 
