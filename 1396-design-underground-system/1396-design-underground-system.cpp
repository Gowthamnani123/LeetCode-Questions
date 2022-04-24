class UndergroundSystem {
public: 
    map<pair<string, string>, pair<int, int>> travels;
    map<int, pair<string, int>> persons;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        persons[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        if(persons.find(id) != persons.end()){
            string start = persons[id].first;
            int startTime = persons[id].second;
            int sum = 0, count = 0;
            pair<string, string> travel = make_pair(persons[id].first, stationName);
            if(travels.find(travel) != travels.end()){
                sum += travels[travel].first;
                count += travels[travel].second;
            }
            sum += (t - startTime);
            count += 1;
            travels[travel] = make_pair(sum, count);
            persons.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = travels[make_pair(startStation, endStation)];
        int sum = p.first, count = p.second;
        return (double)sum/count;
    }
};
    
 