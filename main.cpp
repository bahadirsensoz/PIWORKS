#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;



int string2int(const string &s)
{
    int ans = 0;
    for(size_t i=0; i< s.length(); i++)
    {
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}

int* string2array(const string &s, int n)
{
    int* arr = new (nothrow) int[n];
    if(arr!= nullptr)
    {
        string singleNumber = "";
        int j = 0;
        for(size_t i=0; i<s.length();i++)
        {
            if(s[i]!= ' ')
                singleNumber += s[i];
            else
            {
                arr[j] = string2int(singleNumber);
                singleNumber = "";
                j++;
            }
        }
        arr[j] = string2int(singleNumber);
    }
    return arr;
}


bool NonPrime(int a){
    if(a==2)
        return false;

    for (int i = 1; i<a-1; i++){
        if(a%(a-i) == 0)
            return true;
    }

    return false;
}



int getSumPyramid(){

        string line;
        vector<vector<int>> num;
        vector<int> lines;
        string filename("Input.txt");
        ifstream input_file(filename);


         if(input_file.is_open()){
            while (getline(input_file,line)){
                stringstream ss;
                ss << line;
                //cout << line << endl;
                int numbers;
                string temp;
                vector<int> v;
                while(!ss.eof()){
                    ss >> temp;
                    if(stringstream(temp) >> numbers){ //sanitize special chars in case exist in file
                        //cout << numbers << endl;
                        v.push_back(numbers);
                    }
                }
                num.push_back(v);

            }
        }
        for(int i = 0; i<num.size();i++){
            vector<int> temp = num.at(i);
            //cout << i << endl;
            //cout << temp[0];
            //for(int j = 0; j< temp.size(); j++){
              //  cout << temp.at(j) << endl;
                //}
        }


    //vector<int>::iterator iter;
        int searchIndex = 0;
        int total = num.at(0).at(0);
        for(int i =1; i< num.size(); i++){
            vector<int> temp = num.at(i);
            //NonPrime returns true if it is not prime
            if(!NonPrime(temp[searchIndex]) && !NonPrime(temp[searchIndex + 1])){ //not prime
                break;
            }

            if (temp[searchIndex] > temp[searchIndex + 1]) {
                if(NonPrime(temp[searchIndex])){
                    total += temp[searchIndex];
                    //cout << temp[searchIndex] << endl;
                }
                else{
                    total += temp[searchIndex + 1];
                    searchIndex++;
                    //cout << temp[searchIndex] << endl;
                }
            } else {
                total += temp[searchIndex + 1];
                searchIndex++;
                //cout << temp[searchIndex] << endl;
            }
        }
        return total;

    }

int main() {

    cout << getSumPyramid() << endl;

    return 0;
}
