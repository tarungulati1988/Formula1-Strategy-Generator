#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define in_optionLife 18
#define in_primeLife 30

// option --> 1
// prime --> 2
/*Weather:
          Dry --> 1
          Windy --> 2
          Cloudy --> 3*/
/*TrackID:
          Australia --> 1
          Malaysia --> 2
          India --> 3*/
          

class input_details
{
	public:
        int in_gridPosition;
        int in_used_tirelife[3];
        int in_q_session_tires[3];
              
        int in_primeTires[3];
        int in_optionTires[3];
        int in_trackID;
        float in_trackTemperature;
        int in_weather;
        float in_score;

        //constructor 
        input_details()
        {
        	/*in_gridPosition = 0;
        	in_trackName = "australia";
        	in_weather = "DEFAULT INPUT WEATHER";
        	in_input_score = 0;
        	for (int i = 0; i < 3; ++i)
        	{
        		in_used_tirelife[i] = 0;
        		in_q_session_tires[i] = "DEFAULT Q TIRE";
        		in_primeTires[i] = 0;
        		in_optionTires[i] = 0;
			}*/
			
			in_gridPosition = 0;
            in_score = 0.0;
            for (int i = 0 ; i < 3 ; i++) {
                in_primeTires[i] = 100;
                in_optionTires[i] = 100;
                in_used_tirelife[i]=0;
                in_q_session_tires[i] = 0;
            }
        }
        
        //----------get user input details......
        
        void in_get_input(){
             
                             cout<<endl<<"***********IMPORTANT*************\n";
                             cout<<endl<<"Input guidlines are as follows: \n";
                             cout<<endl<<"1 --> Australia\n2 --> China\n3 --> India";
                             cout<<endl<<"Weather:\n1 --> dry\n2 --> windy\n3 --> cloudy";
                             cout<<endl<<"\n*********************************\n";
                             //grid position input
                             do{
                                    cout<<endl<<"Grid position (1-22): ";
                                    cin>>in_gridPosition;
                                }while((in_gridPosition < 1) || (in_gridPosition > 22));
                                
                             //trackID input
                             cout<<endl<<"Track ID: ";
                             cin>>in_trackID;
                             if(in_trackID != 1 && in_trackID != 2 && in_trackID !=3){
                                             exit(0);
                                        }
                             
                             cout<<endl<<"Track weather: ";
                             cin>> in_weather;
                             if(in_weather != 1 && in_weather != 2 && in_weather != 3){
                                                exit(0);
                                           }
                                
                             //track temperature input
                             cout<<endl<<"Track temperature: ";
                             cin>>in_trackTemperature;
                             
                             //Qualifying details input begins here........
                             
                             bool in_timeset;
                             string in_tempTire;
                             int in_hot_laps;
                             int in_prime_count = 0, in_option_count = 0;
                             for (int i = 0; i<3; i++) {
                                    cout<<endl<<"Time set in Q"<<i+1<<"? (1/0): ";
                                    cin>>in_timeset;
                                    if (in_timeset) {
                                        cout<<endl<<"Tire used in Q"<<i+1<<" (Option/Prime): ";
                                        cin>>in_tempTire;
                                        cout<<endl<<"Number of laps set: ";
                                        cin>>in_hot_laps;
                                        if (in_tempTire == "prime" || in_tempTire == "Prime") {
                                            in_q_session_tires[i] = 2;
                                            in_used_tirelife[i] = 5*in_hot_laps;
                                            in_primeTires[in_prime_count] -= in_used_tirelife[i];
                                            in_prime_count++;
                                        }
                                        else{
                                            in_q_session_tires[i] = 1;
                                            in_used_tirelife[i] = 10*in_hot_laps;
                                            in_optionTires[in_option_count] -= in_used_tirelife[i];
                                            in_option_count++;
                                        }
                                    }
                                }
                                
                             //Qualifying details input and tire life calculation ends here......
                             
                             
                             
                             //Tire life calculation and score calculation for input begins here.........
                             
                                int in_tot_prime  = 0, in_tot_option = 0;
                                int in_primeLifeRemaining[3], in_optionLifeRemaining[3];
                                for(int k = 0; k < 3;k++)
                                {
                                    //cout<<"o: "<<optionTires[k]<<endl<<"p: "<<primeTires[k];
                                    in_tot_option += (in_optionTires[k] * in_optionLife)/100;
                                    in_tot_prime += (in_primeTires[k] * in_primeLife)/100;
                                }
                                
                                in_score = (22 - in_gridPosition) + (0.6*in_tot_option) + (0.4*in_tot_prime);
                                
                             
                             //tire life calculation for input ends here..........
                                
                             //score calculation based on the weather on the day of the race starts here...........
                             
                             
                                 if(in_weather == 1)
                                {
                                    in_score += 5;
                                }
                                else if (in_weather == 2)
                                {
                                    in_score -= 7;
                                }
                                else if(in_weather == 3)
                                {
                                    in_score -= 2;
                                }
                                else
                                {
                                    exit(0);     
                                }
                                if (in_trackTemperature >= 25 && in_trackTemperature <= 33)
                                {
                                    in_score += (0.8*in_trackTemperature);
                                }
                                else
                                {
                                    in_score -= (0.4*in_trackTemperature);
                                }
                             
                             
                             //score calculation based on the weather on the day of the race ends here............
                             
                             
                                
             }
        
        //user input details ends here......
        
};


//get user input to build a case implementation begins here........


      void caseMatchAndAdaptation(){
                          input_details *inputCaseObj = new input_details;
                          inputCaseObj->in_get_input();
                          cout<<endl<<"testing: "<<inputCaseObj->in_gridPosition<<" , "<<inputCaseObj->in_q_session_tires[2]<<" , "<<inputCaseObj->in_score;
                          
                          //check to see if q3 tire == stint 1 tire and input track id == database track id........
                          
                          //file pointer to read file...
                          fstream infile;
                          int matchCount = 0;
                          infile.open("tempCases.dat",ios::in|ios::binary);
                          
                          //file pointer to create temporary file with matching cases...
                          fstream outfile;
                          outfile.open("tempMatchingCases.dat",ios::out|ios::app|ios::binary|ios::trunc);
                          //check if file is open...
                          if(infile.is_open()){
                                                    case_details *tempIterator = new case_details;
                                                    while(infile.read((char *)tempIterator,sizeof(case_details))){
                                                                                   //match cases where tire used in qualifying 3 == tire used in stint1 or no time set in qualifying 3 and trackID's are same
                                                                                   if( ( inputCaseObj->in_q_session_tires[2] == tempIterator->stint_tires[0] && inputCaseObj->in_trackID == tempIterator->trackID ) || ( inputCaseObj->in_q_session_tires[2] == 0 && inputCaseObj->in_trackID == tempIterator->trackID ) ){
                                                                                         
                                                                                         cout<<endl<<"-score difference is: "<<(inputCaseObj->in_score - tempIterator->score);
                                                                                         if( (inputCaseObj->in_score - tempIterator->score) <= 10.0 && (inputCaseObj->in_score - tempIterator->score) >= 0.0){
                                                                                                ++matchCount;
                                                                                                outfile.write((char *)tempIterator,sizeof(case_details));   
                                                                                             }
                                                                                       }
                                                                            }
                                                    cout<<endl<<"Number of case matches: "<<matchCount;
                                                    infile.close();
                                                    outfile.close();
                                               }
                          else{
                                               cout<<endl<<"The file couldn't be opened.";
                               }
                          
                          
                          //check ends here......
                          
           
           }


//get user input to build a case implementation ends here..........
