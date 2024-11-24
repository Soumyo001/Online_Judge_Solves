/*
      ///////////////////////////////////////////////
      /////////// This is just a KNN Demo ///////////
      ////// Displaying the main functionality //////
      ///////////////////////////////////////////////
*/


#include<bits/stdc++.h>
using namespace std;

struct Point{
    vector<double> features;
    int label;
};

double calculateEuclidean(const Point& dataPoint, const Point& newPoint){
    double sum = 0;
    for(int i=0;i<dataPoint.features.size();++i){
        sum+=pow(dataPoint.features[i]-newPoint.features[i], 2);
    }
    return sqrt(sum);
}


int KNN(int k, const vector<Point>& dataset, const Point& newPoint){
    if(k>dataset.size()){
        k=dataset.size();
    }
    vector<pair<double, int>> distances;
    for(const Point& data:dataset){
        double distance = calculateEuclidean(data, newPoint);
        distances.push_back({distance, data.label});
    }
    sort(distances.begin(),distances.end());
    unordered_map<int,int> labelCount;

    for(int i=0;i<k;++i){
        labelCount[distances[i].second]++;
    }

    int mx = INT_MIN;
    int predict = -1;
    for(const auto& i:labelCount){
        if(mx<i.second){
            mx = i.second;
            predict = i.first;
        }
    }
    return predict;
}

int main(void){
    vector<Point> dataset = {
    {{1.0, 2.0}, 0}, {{2.0, 3.0}, 0}, {{1.5, 1.8}, 0},
    {{3.0, 3.0}, 1}, {{3.5, 4.0}, 1}, {{4.0, 4.5}, 1},
    {{5.0, 2.0}, 2}, {{6.0, 3.0}, 2}, {{6.5, 3.5}, 2},
    {{7.0, 4.0}, 2}, {{5.5, 2.5}, 2}, {{4.5, 4.0}, 1},
    {{2.5, 2.0}, 0}, {{3.0, 1.5}, 0}, {{3.5, 3.5}, 1},
    {{7.5, 5.0}, 2}, {{6.0, 5.0}, 1}, {{5.5, 4.5}, 2},
    {{0.5, 1.5}, 0}, {{2.2, 2.8}, 0}, {{1.2, 1.7}, 0},
    {{3.3, 3.7}, 1}, {{3.8, 4.1}, 1}, {{4.3, 4.6}, 1},
    {{5.3, 2.1}, 2}, {{6.3, 3.1}, 2}, {{6.8, 3.6}, 2},
    {{7.3, 4.1}, 2}, {{5.8, 2.6}, 2}, {{4.8, 4.1}, 1},
    {{2.8, 2.2}, 0}, {{3.3, 1.6}, 0}, {{3.7, 3.6}, 1},
    {{7.8, 5.1}, 2}, {{6.2, 5.1}, 1}, {{5.6, 4.6}, 2},
    {{1.1, 2.1}, 0}, {{2.1, 3.2}, 0}, {{1.6, 1.9}, 0},
    {{3.1, 3.1}, 1}, {{3.6, 4.2}, 1}, {{4.1, 4.4}, 1},
    {{5.1, 2.2}, 2}, {{6.1, 3.2}, 2}, {{6.6, 3.7}, 2},
    {{7.2, 4.2}, 2}, {{5.4, 2.3}, 2}, {{4.6, 4.2}, 1},
    {{0.0,0.50}, 0}
    };
    Point newPoint = {{5.3, 4.0}, -1};

    cout<<"Prediction for new point is : "<< KNN(13,dataset,newPoint) <<"\n";
}