#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Point{
    public:
    int x,y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};
int countTriangles(vector<Point> points){
    int count=0;
    unordered_map<int,int> xmap,ymap;
    for(int i=0;i<points.size();i++){
        Point p=points[i];
        int x=p.x;
        int y=p.y;
        xmap[x]++;
        ymap[y]++;
    }
    for(int i=0;i<points.size();i++){
        count+=((xmap[points[i].x]-1)*(ymap[points[i].y]-1));
    }
    return count;
}
int main(){
    vector<Point> points;
    points.push_back(Point(1,2));
    points.push_back(Point(2,1));
    points.push_back(Point(2,2));
    points.push_back(Point(2,3));
    points.push_back(Point(3,2));
    int res=countTriangles(points);
    cout<<res<<endl;
    return 0;
}