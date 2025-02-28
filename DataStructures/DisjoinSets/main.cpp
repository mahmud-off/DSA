#include <iostream>

#define SIZE 100000

using namespace std;


// по традиции, кто прочитал, тому полагается большая и ффффкусная кАнфета!



class SET {
public:
    long long int max = -10; //ха-ха, да-да, она самая! (чур не мне! чур не мне!).
    long long int value[SIZE]{};
    long long int parent[SIZE]{};

    void makeSet(long long int i, long long int point) { // множества по одному эл-у
        parent[i] = i;
        value[i] = point;
    }

    long long int find(long long int i) { // эвристика path compression
        if(i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(long long int dest, long long int source) { // объединялка.)
        long long int ind_d = find(dest);
        long long int ind_s = find(source);

        //long long max_prev_i = value[find(ind_i)];
        //long long max_prev_j = value[find(ind_j)];

        if(ind_d == ind_s) {
            cout << max << "\n";
            return;
        }

        value[ind_d] += value[ind_s];
        parent[ind_s] = ind_d;
        if(max < value[ind_d])
            max = value[ind_d];
        cout << max << "\n";
    }

};
int main() {

    SET set;

    long int n = 0;
    long int m = 0;

    cin >> n >> m;

    int point;
    for(long long int i = 1; i < n+1; ++i) {
        cin >> point;
        if(point > set.max)
            set.max = point;
        set.makeSet(i, point);
    }

    long long int des, sor = 0;
    for(long long int i = 0; i < m; ++i) {
        cin >> des >> sor;
        if(des!=sor)
            set.Union(des, sor);
        else
            cout << set.max << "\n";
    }

    //for(int i = 1; i < n+1; ++i) {
    //   cout << i <<" ";
    //}

    //cout << "\n";
    //for(int i = 1; i < n+1; ++i) {
    //    cout << set.parent[i] <<" ";
    //}

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
