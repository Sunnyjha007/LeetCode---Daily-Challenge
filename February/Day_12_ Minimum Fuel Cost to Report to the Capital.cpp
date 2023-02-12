class Solution {
    long long count = 0;
    vector<int> v;
    pair<long long, long long> getCarsAndPerson(unordered_map<int, vector<int>>& gp, int curr, int seats) {
        long long car = 0, persons = 1;
        v[curr] = 1;
        for (auto val: gp[curr]) {
            if (v[val]) continue;
            auto carsAndPerson = getCarsAndPerson(gp, val, seats);
            car = car + carsAndPerson.first;
            persons += carsAndPerson.second;
            
        }
        count = count + car;
        return {ceil(persons/(seats * 1.0)) , persons};
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> gp;
        for (auto road: roads) {
            gp[road[0]].push_back(road[1]);
            gp[road[1]].push_back(road[0]);
        }
        v.resize(roads.size() + 1, 0);
        
        for (auto val: gp[0]) {
            v[0] = 1;
            auto carsAndPerson = getCarsAndPerson(gp, val, seats);
            count = count + carsAndPerson.first;
        }
        return count;
    }
};
