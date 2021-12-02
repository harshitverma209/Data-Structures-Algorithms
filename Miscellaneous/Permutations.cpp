/*The problem:
To find all (sorted)unique permutations of a string.
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
void generate_permutations(string str, vector<string> &permutations, int j, int n){
    if(j==n){
        permutations.push_back(str);
    }
    for(int i=j; i<n; i++){
        swap(str[j],str[i]);
        generate_permutations(str,permutations,j+1,n);
        swap(str[j],str[i]);
    }
}
vector<string> find_sorted_permutations(string str){
    vector<string> permutations;
    generate_permutations(str,permutations,0,str.length());
    set<string> sorted_permutations;
    for(string p:permutations){
        sorted_permutations.insert(p);
    }
    vector<string> res(sorted_permutations.begin(),sorted_permutations.end());
    return res;
}
int main(){
    string str="aaac";
    vector<string> res=find_sorted_permutations(str);
    for(string str:res){
        cout<<str<<endl;
    }
    return 0;
}