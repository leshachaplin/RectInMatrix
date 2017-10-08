#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int i, j, N, M;
    cout << "N=";
    cin >> N;
    cout << "M=";
    cin >> M;

    int matrix[N][M];
    cout << "Input matrix A \n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    cout << "matrix A \n";
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++)
        cout << matrix[i][j]<<" ";
        cout << endl;
    }

    int a, b, c, d;
    cout << "enter coordinates" << endl;
    cin >> a ;
    cin >> b ;
    cin >> c ;
    cin >> d ;
    bool isAFound = false;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (matrix[i][j] == a){
                for (int k = 0; k < M; k++) {
                    if (k == j) continue;

                    if (matrix[i][k] == b ||
                        matrix[i][k] == c ||
                        matrix[i][k] == d) {
                            int point1 = (matrix[i][k] == b) ? c : b;
                            int point2 = (matrix[i][k] == c) ? d : c;
                            for (int x = 0; x < N; x++) {
                                if (x == i) continue;

                                if ((matrix[x][j] == point1 && matrix[x][k] == point2) ||
                                    (matrix[x][j] == point2 && matrix[x][k] == point1)) {
                                    cout << "rectangle found" << endl;
                                    goto afterLoop;
                                }
                            }
                        }
                }
            }
        }
    }
    afterLoop:

    return 0;
}
