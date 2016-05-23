#include <iostream>
//asldkfja;
using namespace std;

struct  node
{
	int Key;
	int Count;
	node *Left;
	node *Right;
	bool Ltag;
	bool Rtag;
};

class TREE
{
private:
	node *Tree; //Указатель на корень дерева.
	void Search(int, node**);
public:
	TREE() { Tree = NULL; }
	node** GetTree() { return &Tree; } //Получение вершины дерева.
	void BuildTree();
	void CleanTree(node **);
	void ObhodEnd(node **);
	void ObhodLeft(node **);
	void ObhodBack(node **);
	void Vyvod(node**, int);
	void add(node **, int);
	void firmware(node **);
	int Height(node**);
};

int proverkaInt(); //проверка на интовое число

void main()
{
	setlocale(LC_ALL, "Russian");
	TREE A;
	int count = 0;
	int addkey = NULL;
	bool flag = true;
	A.BuildTree();
	A.firmware(A.GetTree());
	while (flag){
		cout << "\nВыберите действие:" << endl;
		cout << "\n1. Вывод дерева\n";
		cout << "\n2. Левосторонний обход дерева\n ";
		cout << "\n3. Концевой обход дерева\n ";
		cout << "\n4. Обратный обход дерева\n ";
		cout << "\n5. Копирование дерева\n";
		cout << "\n6. Вставка элемента\n";
		cout << "\n7. Удаление дерева и выход из программы\n";
		cout << "\n8. Выход из программы\n";
		cin >> count;

		switch (count){
		case 1:
			cout << "\nВывод дерева:\n";
			A.Vyvod(A.GetTree(), 0);
			cout << "\nВысота дерева:" << A.Height(A.GetTree()) << endl;
			break;
		case 2:
			cout << "\nЛевосторонний обход дерева: ";
			A.ObhodLeft(A.GetTree());
			break;
		case 3:
			cout << "\nКонцевой обход дерева: "; A.ObhodEnd(A.GetTree());
			break;
		case 4:
			cout << "\nОбратный обход дерева: "; A.ObhodBack(A.GetTree());
			break;
		case 5:
			//
			break;
		case 6:
			cout << "\nВставка элемента\n";
			cout << "Введите элемент для вставки: ";
			addkey = proverkaInt();
			A.add(A.GetTree(), addkey);
			A.Vyvod(A.GetTree(), 0);
			break;
		case 7:
			cout << "\nУдаление дерева: ";
			A.CleanTree(A.GetTree());
			flag = false;
			break;
		case 8:
			flag = false;
			break;
		default:
			cout << "Неверно! Повторите ввод...";
		}
	}


}

int proverkaInt(){
	bool flag = false;
	char k[20];
	do{
		flag = false;
		_flushall();
		cin.getline(k, 20);
		for (int i = 0; k[i] != '\0'; i++){
			if ((k[i] < '0') || (k[i] > '9')){
				flag = true;
				break;
			}
		}
		if (atoi(k) == 0)
			flag = true;
		if (flag == true){
			cout << "Incorrect data \n";
			cout << "Try again \n";
		}
	} while (flag == true);
	return atoi(k);
}

void TREE::BuildTree()
// Построение бинарного дерева (рекурсивный алгоритм).
// Tree - указатель на корень дерева.
{
	int el;

	cout << "Вводите ключи вершин дерева\nДля завершения ввода введите '0'\n";
	cin >> el;
	while (el != 0)
	{
		Search(el, &Tree); cin >> el;
	}
}

void TREE::Search(int x, node **p)
//  Поиск вершины с ключом x в дереве со вставкой
//             (рекурсивный алгоритм).
// *p - указатель на корень дерева.
{
	if (*p == NULL)
	{// Вершины в дереве нет; включить ее.
		*p = new(node);
		(**p).Key = x;     (**p).Count = 1;
		(**p).Left = NULL; (**p).Right = NULL;
	}
	else
		if (x<(**p).Key) Search(x, &((**p).Left));
		else
			if (x>(**p).Key) Search(x, &((**p).Right));
			else  (**p).Count = (**p).Count + 1;
}

void TREE::ObhodLeft(node **w)
//Левосторонний обход дерева.
//*w - указатель на корень дерева.
{
	if (*w != NULL)
	{
		cout << (**w).Key << " ";
		if ((*w)->Ltag == true)//
			ObhodLeft(&((**w).Left));
		if ((*w)->Rtag == true)//
			ObhodLeft(&((**w).Right));
	}
}

void TREE::firmware(node **w){//
	if (*w != NULL){
		firmware(&((**w).Left));
		if ((*w)->Left != NULL){
			(*w)->Ltag = true;
		}
		else {
			(*w)->Ltag = false;
			(*w)->Left = (*w);
		}
		firmware(&((**w).Right));
		if ((*w)->Right != NULL){
			(*w)->Rtag = true;
		}
		else {
			(*w)->Rtag = false;
			(*w)->Right = (*w);
		}
	}


}

void TREE::ObhodEnd(node **w)
//Концевой обход дерева.
//*w - указатель на корень дерева.
{
	if (*w != NULL)
	{
		if ((*w)->Ltag == true)//
			ObhodEnd(&((**w).Left));
		if ((*w)->Rtag == true)//
			ObhodEnd(&((**w).Right));
		cout << (**w).Key << " ";
	}
}

void TREE::ObhodBack(node **w)
//Обратный обход дерева.
//*w - указатель на корень дерева.
{
	if (*w != NULL)
	{
		if ((*w)->Ltag == true)//
			ObhodBack(&((**w).Left));
		cout << (**w).Key << " ";
		if ((*w)->Rtag == true)//
			ObhodBack(&((**w).Right));
	}
}

void TREE::CleanTree(node **w)
//Очистка дерева.
//*w - указатель на корень дерева.
{
	if (*w != NULL)
	{
		if ((*w)->Ltag == true)//
			CleanTree(&((**w).Left));
		if ((*w)->Rtag == true)//
			CleanTree(&((**w).Right));
		delete *w;
	}
}

void TREE::Vyvod(node **w, int l)
//Изображение дерева *w на экране дисплея 
// (рекурсивный алгоритм). 
//*w - указатель на корень дерева. 
{
	int i;
	bool flag = false;
	if (*w != NULL)
	{
		flag = false;
		if ((*w)->Rtag == true){
			Vyvod(&((**w).Right), l + 1);
			flag = true;
			for (i = 1; i <= l; i++) cout << " ";
			cout << (**w).Key << endl;
		}
		if ((*w)->Ltag == true){// 
			Vyvod(&((**w).Left), l + 1);
			if (flag == false){
				for (i = 1; i <= l; i++) cout << " ";
				cout << (**w).Key << endl;
			}
		}

		if ((*w)->Ltag == false && (*w)->Rtag == false){
			for (i = 1; i <= l; i++) cout << " ";
			cout << (**w).Key << endl;
		}
		//for (i = 1; i <= l; i++) cout « " "; 
		//cout « (**w).Key « endl; 
	}
}

void TREE::add(node **w, int Key){
	if (*w != NULL){
		if ((*w)->Ltag == true){// 
			if (Key < (*w)->Key){
				add(&(*w)->Left, Key);

			}
			else if (Key == (*w)->Key){
				(*w)->Count++;
				return;
			}

		}
		if ((*w)->Rtag == true){// 
			if (Key >(*w)->Key){
				add(&(*w)->Right, Key);
			}
			else if (Key == (*w)->Key){
				(*w)->Count++;
				return;
			}

		}
		else {
			node *temp = new node;
			temp->Key = Key;
			temp->Left = temp;
			temp->Right = temp;
			temp->Count = 1;
			temp->Rtag = false;
			temp->Ltag = false;
			if (Key < (*w)->Key){
				(*w)->Left = temp;
				(*w)->Ltag = true;
			}
			else if (Key >(*w)->Key){
				(*w)->Right = temp;
				(*w)->Rtag = true;
			}
			else{
				(*w)->Count++;
			}
			return;
		}
	}
	else{
		*w = new node;
		(*w)->Key = Key;
		(*w)->Left = *w;
		(*w)->Right = *w;
		(*w)->Count = 1;
		(*w)->Ltag = false;
		(*w)->Rtag = false;
	}
}

int TREE::Height(node **w)
//Определение высоты бинарного дерева.
//*w - указатель на корень дерева.
{
	int h1 = 0, h2 = 0;
	if (*w == NULL) return (-1);
	else
	{
		if ((*w)->Ltag == true)//
			h1 = Height(&((**w).Left));
		if ((*w)->Rtag == true)//
			h2 = Height(&((**w).Right));
		if (h1>h2) return (1 + h1);
		else  return (1 + h2);

	}
}