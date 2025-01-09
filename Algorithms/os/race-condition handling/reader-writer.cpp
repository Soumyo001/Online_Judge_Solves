#include<bits/stdc++.h>
#include<thread>
#include <semaphore> 
using namespace std;
int read_count=0;
mutex resource;
mutex read_count_mutex;
// binary_semaphore sem(1);
// binary_semaphore db(1);
void reader(int id){
    while(true){
        //unique_lock<mutex> rs_lock(read_count_mutex);
        read_count_mutex.lock();
        //sem.acquire();
        ++read_count;
        if(read_count==1){
            //db.acquire();
            resource.lock();
        }
        //rs_lock.unlock();
        read_count_mutex.unlock();
        //sem.release();
        cout<<"Reader "<<id<<" is reading...\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout<<"Reader "<<id<<" finished reading...\n";
        //rs_lock.lock();
        read_count_mutex.lock();
        //sem.acquire();
        --read_count;
        if(read_count==0){
            //db.release();
            resource.unlock();
        }
        //rs_lock.unlock();
        read_count_mutex.unlock();
        //sem.release();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
void writer(int id){
    while(true){
        resource.lock();
        //db.acquire();
        cout<<"Writer "<<id<<" is writing...\n";
        this_thread::sleep_for(chrono::milliseconds(1500));
        cout<<"Writer "<<id<<" finished writing...\n";
        resource.unlock();
        //db.release();
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}
void reader_writer(){
    thread readers[5],writers[2];
    for(int i=0;i<5;++i) readers[i]=thread(reader,i+1);
    for(int i=0;i<2;++i) writers[i]=thread(writer,i+1);
    for(int i=0;i<5;++i) readers[i].join();
    for(int i=0;i<2;++i) writers[i].join();
}
int main(void){
    reader_writer();
}