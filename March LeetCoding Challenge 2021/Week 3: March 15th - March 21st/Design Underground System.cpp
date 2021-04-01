class UndergroundSystem {
public:
    unordered_map<string,pair<int,int>> time;
    unordered_map<int,pair<string,int>> station;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        station[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string key=station[id].first+"to"+stationName;
        if(time.count(key)>0)
        {
            int value=time[key].first+t-station[id].second;
            int count=time[key].second+1;
            time[key]={value,count};
        }
        else
        {
            time[key]={t-station[id].second,1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto p=time[startStation+"to"+endStation];
        return (double)p.first/(double)p.second;
    }
};
