#include<bits/stdc++.h>
#include<thread>
using namespace std;

const int BUFFER_SIZE = 7;
int count_slot = 0;

void producer(int id){
    while (true)
    {
       int item = rand()%100;
       cout<<"Producer "<<id<<" producing an item\n";
       this_thread::sleep_for(chrono::milliseconds(500));

       while(count_slot == BUFFER_SIZE){
        cout<<"Producer "<<id<<" is waiting.\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
       }
       //insert_item(item);
       cout<<"Inserting into buffer. Item no : "<<item<<"\n";
       this_thread::sleep_for(chrono::milliseconds(500));
       count_slot=count_slot+1;
    }
}

void consumer(int id){
    while (true)
    {
       while(count_slot == 0){
        cout<<"Consumer "<<id<<" is waiting. \n";
        this_thread::sleep_for(chrono::milliseconds(1000));
       }
       //item = remove_item();
       cout<<"Consumer "<<id<<" removing an item from buffer. \n";
       this_thread::sleep_for(chrono::milliseconds(1000));
       count_slot = count_slot - 1;
       //consume_item(item);
    }
    
}


int main(void){
    srand(time(0));
    thread producers[7], consumers[15];
    for(int i=0;i<7;++i) producers[i] = thread(producer, i+1);
    for(int i=0;i<15;++i) consumers[i] = thread(consumer, i+1);
    for(int i=0;i<7;++i) producers[i].join();
    for(int i=0;i<15;++i) consumers[i].join();
}