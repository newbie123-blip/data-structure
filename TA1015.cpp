#include<iostream>
using namespace std;

class GameCharacter
{
public:
	string name;
	int hp;
	int level;
	GameCharacter(string n, int h, int l)
	{
		name = n;
		hp = h;
		level = l;
	}

	void damage(int value)
	{
		hp -= value;
		if (hp < 0) {
			hp = 0;
		}
	}
	void heal(int value)
	{
		hp += value;
		if (hp > 100) {
			hp = 100;
		}
	}
	void levelUp(int value)
	{
		level += value;
		hp = 100;
	}
	void show()
	{
		cout << "=====角色=====" << "\n";
		cout << "名稱: " << name << "\n";
		cout << "血量: " << hp << "\n";
		cout << "等級: " << level << "\n";
	}
};

int main() {
	string x;
	int a, b, c;
	cout << "輸入名稱: ";
	cin >> x;
	cout << "輸入血量: ";
	cin >> b;
	cout << "輸入等級: ";
	cin >> c;

	GameCharacter p1(x, b, c);

	cout << "==========選單==========" << "\n";
	cout << "1.扣血" << "\n";
	cout << "2.回血" << "\n";
	cout << "3.升級" << "\n";
	cout << "4.show角色資料" << "\n";
	cout << "5.show全部角色" << "\n";
	cout << "6.結束程式" << "\n";

	while (cin>>a,a) {
		int temp;
		if (a==1) {
			cout << "要扣多少血"<<"\n";
			cin >> temp;
			p1.damage(temp);
		}else if (a == 2) {
			cout << "要回多少血" << "\n";
			cin >> temp;
			p1.heal(temp);
		}
		else if (a == 3) {
			cout << "要升多少級" << "\n";
			cin >> temp;
			p1.levelUp(temp);
		}
		else if (a == 4) {
			p1.show();
		}
		else if (a == 5) {
			p1.show();
		}
	}

	return 0;
}