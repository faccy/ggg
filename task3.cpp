#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class OFF {
private:
	int verticeNums; //顶点数
	int faceNums; //面数
	int edgeNums; //边数
	vector<vector<double>> vertices; //顶点二维数组
	vector<vector<int>> faces; //面数组
public:
	OFF(ifstream& in) {
		string off;
		in >> off;
		in >> verticeNums >> faceNums >> edgeNums;
		//顶点输入
		vertices.resize(verticeNums);
		for (int i = 0; i < verticeNums; ++i) {
			vertices[i].resize(3);
			for (int j = 0; j < 3; ++j) {
				in >> vertices[i][j];
			}
		}
		//面输入
		faces.resize(faceNums);
		for (int i = 0; i < faceNums; ++i) {
			int num;
			in >> num;
			faces[i].resize(num + 1);
			faces[i][0] = num;
			for (int j = 1; j <= faces[i][0]; ++j) {
				in >> faces[i][j];
			}
		}
	}
	//读取顶点的接口
	vector<double> getPoint(int index) {
		return vertices[index];
	}
	//读取面的顶点的接口
	vector<vector<double>> getPointOfFace(int index) {
		vector<vector<double>> res;
		for (int i = 1; i <= faces[index][0]; ++i) {
			res.push_back(vertices[faces[index][i]]);
		}
		return res;
	}
	void printInfo() {
		cout << "文件已读取，共包含顶点" << verticeNums
			<< "个，" << "面" << faceNums << "个" << endl;
	}
};
int main()
{
	string fileRoad = "C:\\Users\\178QT73\\Desktop\\testFile.off";
	ifstream openFile(fileRoad);
	OFF off1(openFile);
	openFile.close();
	off1.printInfo();
	cout << "点测试：" << endl;
	vector<double> point;
	point = off1.getPoint(2);
	for (double ele : point) {
		cout << ele << " ";
	}
	cout << endl;
	cout << "面测试：" << endl;
	vector<vector<double>> pointOfFace = off1.getPointOfFace(3);
	for (auto ele : pointOfFace) {
		for (double sele : ele) {
			cout << sele << " ";
		}
		cout << endl;
	}
	return 0;
}