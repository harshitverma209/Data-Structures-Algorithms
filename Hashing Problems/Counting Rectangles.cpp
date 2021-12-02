#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Point{
    public:
    int x,y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
    bool operator==(const Point& otherPoint) const
    {
        if (this->x == otherPoint.x && this->y == otherPoint.y) return true;
        else return false;
    }
    class HashFunction
    {   
        public:
        size_t operator()(const Point& point) const
        {
        size_t xHash = std::hash<int>()(point.x);
        size_t yHash = std::hash<int>()(point.y) << 1;
        return xHash ^ yHash;
        }
    };
};
int countRectangles(vector<Point> points){
    unordered_set<Point,Point::HashFunction> pointset;
    int count=0;
    for(Point p:points){
        pointset.insert(p);
    }
    for(int i=0;i<points.size()-1;i++){
        Point p1=points[i];
        for(int j=i+1;j<points.size();j++){
            Point p2=points[j];
            int x1 = p1.x;
            int y1 = p1.y;
            int x2 = p2.x;
            int y2 = p2.y;
            if(x1==x2 or y1==y2){
                continue;
            }
            Point p3 = Point(x1,y2);
            Point p4 = Point(x2,y1);
            if(pointset.find(p3)!=pointset.end() and pointset.find(p4)!=pointset.end()){
                count++;
            }
        }
    }
    return count/2;
}
int main(){
    vector<Point> points;
    points.push_back(Point(4,1));
    points.push_back(Point(4,0));
    points.push_back(Point(0,0));
    points.push_back(Point(0,1));
    points.push_back(Point(1,1));
    points.push_back(Point(1,0));
    points.push_back(Point(2,0));
    points.push_back(Point(2,1));
    int c=countRectangles(points);
    cout<<c<<endl;
    return 0;
}