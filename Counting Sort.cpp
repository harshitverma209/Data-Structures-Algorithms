#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> counting_sort(vector<int> arr){
    int max=*max_element(arr.begin(), arr.end());
    vector<int> count(max+1,0),output(arr.size(),0);
    //Step 1:Counting occurrences in the array
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }

    //Step 2:Compute cumulative sum of occurrences

    for(int i=1;i<count.size();i++){
        count[i]+=count[i-1];
    }

    //Step 3: Insert the elements into the output array
    for(int i=0;i<arr.size();i++){
        int j=arr[i];
        if(count[j]){
            output[count[j]-1]=arr[i];
            count[j]--;
        }
    }
    return output;


}
int main(){
    vector<int> arr={9,5,7,3,4,6,5,5,3,4,3,2,9};
    vector<int> output=counting_sort(arr);
    for(int e:output){
        cout<<e<<endl;
    }
    return 0;
}