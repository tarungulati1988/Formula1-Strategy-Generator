#include <iostream>
#include <string>
#include <fstream>

#define australiaNoLaps 57

#define optionLife 18
#define primeLife 30

using namespace std;


class case_details
{
	public:
		int gridPosition;
        int used_tirelife[3];
        int q_session_tires[3];
              
        int primeTires[3];
        int optionTires[3];
        float trackTemperature;
        int weather;
        float score;

        int raceID;
        int stint_last_laps[3];
        //option tires--> 1
        //prime tires--> 2
        int stint_tires[3];
        
        int trackID;

        //constructor
        case_details()
        {
        /*	gridPosition = 0;
        	trackTemperature = 0;
        	score = 0.0;
        	raceID = 0;
        	trackID = 0;
        	weather = "DRY";
        	trackName = "DEFAULT TRACK";
        	for (int i = 0; i < 3; ++i)
        	{
        		used_tirelife[i] = 0;
        		q_session_tires[i] = "DEFAULT TIRE";
        		primeTires[i] = 0;
        		optionTires[i] = 0;
        		stint_tires[i] = "DEFAULT STINT TIRE";
        		stint_last_laps[i] = 0;

        	}*/
        	gridPosition = 0;
            score = 0.0;
            for (int i = 0 ; i < 3 ; i++) {
                primeTires[i] = 100;
                optionTires[i] = 100;
                used_tirelife[i]=0;
                q_session_tires[i] = 0;
            }
        	
        }
        //constructor ends here.....
        
        //get_input() function starts here....
        
        void get_input(){
             
                         cout<<endl<<"***********IMPORTANT*************\n";
                         cout<<endl<<"Input guidelines are as follows:\n";
                         cout<<endl<<"1 --> Australia\n2 --> China\n3 --> India";
                         cout<<endl<<"For weather:\n1 --> dry\n2 --> windy\n3 --> cloudy";
                         cout<<endl<<"\n*********************************";
                         //grid position input
                         do{
                                cout<<endl<<"Grid position (1-22): ";
                                cin>>gridPosition;
                            }while((gridPosition < 1) || (gridPosition > 22));
                            
                         
                            
                         //trackID input
                         cout<<endl<<"Track ID: ";
                         cin>>trackID;
                         if(trackID != 1 && trackID != 2 && trackID !=3){
                                         exit(0);
                                    }
                         
                         //raceID input
                         cout<<endl<<"RaceID: ";
                         cin>>raceID;
                         
                         //track weather input
                         cout<<endl<<"Track weather: ";
                         cin>> weather;
                            
                         //track temperature input
                         cout<<endl<<"Track temperature: ";
                         cin>>trackTemperature;
                         
                         bool timeset;
                         string tempTire;
                         int hot_laps;
                         int prime_count = 0,option_count = 0;
                         for (int i = 0; i<3; i++) {
                                cout<<endl<<"Time set in Q"<<i+1<<"? (1/0): ";
                                cin>>timeset;
                                if (timeset) {
                                    cout<<endl<<"Tire used in Q"<<i+1<<" (Option/Prime): ";
                                    cin>>tempTire;
                                    cout<<endl<<"Number of laps set: ";
                                    cin>>hot_laps;
                                    if (tempTire == "prime" || tempTire == "Prime") {
                                        q_session_tires[i] = 2;
                                        //q_session_tires[i].assign(tempTire);
                                        used_tirelife[i] = 5*hot_laps;
                                        primeTires[prime_count] -= used_tirelife[i];
                                        prime_count++;
                                    }
                                    else{
                                        q_session_tires[i] = 1;
                                        //q_session_tires[i].assign(tempTire);
                                        used_tirelife[i] = 10*hot_laps;
                                        optionTires[option_count] -= used_tirelife[i];
                                        option_count++;
                                    }
                                }
                            }
                            
                            int tot_prime  = 0,tot_option = 0;
                            int primeLifeRemaining[3], optionLifeRemaining[3];
                            for(int k = 0; k < 3;k++)
                            {
                                //cout<<"o: "<<optionTires[k]<<endl<<"p: "<<primeTires[k];
                                tot_option += (optionTires[k] * optionLife)/100;
                                tot_prime += (primeTires[k] * primeLife)/100;
                            }
                            
                            score = (22 - gridPosition) + (0.6*tot_option) + (0.4*tot_prime);
                            
                            if(weather == 1)
                            {
                                score += 5;
                            }
                            else if (weather == 2)
                            {
                                score -= 7;
                            }
                            else if(weather == 3)
                            {
                                score -= 2;
                            }
                            else
                            {
                                exit(0);     
                            }
                            if (trackTemperature >= 25 && trackTemperature <= 33)
                            {
                                score += (0.8*trackTemperature);
                            }
                            else
                            {
                                score -= (0.4*trackTemperature);
                            }
                            
                            //-------strategy details input starts here.........
                            
                            
                            string tempStr;
                           

                            for (int i = 0; i < 3 ; i++ )
                            {
                                int lap;
                                if(i!=2)
                                {
                                    cout<<endl<<"Enter the last lap of stint "<<i+1<<": ";
                                    cin>>lap;
                
                                }
                                else
                                {
                                    lap = australiaNoLaps;
                                }
                                cout<<endl<<"Enter stint "<<i+1<<" tire (O/P): ";
                                cin>>tempStr;
                                stint_last_laps[i] = lap;
                                if(tempStr == "option" || tempStr == "Option")
                                           stint_tires[i] = 1;
                                else
                                           stint_tires[i] = 2;
                                //stint_tires[i].assign(tempStr);
                                cout<<endl<<"Stint "<<i+1<<" tire was: "<<stint_tires[i];
                               
                            }
                            
                            
                            //--------strategy details input ends here..........
             
             }
        
        
        //get_input() function ends here....
        
        

};

void makeCase(){
                case_details *caseObj = new case_details;
                caseObj->get_input();
                fstream outfile;
                
                outfile.open("tempCases.dat",ios::out|ios::app|ios::binary);
                
                outfile.write((char *)caseObj,sizeof(case_details));
                outfile.close();
             
             }
             
void getCase(){
     
                fstream infile;
                int count = 0;
                infile.open("tempCases.dat",ios::in|ios::binary);
                if(infile.is_open())
                {
                    case_details *temp = new case_details;
                    while(infile.read((char *)temp,sizeof(case_details)))
                    {
                        cout<<endl<<"\n----------------CASE "<<++count<<"---------------";
                        cout<<endl<<"grid position: "<<temp->gridPosition;
                        cout<<endl<<"qualifying tires : "<<temp->q_session_tires[0]<<" , "<<temp->q_session_tires[1]<<" ,  "<<temp->q_session_tires[2];
                        cout<<endl<<"stint tires : "<<temp->stint_tires[0]<<" , "<<temp->stint_tires[1]<<" ,  "<<temp->stint_tires[2];
                        cout<<endl<<"stint last laps : "<<temp->stint_last_laps[0]<<" , "<<temp->stint_last_laps[1]<<" ,  "<<temp->stint_last_laps[2]; 
                        cout<<endl<<"weather: "<<temp->weather;
                        cout<<endl<<"track Id: "<<temp->trackID;
                        cout<<endl<<"race ID: "<<temp->raceID;
                        cout<<endl<<"score: "<<temp->score;
                        cout<<endl<<"-------------------------------------\n";
                        //delete temp;
//                        temp = new case_details;
                    }   
                    infile.close();   
                }
                else
                {
                    cout<<endl<<"File Not found while reading";
                }
     
     }
