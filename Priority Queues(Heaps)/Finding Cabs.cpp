#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Cab{
    public:
    string id;
    int x;
    int y;
    Cab(string id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    Cab(){}
    int dist(){
        return x*x+y*y;
    }
};
class Compare{
    public:
    bool operator()(Cab a,Cab b){
        return a.dist()<b.dist();
    }
};
void printNearestCabs(vector<Cab> cabs,int k){
    priority_queue<Cab,vector<Cab>,Compare> heap(cabs.begin(),cabs.begin()+k);
    for(int i=k;i<cabs.size();i++){
        Cab c=cabs[i];
        Cab t=heap.top();
        if(c.dist()<t.dist()){
            heap.pop();
            heap.push(c);
        }
    }
    Cab output[k];
    int i=k-1;
    while(!heap.empty()){
        output[i]=heap.top();
        i--;
        heap.pop();
    }
    for(Cab c:output){
        cout<<c.id<<endl;
    }
}
int main(){
    vector<Cab> cabs;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string id;
        int x,y;
        cin>>id>>x>>y;
        Cab c(id,x,y);
        cabs.push_back(c);
    }
    int k;
    cin>>k;
    printNearestCabs(cabs,k);
    return 0;
}
/*
5
c1 4 4
c2 1 1
c3 2 2
c4 3 3
c5 5 5
2
*/