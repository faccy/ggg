#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	string fileRoad = "C:\\Users\\178QT73\\Desktop\\testFile.off";
	ifstream openFile(fileRoad);
	string off;
	openFile >> off;
	//顶点数，面数，边数
	int verticeNums, faceNums, edgeNums;
	openFile >> verticeNums >> faceNums >> edgeNums;
	vector<vector<double>> vertices(verticeNums, vector<double>(3, 0));
	vector<vector<int>> indexs;
	vector<int> verticeNumsOfFace(faceNums, 0);
	for (int i = 0; i < verticeNums; ++i) {
		for (int j = 0; j < 3; ++j) {
			openFile >> vertices[i][j];
		}
	}
	for (int i = 0; i < faceNums; ++i) {
		openFile >> verticeNumsOfFace[i];
		vector<int> indexOfFace(verticeNumsOfFace[i], 0);
		for (int j = 0; j < verticeNumsOfFace[i]; ++j) {
			openFile >> indexOfFace[j];
		}
		indexs.push_back(indexOfFace);
	}
	openFile.close();
	cout << "文件已读取，共包含顶点" << verticeNums << "个，" << "面" << faceNums << "个" << endl;
	while (1) {
		cout << "********************************" << endl;
		cout << "您接下来的操作是：" << endl;
		cout << "1. 查询顶点坐标" << endl;
		cout << "2. 查询面的顶点坐标" << endl;
		cout << "输入数字以选择,输入-1结束操作" << endl;
		cout << "********************************" << endl;
		int operation, index;
		cin >> operation;
		while (cin.fail()) {
			cout << "输入不合法！请输入整数" << endl;
			cin.clear();
			cin.ignore();
			cin >> operation;
		}
		switch (operation) {
		case 1:
			cout << "请输入要查询的顶点索引：" << endl;
			cin >> index;
			while (cin.fail()) {
				cout << "输入不合法！请输入整数" << endl;
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			if (index < 0 || index > verticeNums) {
				cout << "索引越界！返回主界面" << endl;
				break;
			}
			for (int i = 0; i < 3; ++i) {
				cout << vertices[index][i] << " ";
			}
			cout << endl;
			break;
		case 2:
			cout << "请输入要查询的面索引：" << endl;
			cin >> index;
			while (cin.fail()) {
				cout << "输入不合法！请输入整数" << endl;
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			if (index < 0 || index > faceNums) {
				cout << "索引越界！返回主界面" << endl;
				break;
			}
			for (int i = 0; i < indexs[index].size(); ++i) {
				for (int j = 0; j < 3; ++j) {
					cout << vertices[indexs[index][i]][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			break;
		case -1:
			return 0;
		default:
			cout << "输入不合法！请输入整数" << endl;
		}
	}
	return 0;
}