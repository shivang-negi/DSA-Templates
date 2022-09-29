#include<iostream>
#include<vector>
#include<iomanip>
#include<ios>
using namespace std;

void findans(vector<vector<double>>&graph, int nodes, int time, int start, double p, vector<double>& answer)
{
    if(time <= 0) {
        answer[start] += p;
        return;
    }

    for(int i=1;i<=nodes;i++)
        if(graph[start][i] != 0) {
            p *= graph[start][i];
            findans(graph, nodes, time-10 , i , p ,answer);
            p /= graph[start][i];
        }
}

int main()
{
    int t;
    cin>>t;
	vector<pair<int,double>> res;
    while(t--)
    {
		cin.tie(NULL);
        int nodes,edges,time;
        cin>>nodes>>edges>>time;
        vector<vector<double>> graph(nodes+1,vector<double>(nodes+1,0));
		for(int i=0;i<edges;i++) {
			int from,to;
			double p;
			cin>>from>>to>>p;
			graph[from][to] = p;
		}
		vector<double> answer(nodes+1,0);
        findans(graph, nodes, time, 1, 1.0, answer);
        double final_prob = -1; int final_div = 0;
        for(int i=1;i<=nodes;i++)
        {
            if(answer[i]>final_prob)
            {
                final_prob = answer[i];
                final_div = i;
            }
        }
		res.push_back({final_div,final_prob});
    }
	for(auto x:res)
		{
			cout<<x.first<<" ";
			cout<<setprecision(6)<<fixed;
			cout<<x.second<<endl;
		}
    return 0;
}