#include "SupermarketManager.h"

//排序算法
int Partition(vector<Commodity*>& arr, int m, int n) {
	Commodity* mark = arr[m];
	int i = m, j = n;
	while (i < j) {
		while (i < j && mark->getPrice() < arr[j]->getPrice()) {
			j--;
		}
		arr[i] = arr[j];
		while (i < j && arr[i]->getPrice() < mark->getPrice()) {
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = mark;
	return i;
}

void mySort(vector<Commodity*>& arr, int m, int n) {
	if (m < n) {
		int i = Partition(arr, m, n);
		mySort(arr, m, i - 1);
		mySort(arr, i + 1, n);
	}
}

void SupermarketManager::addToVector(Commodity* ca) {
	commodities.push_back(ca);
}

void SupermarketManager::ManageMenu() {
	cout << "文本界面与功能：" << endl
		<< "1、新增商品信息" << endl
		<< "2、删除商品信息" << endl
		<< "3、修改商品信息（ps：例如按Id修改价格、描述等）" << endl
		<< "4、商品信息检索" << endl
		<< "5、商品按价格排序输出" << endl
		<< "6、输出价格前五的商品" << endl
		<< "0、退出" << endl
		<< "请选择功能(0 - 6)：" << endl;
	int operation;
	cin >> operation;
	switch (operation) {
	case 0:
		return;
		break;
	case 1:
		addCommodity();
		break;
	case 2:
		deleteCommodity();
		break;
	case 3:
		modifyCommodity();
		break;
	case 4:
		infoSearch();
		break;
	case 5:
		sortPrint();
		break;
	case 6:
		mostExpensive5();
		break;
	default:
		break;
	}
}

inline void SupermarketManager::backToMenu() {
	cout << "是否返回主菜单（y返回，n退出）：";
	char isBack;
	cin >> isBack;
	if (isBack == 'y') {
		ManageMenu();
	}
	else {}
}

void SupermarketManager::addCommodity() {
	int preSize = commodities.size();
	cout << ">>>>>>增加商品<<<<<<" << endl;
	cout << "类型：";
	string type;
	cin >> type;
	type[0] = toupper(type[0]);
	cout << "名称：";
	string name_;
	cin >> name_;
	cout << "价格：";
	double price_;
	cin >> price_;
	cout << "特性：";
	string features_;
	cin >> features_;
	cout << "数量：";
	int num_;
	cin >> num_;
	if (type == "Drinks") {
		Commodity* tempCom = new Drinks(name_, preSize, price_, num_, features_);
		commodities.push_back(tempCom);
	}
	else if (type == "Tissue") {
		Commodity* tempCom = new Tissue(name_, preSize, price_, num_, features_);
		commodities.push_back(tempCom);
	}
	else {}
	if (commodities.size() == preSize + 1) {
		cout << "商品添加成功" << endl;
	}
	else {
		cout << "商品添加失败" << endl;
	}
	backToMenu();
}

void SupermarketManager::deleteCommodity() {
	cout << ">>>>>>删除商品<<<<<<" << endl;
	cout << "类型：";
	string type;
	cin >> type;
	vector<Commodity*> choseType = (*this)[type];
	for (auto ele : choseType) {
		ele->printInfo();
	}
	cout << endl << "删除商品和数量（如：王老吉，2）：";
	string name_;
	int num_;
	cin >> name_ >> num_;
	if (num_ > choseType.size()) {
		cout << "输入不合法，删除失败！" << endl;
	}
	else {
		for (auto ele : commodities) {
			if (ele->getName() == name_) {
				ele->setNum(ele->getName() - num_);
				break;
			}
		}
		cout << "删除成功！" << endl;
		backToMenu();
	}
}

void SupermarketManager::modifyCommodity() {
	bool changed = false;
	cout << ">>>>>>修改商品<<<<<<" << endl;
	cout << "名称：";
	string name_;
	cin >> name_;
	cout << "修改项（1=价格，2=描述）：";
	int changeItem;
	cin >> changeItem;
	if (changeItem == 1) {
		cout << "新价格：";
		double price_;
		cin >> price_;
		for (auto ele : commodities) {
			if (ele->getName() == name_) {
				ele->setPrice(price_);
				changed = true;
				cout << "价格修改成功" << endl;
				break;
			}
		}
	}
	else if (changeItem == 2) {
		cout << "新描述：";
		string features_;
		cin >> features_;
		for (auto ele : commodities) {
			if (ele->getFeatures() == features_) {
				ele->setFeatures(features_);
				changed = true;
				cout << "描述修改成功" << endl;
				break;
			}
		}
	}
	else {}
	if (!changed) {
		cout << "修改失败" << endl;
	}
	backToMenu();
}

void SupermarketManager::infoSearch() {
	cout << ">>>>>>商品信息检索<<<<<<" << endl;
	cout << "类型：";
	string type;
	cin >> type;
	type[0] = toupper(type[0]);
	if (type == "Drinks") {
		for (auto ele : commodities) {
			if (Drinks* d = dynamic_cast<Drinks*>(ele)) {
				d->printInfo();
			}
		}
	}
	else if (type == "Tissue") {
		for (auto ele : commodities) {
			if (Tissue* t = dynamic_cast<Tissue*>(ele)) {
				t->printInfo();
			}
		}
	}
	else {}
	cout << endl;
	backToMenu();
}

void SupermarketManager::sortPrint() {
	cout << ">>>>>>商品排序输出<<<<<<" << endl;
	if (commodities.size() == 0) {
		cout << "商品列表为空！" << endl;
		return;
	}
	cout << "排序类型（1=由高到低，2=由低到高）:";
	int sortType;
	cin >> sortType;
	mySort(commodities, 0, commodities.size() - 1);
	int len = commodities.size();
	if (sortType == 1) {
		commodities[len - 1]->printInfo();
		for (int i = len - 2; i >= 0; --i) {
			cout << ">";
			commodities[i]->printInfo();
		}
	}
	else if (sortType == 2) {
		commodities[0]->printInfo();
		for (int i = 1; i < len; ++i) {
			cout << "<";
			commodities[i]->printInfo();
		}
	}
	else {}
	backToMenu();
}

void SupermarketManager::mostExpensive5() {
	cout << ">>>>>>价格前五商品<<<<<<" << endl;
	if (commodities.size() == 0) {
		cout << "商品列表为空！" << endl;
		return;
	}
	mySort(commodities, 0, commodities.size() - 1);
	int len = commodities.size();
	if (len <= 5) {
		for (int i = len - 1; i >= 0; --i) {
			commodities[i]->printInfo();
		}
	}
	else {
		for (int i = len - 1; i >= len - 5; --i) {
			commodities[i]->printInfo();
		}
	}
	backToMenu();
}

vector<Commodity*> SupermarketManager::operator[](string& type) {
	vector<Commodity*> res;
	type[0] = toupper(type[0]);
	if (type == "Drinks") {
		for (auto ele : commodities) {
			if (Drinks* d = dynamic_cast<Drinks*>(ele)) {
				res.push_back(d);
			}
		}
	}
	else if (type == "Tissue") {
		for (auto ele : commodities) {
			if (Tissue* t = dynamic_cast<Tissue*>(ele)) {
				res.push_back(t);
			}
		}
	}
	else {}
	return res;
}
