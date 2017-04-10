
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <list>
#include <vector>
#include <string>

using namespace std;

void PrintList(vector<list < int> > &lst) {
    for (int i = 0; i < lst.size(); i++) {
        cout << i << ": ";
        for (list<int>::iterator ip = lst[i].begin(); ip != lst[i].end(); ip++) {
            cout << *ip << " ";
        }
        cout << endl;
    }
}

class Graph {
    int numNodes;
    vector<list < int> >
    outlist;
    vector<list < int> >
    inlist;
public:
    Graph(int N) {
        numNodes = N;
        outlist.resize(N);
        inlist.resize(N);
    }

    Graph(string fn) {
        ReadFromFile(fn);
    }


    void Print() {
        cout << "Outlist:" << endl;
        PrintList(outlist);
        cout << "Inlist:" << endl;
        PrintList(inlist);
    }

    int InDegree(int vertex) {
        inlist[vertex].size();
    }

    int OutDegree(int vertex) {
        outlist[vertex].size();
    }

    bool isNeighborDownStream(int neigh, int source) {
        bool result = false;

        for (list<int>::iterator ip = inlist[source].begin(); ip != inlist[source].end(); ip++) {
            if (*ip == neigh) {
                result = true;
            }
        }
        return result;
    }

    bool isNeighborUpStream(int neigh, int source) {
        bool result = false;

        for (list<int>::iterator ip = outlist[source].begin(); ip != outlist[source].end(); ip++) {
            if (*ip == neigh) {
                result =  true;
            }
        }
        return result;
    }

    bool isReachable(int target, int source) {
         for (list<int>::iterator ip = outlist[source].begin(); ip != outlist[source].end(); ip++) {
            if (*ip == target) {
                return true;
            } else {
                return isReachable(*ip, source);
            }
        }

        return false;
    }

    void addEdge(int s, int t) {
        outlist[s].push_back(t);
        inlist[t].push_back(s);
    }


    void ReadFromFile(string fn) {
        ifstream ifs;
        int s, t;

        ifs.open(fn, std::ifstream::in);
        ifs >> numNodes;
        inlist.resize(numNodes);
        outlist.resize(numNodes);

        ifs >> s >> t;
        while (ifs.good()) {
            outlist[s].push_back(t);
            inlist[t].push_back(s);
            ifs >> s >> t;
        }
        ifs.close();
    }
};

int main() {
    Graph g("C:\\Users\\Umut Seven\\Downloads\\data.txt");
    g.Print();

    return 0;
}
