#include <fstream>
#include <vector>

using namespace std;
ifstream in("INPUT.TXT");      // ������ ����� ������� ������ ��� ������� ������
ofstream out("OUTPUT.TXT");

vector <int> col;                 // � ���� ������� ����� ������������ �����
vector <pair<int,int>> pr;        // � ���� �������� ���� ������
int m;  // ����� ��� ������

bool analiz(int t, vector <int> color) {  // � ���� ����������� ��������� ����� ��������� ����������� (�������)
       for (int z = t; z < m; z++) { // ������� � ���� ������ t
             int a = pr[z].first;
             int b = pr[z].second;
             if (color[a - 1] == 0) {          // ������ �� �������
                    if (color[b - 1] == 0) {   // ������ ����
                           color[a - 1] = 1;   // ��������� ����� ������� ���������
                           color[b - 1] = -1;
                           if (!analiz(z+1, color)) { // ����� �� ����������, ��������� ��������
                                  color[a - 1] = -1;
                                  color[b - 1] = 1;
                                  return analiz(z+1, color); // � ������ ���������
                           }
                    }
                    else color[a - 1] = -color[b - 1]; // �� ������ ����, �������� �1 �� ����
             }
             else { // ������ �������
                    if (color[b - 1] == 0) color[b - 1] = -color[a - 1]; // �� ������ ���� ������� �2 �� ����
                    else { // ������ ����
                           if (color[b - 1] == color[a - 1]) // ������� ���������
                                  return false;
                    }
             }
       }
       return true;
}

int main() {
       out.clear();
       int n;  // ���������� ���
       in >> n >> m;
       int a, b;
       for (int z = 0; z < n; z++) col.push_back(0); // �������� ������ �������
       for (int z = 0; z < m; z++) {
             in >> a >> b;
             pr.push_back(make_pair(a, b));    // ��������� ���� ������
       }
       if (n < 2) { out << "YES"; return 0; }  // ����� ���� � ����, �� �������� ���������

       if (analiz(0,col)) out << "YES";         // � �����. �������� ������
       else out << "NO";
       return 0;
}
