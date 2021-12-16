#include<iostream>
using namespace std;

class Matrix {
    //n*n矩阵
    int n, a[100][100];

public:
    //构造函数
    Matrix(int N = 0) : n(N) {}

    //输入矩阵
    void input() {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
    }

    //输出矩阵
    void output() {
        cout << "----------------" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    //交换两个数值
    void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    //转置
    void T() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(a[i][j], a[j][i]);
    }

    //上下翻转
    void updown() {
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n / 2; i++)
                swap(a[i][j], a[n - i - 1][j]);
    }
};

int main() {
    Matrix m;
    m.input();
    m.updown();
    m.T();
    m.output();
}
