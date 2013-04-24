#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

class input{
      private:
              int gridPosition;
              map<string, int> q1Tire;
              map<string, int> q2Tire;
              map<string, int> q3Tire;
              int primeTires[3];
              int optionTires[3];
              string trackName;
              float trackTemperature;
              string weather;
      
      
      public:
      input(){
             primeTires[0] = 100;
             primeTires[1] = 100;
             primeTires[2] = 100;
             optionTires[0] = 100;
             optionTires[1] = 100;
             optionTires[2] = 100;
             //grid position input
             do{
                             cout<<"Grid position: ";
                             cin>>gridPosition;
                     }while((gridPosition < 1) || (gridPosition > 22));
             
             
             //track name input
             cout<<"Track name(China, Malaysia, Australia): ";
             cin>> trackName;
            
             //track name input
             cout<<"Track weather(dry, windy, cloudy): ";
             cin>> weather;
             
             //track temperature input
             cout<<"Track temperature: ";
             cin>>trackTemperature;
             
             
             //Qualifying tire details
             bool tempQ1, tempQ2, tempQ3;
             string tempTire;
             int tempTireCount;
             
              cout<<"Q1 time set(true-->1/false-->0): ";
              cin>> tempQ1;
              if(tempQ1 == true){
                         cout<<"Q1 tire used(options/primes): ";
                         cin>>tempTire;
                         do{
                                        cout<<"Number of hot laps set on it(max 10): ";
                                        cin>>tempTireCount;              
                                       }while((tempTireCount < 1) || (tempTireCount > 10));
                         cout<<"Q2 time set(true-->1/false-->0): ";
                         cin>>tempQ2;
                         //q1Tire[tempTire] = tempTireCount;
                         if(tempQ2 == true){
                                      cout<<"Q2 tire used(options/primes): ";
                                      cin>>tempTire;
                                      do{
                                        cout<<"Number of hot laps set on it(max 7): ";
                                        cin>>tempTireCount;              
                                       }while((tempTireCount < 1) || (tempTireCount > 7));
                                      cout<<"Q3 time set(true-->1/false-->0): ";
                                      cin>>tempQ3;
                                      if(tempQ3 == true){
                                                   cout<<"Q3 tire used(options/primes): ";
                                                   cin>>tempTire;
                                                   do{
                                                        cout<<"Number of hot laps set on it(max 3): ";
                                                        cin>>tempTireCount;              
                                                      }while((tempTireCount < 1) || (tempTireCount > 3));
                                                }//if Q3 ends here
                                      else{
                                                //Q3 else part...no time set in Q3
                                                //code goes here...
                                           }
                                                
                                     }//if Q2 ends here
                                     else{
                                              //Q2 else part...no time set in Q2 and hence not in Q3 also
                                              //code goes here...
                                          }
                         
                       }//if Q1 ends here
                       else{
                                //Q1 else part...no time set in Q1 and hence not in Q2 and Q3 also
                                //code goes here...
                            }
                       
             cout<<gridPosition;
             cout<<trackName;
             cout<<weather;
             
             }
      };
