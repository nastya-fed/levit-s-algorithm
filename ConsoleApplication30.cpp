// ConsoleApplication30.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <time.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <ctime>

//#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> rib;
typedef vector<vector<rib> > graph;

const int inf = 1000 * 1000 * 1000;

void print_g(graph& g) {
    for (int i = 0; i < g.size(); i++) {
        cout << i << ":\n";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j].first << ':' << g[i][j].second << ' ';
        }
        cout << "\n";
    }
}



//алгоритм Левита

int main(){
  
    srand(time(0));
    int c = 0;
    while(c < 30){
        cout << c << "\n";
        c++;
        int n = 100, v1 = 0, W = 100;
       
        int m = n * 10;
        graph g(n);
        
        vector<set<int> > vs(n);
        //cout << rand() << "\n";
        for(int i = 0; i<n-1; i++){
            int w = rand() % W + 1;
            g[i].push_back({i+1, w});
            
            vs[i].insert(i+1);
            
        };
        for(int i = n; i<=m; i++){
            int v_1 = rand() % n;
            int v_2 = rand() % n;
            while(v_1 == v_2 || vs[v_1].find(v_2) != vs[v_1].end()){
                v_1 = rand() % n;
                v_2 = rand() % n;
            }
            int w = rand() % W + 1;
            g[v_1].push_back({v_2, w});
            
            vs[v_1].insert(v_2);
            
        }
        print_g(g);
        vector<int> d(n, inf);
        d[v1] = 0;
        vector<int> id(n);
        id[v1] = 1;
        deque<int> q;
        q.push_back(v1);
        vector<int> p(n, -1);
        int ma = 0;
        int mi = inf;
        auto start = clock();
        while (!q.empty())
        {
            
            if(q.size() > ma){
                ma = q.size();
            }
            int v = q.front();
            q.pop_front();
            id[v] = 2;
            for (size_t i=0; i<g[v].size(); ++i)
            {
                int to = g[v][i].first, len = g[v][i].second;
                if (d[to] > d[v] + len)
                {
                    d[to] = d[v] + len;
                    if(id[to] == 0)
                        q.push_back(to);
                    else if(id[to] == 2)
                        q.push_front(to);
                    p[to] = v;
                    id[to] = 1;
                }
            }
        }
        auto end = clock();
        //cout << start << "\n";
        cout << end - start << "\n";
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
