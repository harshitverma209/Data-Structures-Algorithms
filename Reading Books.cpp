/*The problem: To assign consecutive segments of books from a 
total of B books to S students such that the maximum pages any 
student has to read is minimum */
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool canRead(vector<int> books,int s, int maxPages,int pagesLeft){
    int currPages=0;
    for(int i=0;i<books.size();i++){
        currPages+=books[i];

        if(currPages>=maxPages){
            s--;
            if(currPages>maxPages){
                currPages-=books[i];
                i--;
            }
            pagesLeft-=currPages;
            currPages=0;
            if(s<=0 && pagesLeft>0){
                return false;
            }
            
        }
    }
    return true;
}
int minPages(vector<int> books, int s){
    int totalPages=accumulate(books.begin(),books.end(),0);
    int end=totalPages;
    int beg=*min_element(books.begin(),books.end());
    int res=INT_MAX;
    int mid=(beg+end)/2;
    while(beg<end){
        if(canRead(books,s,mid,totalPages)){
            res=min(res,mid);
            end=mid;
        }else{
            beg=mid+1;
        }
        mid=(beg+end)/2;
    }
    return res;
}
int main(){
    vector<int> books={12,34,67,90};
    int s=2;
    int res=minPages(books,s);
    cout<<res<<endl;
    return 0;
}