/*The problem is to calculate badness in a ranklist. Badness is determined as follows:
THe sum of the differences between the desired and actual ranks of teams
Note: Try in linear time
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
int badness(vector<pair<string,int>> arr){
    int bad=0,n=arr.size();
    vector<int> count(n+1,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i].second]++;
    }
    int k=0;
    for(int i=0;i<count.size();i++){
        
        while(count[i]>0){
            count[i]--;
            bad+=abs(k-i+1);
            k++;
        }
    }
    return bad;
}
int main(){
    vector<pair<string,int>> arr={{"lol",1},{"let",2},{"me",2},{"do",1},{"this",5},{"right",7},{"please",7}};
    cout<<badness(arr);
    return 0;
}