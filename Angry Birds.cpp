/*The problem: PlaceB birds in N nests such that
the minimum distance between any two birds is the largest*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool can_fit(vector<int> nests,int birds,int min_dis){
    int prev_nest=nests[0];
    birds--;
    for(int i=1;i<nests.size()&&birds>0;i++){
        if(!(nests[i]-prev_nest>=min_dis)){
            if(i==nests.size()-1){
                return false;
            }
        }
        else{
            birds--;
            prev_nest=nests[i];
        }
    }
    return true;
}
int solve_angry_birds(vector<int> nests,int birds,int beg,int end){
    int mid=(beg+end)/2;
    int max_min_dis=-1;
    while(beg<end){
        if(can_fit(nests,birds,mid)){
            beg=mid+1;
            max_min_dis=max(max_min_dis,mid);
        }else{
            end=mid;
        }
        mid=(beg+end)/2;
    }
    return max_min_dis;
}
int main(){
    vector<int> nests={1,2,4,8,9};
    int birds=3;
    int least_distance=0;
    int max_distance=nests[nests.size()-1]-nests[0];
    sort(nests.begin(),nests.end());
    int res=solve_angry_birds(nests,birds,least_distance,max_distance);
    cout<<res<<endl;
    return 0;
}