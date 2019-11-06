/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/

#include "Song.h"
#include <cstdlib>
#include <iostream>
#include "UTpod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();

    t.sortSongList();
    cout<<"sorteed"<<endl;
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    cout<<"CLEAR THE MEMORY"<<endl;
    t.clearMemory();

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    result = t.addSong(s1);
    result = t.addSong(s2);
    result = t.addSong(s3);
    result = t.addSong(s4);
    result = t.addSong(s3);
    t.showSongList();

    cout<<"shuffled"<<endl;


    t.shuffle();
    t.showSongList();
    cout<<"shuffled"<<endl;

    t.sortSongList();
    t.showSongList();
    cout<<"sorted"<<endl;

    t.removeSong(s3);
    t.showSongList();
    cout<< "very cool thank you"<< endl;

    UtPod u(320);
    cout << "memory = " << u.getRemainingMemory() << endl;
    cout << "memory = " << u.getTotalMemory() << endl;


    Song u5("Eagles", "Take It Easy", 40);
    result = u.addSong(u5);
    cout << "result = " << result << endl;

    Song u7("AC DC", "Back in Black", 10);
    result = u.addSong(u7);
    cout << "result = " << result << endl;

    Song u1("Beach Boys", "Kokomo", 10);
    result = u.addSong(u1);
    cout << "result = " << result << endl;

    Song u2("Roy Orbison", "In Dreams", 8);
    result = u.addSong(u2);
    cout << "result = " << result << endl;

    Song u3("Frankie Avalon", "Venus", 12);
    result = u.addSong(u3);
    cout << "result = " << result << endl;

    Song u4("Earth, Wind & Fire", "September", 20);
    result = u.addSong(u4);
    cout << "result = " << result << endl;


    u.showSongList();
    cout<<"Sorted: "<<endl;
    u.sortSongList();
    u.showSongList();

    u.shuffle();
    u.showSongList();

    Song u6("Britney Spears", "Toxic", 100);
    result = u.addSong(u6);
    cout << "result = " << result << endl;
    result = u.addSong(u6);

    cout<<"sorted with britney"<<endl<<endl;

    u.sortSongList();
    u.showSongList();

    u.removeSong(u6);
    cout<<"Now without one of britneys"<<endl;
    u.showSongList();

    u.shuffle();
    cout<<"shuffle it up"<<endl;
    u.showSongList();




    

}