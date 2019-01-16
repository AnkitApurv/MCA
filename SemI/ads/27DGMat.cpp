/*  @author Ankit Apurv
    @desc Directed Graph vi Adjacency Matrix
    @date 16/10/2018
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class DGraph
{
    private:
        unsigned int edges, m[10][10];

    public:
        DGraph()
        {
            for(unsigned int i = 0; i <= 9; i++)
            {
                for(unsigned int j = 0; j <= 9; j++)
                {
                    m[i][j] = 0;
                }
            }

        };

        void create(void)
        {
            cout << "Number of edges : ";
            cin >> edges;

            int from = 0, to = 0;

            cout << "Specify the vertices (from <space> to)\n";
            while(from != -1 || to != -1)
            {
                cout << "Vertex : ";
                cin >> from >> to;
                if( !((from >= 1) && (from <= edges)) && !((to >= 1) && (to <= edges)) )
                {
                    cout << "Invalid Vertex\n";
                    break;
                }
                m[from][to] = 1;
            }
        };

        void display(void)
        {
            for(unsigned int i = 1; i <= edges; i++)
            {
                for(unsigned int j = 1; j <= edges; j++)
                {
                    cout << m[i][j] << "\t";
                }
                cout << "\n";
            }
        };
};

int main(void)
{
    system("clear");
    cout << "27 Directed Graph via Adjacency Matrix\n\n";
    DGraph g;
    g.create();
    g.display();
    return 0;
}