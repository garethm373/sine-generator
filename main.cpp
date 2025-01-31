#include <vector>
#include <iostream>
#include <fstream>


class Wave{

public:

std::vector<float> sineWave(){
    //sine parameters
    float pi = 3.1415926535;
    float freq = 440.0; //hertz
    float ampl = 1.0;
    float duration = .05; //seconds
    int fs = 8000; //sample rate
    int samples = duration * fs;
   
    
    //calculate sine values
    std::vector<float> sineWave;

    for(int i=0; i <= samples; i++){
            sineWave.push_back(0); 
            // t=n/fs, n = i
            float t = static_cast<float>(i)/fs;
            sineWave.at(i) = ampl*sin(2*pi*freq*t);
            std::cout << sineWave[i] << " ";
            }
        return sineWave;
    }

};

//------------------------------------------------

int main(){

    Wave new_wave;
    std::vector<float> outputVals = new_wave.sineWave();
    
    //write sine values to CSV for later visualization
    std::ofstream outfile("sineCSV.csv");

    if(outfile.is_open()){
        for(const auto &row : outputVals){
            for(int i = 0; i <= outputVals.size(); i++){
                outfile << outputVals[i];
                    if (i != outputVals.size() - 1){
                        outfile << ",";
                    }else{
                        outfile.close();
            }
        }   
    }  
    }else{
        std::cout << "Error creating file, please close file.\n"; 
    }

   
    return 0;
}
