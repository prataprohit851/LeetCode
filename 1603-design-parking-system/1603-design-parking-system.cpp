class ParkingSystem {
public:
    vector<int> ht;
    ParkingSystem(int big, int medium, int small) {
        ht.resize(3);
        ht[0] = big;
        ht[1] = medium;
        ht[2] = small;
    }
    
    bool addCar(int carType) {
        ht[carType-1]--;
        return ht[carType-1] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */