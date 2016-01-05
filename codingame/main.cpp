#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Human{
private:
    int id,x,y;
    double dist;
    double nearest_zombie_dist;

public:
    void humanInput(int, int);
    void setDist(double _dist) { dist = _dist;}
    int getX() { return x; }
    int getY() { return y; }
    int getDist() { return nearest_zombie_dist; }
};

void Human::humanInput(int ash_x, int ash_y){
    cin >> id >> x >> y; cin.ignore();
    dist = sqrt(pow(ash_x - x, 2) + pow(ash_y - y, 2));
    nearest_zombie_dist = 999999;
}


class Zombie{
private:
    int id, x, y, next_x, next_y;
public:
    void zombieInput();
    int getX() { return x; }
    int getY() { return y; }
};

void Zombie::zombieInput(){
    cin >> id >> x >> y >> next_x >> next_y;
}


double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double distBetweenHumanAndZombie(Human human, Zombie zombie){
    return dist(human.getX(), human.getY(), zombie.getX(), zombie.getY());
}


int main()
{
    // game loop
    while (1) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        int humanCount;
        cin >> humanCount; cin.ignore();
        vector<Human> human(humanCount);

        for(int i = 0;i < humanCount; i++){
            human[i].humanInput(x, y);
        }
        int zombieCount;
        cin >> zombieCount; cin.ignore();
        vector<Zombie> zombie;
        for (int i = 0; i < zombieCount; i++) {
            zombie[i].zombieInput();
            for(int j = 0;j < humanCount; j++){
                human[j].setDist(min(human[j].getDist(), distBetweenHumanAndZombie(human[j], zombie[i])));
            }
        }

        int minx=human[0].getX(), miny=human[0].getY();
        double maxdist = human[0].getDist();
        for(int i = 1;i < humanCount; i++){
            if(maxdist < human[i].getDist()){
                minx = human[i].getX();
                miny = human[i].getY();
                maxdist = human[i].getDist();
            }
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        


        cout << minx << " " << miny << endl; // Your destination coordinates
    }
}