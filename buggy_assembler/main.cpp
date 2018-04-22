/* 
 * File:   main.cpp
 * Author: (Phase 2) Seongjin Bien & Majorka Thanasi
 *         (Phase 3) Seongjin Bien & Oana Miron
 * Main file of the assembler 
 * Created on March 23, 2018, 1:09 AM
 */

/*
 * IMPORTANT:
 * The input .buggy file's functions (the lines with colons) MUST
 * start with an underscore ("_") for this to work properly.  
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

#include <numeric>
#include <valarray> //accumulate()

using namespace std;


template <typename T>
   std::string to_string(T value)
   {
     //create an output string stream
     std::ostringstream os ;

     //throw the value into the string stream
     os << value ;

     //convert the string stream into a string and return
     return os.str() ;
   }

void printvv(vector< vector<string> > v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<std::string> split(string s, char delim){
    stringstream ss(s);
    string item;
    vector<std::string> elems;
    while(std::getline(ss, item, delim)){
        if(item!=""){
            elems.push_back(item);
        }
    }
    return elems;
}

int main(int argc, char** argv) { 
    
    //Dictionary of known key words
    //The integer values indicate the total number of words that 
    //   belong to that keyword.
    //   e.g. "sense" takes in 2 arguments, such as "sense ahead food"
    //      which takes up 3 words. 
    
    map<string, int> known;
    known["sense"] = 3; //sense sensedir cond 
    known["move"] = 1; // move 
    known["pickup"] = 1; // pickup
    known["flip"] = 2; // flip p
    known["turn"] = 2; // turn lr
    known["drop"] = 1; // drop
    known["mark"] = 2; // mark i
    known["unmark"] = 2; // unmark i
    known["direction"] = 2; // direction d
    known["goto"] = 1; // goto
    known["else"] = 1; // else
            
    
    //Vector for storing all the lines, word by word 
    vector< vector<string> > rawlines;
    
    //Map for storing position values of labels
    map<string, int> labels;
    
    //Vector for storing answer strings to be spit out
    vector< vector<string> > answers;
    answers.resize(100);
    vector< vector<string> > answerorg;
    for (int i = 0; i<100; i++){
        answers[i].resize(0);
    }
    fstream outfile;
    outfile.open("output.txt", ios::out);
    if(outfile.fail()){
        cout << "output.txt is not accessible. \n";
        return (int)'O';
    }
    //Keeps track of occasions where there is an else statement and a goto right after.
    bool elseflag = 0;
    string c;
    fstream infile;
    infile.open("bug.buggy", ios::in);
    if(infile.fail()){
        cout << "Buggy file is not accessible. \n";
        return (int)'B';
    }
    while (getline(infile, c)){
        if(c[0] != ';' && c[0] != '_'){
            vector<string> temp = split(c, ' ');
            rawlines.push_back(temp);
            
            //cout << c << endl;
        }
        if(c[0] == '_'){ //we assume that all labels start with _ to remove ambiguity 
            string label = c.substr(0, c.size()-1);
            rawlines.push_back(split(label, ' '));
            labels[label] = -1;
            //cout << label << labels[label];
        }
    }
    
    int line_count = 0;
    //Processing the input file
    for (int i = 0; i < rawlines.size(); i++){
       // cout << "elseflag: " << elseflag << endl;
        for(int l = 0; l < rawlines[i].size(); l++){
         //   cout << rawlines[i][l] << " " ;
        }
        //cout << endl;
        
        bool senseflag = false;
        string sensearg = "";
        int next_line = line_count + 1;
        //detect the first word, see if it is a label
        if(i == 0 && rawlines[0][0][0] == '_'){
            labels[rawlines[0][0]] = 0;
            cout << "First label detected." << endl;
        }
        
        else if(i != 0 && rawlines[i][0][0] == '_'){
            //cout << i << endl;
            labels[rawlines[i][0]] = line_count;
            cout << "Label detected; Assigning new line number..." << endl;
        }
        
        //if it's not a label, then parse it 
        else{
            //cout << i << endl;
            //cout << "parsing lines" << endl;
            for (int j = 0; j< rawlines[i].size(); j++){
                string *next_step;
                if(rawlines[i][j] != "else"){
                    int chunksize = known[rawlines[i][j]];
                    //cout << chunksize << " Chunks, Chunk word: " << rawlines[i][j] <<endl;

                    switch (chunksize) {
                        case 1:
                            //move, pickup, drop, goto, else (no arg)
                            answers[line_count].push_back(rawlines[i][j]);
                            
                            answers[line_count].push_back(to_string(next_line));
                            next_step = &answers[line_count][j+1];
                            
                            break;
                        case 2:
                            //flip, turn take one arg
                            answers[line_count].push_back(rawlines[i][j]);
                            answers[line_count].push_back(rawlines[i][j+1]);
                            answers[line_count].push_back(to_string(next_line));
                            next_step = &answers[line_count][j+2];
                            j++; //skip the next word
                            break;
                        case 3:
                            //sense takes 2 arg 
                            answers[line_count].push_back(rawlines[i][j]);
                            answers[line_count].push_back(rawlines[i][j+1]);
                            
                            //we want the last arg of sense to be at the end
                            answers[line_count].push_back(to_string(next_line));
                            
                            next_step = &answers[line_count][j+2];
                            senseflag = 1;
                            sensearg = rawlines[i][j+2];
                            j+=2; //skip the next 2 words
                            break;
                        default:
                            throw("Chunksize cannot be 0! ");
                            return (int)'C';
                            break;
                    }
                }
                else{
                    //processing else
                    cout << "else found\n";
                    answers[line_count].push_back(rawlines[i][j+1]);
                   // cout << rawlines[i][j+1] << endl;
                    j++;
                    elseflag = true;
                    if (senseflag){
                        //cout << sensearg;
                        answers[line_count].push_back(sensearg);
                    }
                    line_count++;
                }
                
    
                if(i+1 < rawlines.size() && rawlines[i+1][0] == "goto"){
                    cout << "Processing goto" <<endl;
                    *next_step =  rawlines[i+1][1];
                    if(rawlines[i].size() >  2){
                        if(elseflag && rawlines[i][rawlines[i].size()-2] == "else"){
                            cout << "elseflag is up "<< endl;
                            *next_step = rawlines[i+1][1] + " " + (rawlines[i][rawlines[i].size()-1]);
                            elseflag = false;
                        }
                    }
                    //cout << *next_step << endl;
                    i++;
                    j++;
                    line_count++;
                }
                
                
                
                 

            }
        }
    /* Debugging
        if(i!=0){
            cout << "line " << line_count-1 << ": ";
            for (int m = 0; m < answers[line_count-1].size() ; m++){
                cout << answers[line_count-1][m] << " ";
            }
            cout << endl << endl;
            
        }
    */
    }
    cout << endl;
    
    //Verify that the buggy file has been parsed correctly 
    //Write the outcome to output.txt
    
    //cout << "\nProcessed output: \n";
    for(int a = 0; a < line_count; a++){
        //cout << "[" <<  a << "] ";
        for(int b = 0; b < answers[a].size(); b++){
            //cout << answers[a][b] << " ";
            outfile << answers[a][b] << " ";
            if(answers[a][b] == "_home"){
          //      cout << a << b ;
            }
        }
        outfile << endl;
        //cout << endl;
    }
    outfile.close();
    /////////////////////////////////////////
    
    /////////////////////////////////////////
    //Process the output text: replace _ keywords with respective ints from label map
    fstream step2;
    step2.open("output.txt", ios::in);
    if(step2.fail()){
        cout << "Step 2: output.txt is not available for secondary processing.\n";
        return (int)'S';
    }
    
    while (getline(step2, c)){
        
        vector<string> temp = split(c, ' ');
        answerorg.push_back(temp);
    }
    
    for (int i = 0; i < line_count; i++){
        for(int j = 0; j < answerorg[i].size(); j++){
            if(answerorg[i][j][0] == '_'){
                cout << answerorg[i][j] << endl;
                answerorg[i][j] = to_string(labels[answerorg[i][j]]);
            }
        }
    }
    
    
    printvv(answerorg);
    
    //Rewrite the result into final.txt
    outfile.open("final.bug", ios::out);
    if(outfile.fail()){
        cout << "final.bug failed to be created. \n";
        return (int)'F';
    }
    
    for (int i = 0; i < answerorg.size(); i++){
        for (int j = 0; j < answerorg[i].size(); j++){
            outfile << answerorg[i][j] << " ";
        }
        outfile << endl;
    }
    
    return 0;
}