#include <iostream>
#include <conio.h>
using namespace std;

struct ChiSo
{
	int TocDo;
	int LucSut;
	int TheLuc;
};

struct CauThu
{
	int MaCT;
	char TenCT[50];
	int SoAo;
	int ViTri;
	ChiSo ChiSo;
	unsigned long Luong;
	int PhongDo;
};

struct node
{
	CauThu info;
	node *next;
};

struct list
{
	node *head;
	node *tail;
};

node *GetNode(CauThu x)
{
	node *p;
	p = new node;
	if (p == NULL)
	{
		cout << "Khong du bo nho.";
		exit(1);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void InsertHead(list &l, CauThu x)
{
	node *p;
	p = GetNode(x);
	if (p == NULL)
	{
		cout << "Khong tao duoc nut!";
		exit(1);
	}
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		p->next = l.head;
		l.head = p;
	}
}

CauThu Input()
{
	CauThu x;
	cout << "Nhap ma cau thu: ";
	cin >> x.MaCT;
	cout << "Nhap ten cau thu: ";
	cin.ignore();
	gets_s(x.TenCT);
	cout << "Nhap so ao: ";
	cin >> x.SoAo;
	cout << "\nVI TRI THI DAU\n + Thu mon = 1\n + Tien dao = 2\n + Tien ve = 3\n + Trung ve = 4\n + Hau ve = 5\n";
	cout << "\nNhap vi tri (1-5): ";
	cin >> x.ViTri;
	while (x.ViTri < 1 || x.ViTri > 5)
	{
		cout << "Nhap sai. Vui long nhap lai (1-5): ";
		cin >> x.ViTri;
	}
	cout << "Nhap chi so: ";
	cout << "\n - Toc do (1-100): ";
	cin >> x.ChiSo.TocDo;
	while (x.ChiSo.TocDo < 1 || x.ChiSo.TocDo > 100)
	{
		cout << "   Nhap sai. Vui long nhap lai (1-100): ";
		cin >> x.ChiSo.TocDo;
	}
	cout << " - Luc sut (1-100): ";
	cin >> x.ChiSo.LucSut;
	while (x.ChiSo.LucSut < 1 || x.ChiSo.LucSut > 100)
	{
		cout << "   Nhap sai. Vui long nhap lai (1-100): ";
		cin >> x.ChiSo.LucSut;
	}
	cout << " - The Luc (1-100): ";
	cin >> x.ChiSo.TheLuc;
	while (x.ChiSo.TheLuc < 1 || x.ChiSo.TheLuc > 100)
	{
		cout << "   Nhap sai. Vui long nhap lai (1-100): ";
		cin >> x.ChiSo.TheLuc;
	}
	cout << "Nhap luong: ";
	cin >> x.Luong;
	cout << "\nPHONG DO THI DAU\n + Dinh cao = 1\n + Tot = 2\n + Binh thuong = 3\n + Thap = 4\n + Rat thap = 5\n";
	cout << "\nNhap phong do (1-5): ";
	cin >> x.PhongDo;
	while (x.PhongDo < 1 || x.PhongDo > 5)
	{
		cout << "Nhap sai. Vui long nhap lai (1-5): ";
		cin >> x.PhongDo;
	}
	return x;
}

void OutputLess(list &l)
{
	if (l.head == NULL)
	{
		cout << "Khong co cau thu nao.\n\n";
		return;
	}
	node *p;
	p = l.head;
	while (p != NULL)
	{
		cout << "Ho ten: " << p->info.TenCT << endl;
		cout << "So ao: " << p->info.SoAo << endl << endl;
		p = p->next;
	}
}

void OutputAll(list &l)
{
	if (l.head == NULL)
	{
		cout << "Khong co cau thu nao.\n\n";
		return;
	}
	node *p;
	p = l.head;
	while (p != NULL)
	{
		cout << "Ma cau thu: " << p->info.MaCT << endl;
		cout << "Ho ten: " << p->info.TenCT << endl;
		cout << "So ao: " << p->info.SoAo << endl;
		cout << "Vi tri: ";
		switch (p->info.ViTri)
		{
		case 1:
			cout << "Thu mon";
			break;
		case 2:
			cout << "Tien dao";
			break;
		case 3:
			cout << "Tien ve";
			break;
		case 4:
			cout << "Trung ve";
			break;
		case 5:
			cout << "Hau ve";
			break;
		}
		cout << "\nChi so: \n";
		cout << "- Toc do: " << p->info.ChiSo.TocDo << endl;
		cout << "- Luc sut: " << p->info.ChiSo.LucSut << endl;
		cout << "- The luc: " << p->info.ChiSo.TheLuc << endl;
		cout << "Luong: " << p->info.Luong << endl;
		cout << "Phong do: ";
		switch (p->info.PhongDo)
		{
		case 1:
			cout << "Dinh cao";
			break;
		case 2:
			cout << "Tot";
			break;
		case 3:
			cout << "Binh thuong";
			break;
		case 4:
			cout << "Thap";
			break;
		case 5:
			cout << "Rat thap";
			break;
		}
		cout << "\n\n";
		p = p->next;
	}
}

void OutputTD(list &l)
{
	if (l.head == NULL)
	{
		cout << "Khong co cau thu nao.\n\n";
		return;
	}
	node *p;
	p = l.head;
	while (p != NULL)
	{
		if (p->info.ViTri == 2)
			cout << "Ho ten: " << p->info.TenCT << endl << endl;
		p = p->next;
	}
}

void OutputLuong(list &l)
{
	if (l.head == NULL)
	{
		cout << "Khong co cau thu nao.\n\n";
		return;
	}
	node *p;
	p = l.head;
	while (p != NULL)
	{
		if (p->info.Luong > 20000)
			cout << "Ho ten: " << p->info.TenCT << endl << endl;
		p = p->next;
	}
}

void Swap(node *a, node *b)
{
	CauThu temp = a->info;
	a->info = b->info;
	b->info = temp;
}

void ListSelectionSort(list &l)
{
	if (l.head == NULL)
	{
		cout << "Khong co cau thu nao.\n\n";
		return;
	}
	node *min;
	node *p, *q;
	p = l.head;
	while (p != l.tail)
	{
		min = p;
		q = p->next;
		while (q != NULL)
		{
			if ((q->info.ChiSo.LucSut + q->info.ChiSo.TheLuc + q->info.ChiSo.TocDo) / 3 < (min->info.ChiSo.LucSut + min->info.ChiSo.TheLuc + min->info.ChiSo.TocDo) / 3)
				min = q;
			q = q->next;
		}
		Swap(min, p);
		p = p->next;
	}
	cout << "Sap xep thanh cong!\n\n";
}

node *middleNode(node *start, node *end)
{
	if (start == NULL)
		return NULL;
	node * slowPtr = start;
	node * fastPtr = start->next;
	while (fastPtr != end)
	{
		fastPtr = fastPtr->next;
		if (fastPtr != end)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
		}
	}
	return slowPtr;
}

node *BinarySearch(list &l, int search)
{
	node *start = l.head;
	node *end = NULL;
	do {
		node *mid = middleNode(start, end);
		if (mid == NULL)
			return NULL;
		if ((mid->info.ChiSo.LucSut + mid->info.ChiSo.TheLuc + mid->info.ChiSo.TocDo) / 3 == search)
			return mid;
		else
			if ((mid->info.ChiSo.LucSut + mid->info.ChiSo.TheLuc + mid->info.ChiSo.TocDo) / 3 < search)
				start = mid->next;
			else
				end = mid;
	} while (end == NULL || end->next != start);
	return NULL;
}

void Menu()
{
	cout << "=============================================== MENU ===============================================";
	cout << "\n1. Them mot cau thu vao danh sach cau thu";
	cout << "\n2. Hien thi toan bo cau thu trong danh sach cau thu (chi in ten va so ao)";
	cout << "\n3. Hien thi toan bo cau thu trong danh sach cau thu (in tat ca thong tin)";
	cout << "\n4. Hien thi cac cau thu dang thi dau trong vi tri thi dau: tien dao";
	cout << "\n5. Hien thi cac cau thu co muc luong tren 20000$";
	cout << "\n6. Sap xep cac cau thu theo trung binh chi so cau thu bang thuat toan Sap xep chon (Selection sort)";
	cout << "\n7. Tim mot cau thu theo trung binh chi so cau thu bang thuat toan Tim kiem nhi phan (Binary search)";
	cout << "\n\n0. Thoat";
}

void Process(list &l)
{
	int sel;
	cout << "\n\nChon cong viec (0-7): ";
	cin >> sel;
	while (sel < 0 || sel > 7)
	{
		cout << "Nhap sai. Vui long nhap lai (0-7): ";
		cin >> sel;
	}
	switch (sel)
	{
	case 0:
		exit(1);
	case 1:
		cout << endl;
		CauThu x;
		int check;
		do {
			x = Input();
			InsertHead(l, x);
			cout << "\nThoat hoac tiep tuc (0/1): ";
			cin >> check;
			while (check != 0 && check != 1)
			{
				cout << "Nhap sai. Vui long nhap lai (0/1): ";
				cin >> check;
			}
		} while (check == 1);
		break;
	case 2:
		cout << endl;
		OutputLess(l);
		system("pause");
		break;
	case 3:
		cout << endl;
		OutputAll(l);
		system("pause");
		break;
	case 4:
		cout << endl;
		OutputTD(l);
		system("pause");
		break;
	case 5:
		cout << endl;
		OutputLuong(l);
		system("pause");
		break;
	case 6:
		cout << endl;
		ListSelectionSort(l);
		system("pause");
		break;
	case 7:
		cout << endl;
		int c;
		cout << "LUU Y: Hay chac chan ban da thuc hien cong viec 6 truoc!";
		cout << "\nThoat hoac tiep tuc (0/1): ";
		cin >> c;
		while (c != 0 && c != 1)
		{
			cout << "Nhap sai. Vui long nhap lai (0/1): ";
			cin >> c;
		}
		if (c== 0)
			break;
		int tbChiSo;
		node *p;
		cout << "\nNhap trung binh chi so cau thu can tim: ";
		cin >> tbChiSo;
		p = (BinarySearch(l, tbChiSo));
		if (p != NULL)
		{
			cout << "Ho ten: " << p->info.TenCT << endl;
			cout << "So ao: " << p->info.SoAo << endl << endl;
		}
		else
			cout << "Khong tim thay cau thu nao.\n\n";
		system("pause");
		break;
	}
}

void main()
{
	list l;
	l.head = l.tail = NULL;
	while (1)
	{
		system("cls");
		Menu();
		Process(l);
	}
}

/*
void ShowLess(CauThu x)
{
cout << x.TenCT << "\n";
cout << x.SoAo;
cout << "\n\n";
}

void OutputLess(list &l)
{
node *p;
p = l.head;
while (p != NULL)
{
ShowLess(p->info);
p = p->next;
}
}

//void ShowAll (CauThu x) //Hien it
//{
//	cout << "Ma cau thu: " << x.MaCT;
//	cout << "\nTen cau thu: ";
//	puts(x.TenCT);
//	cout << "So ao: " << x.SoAo;
//	cout << "\nVi tri: ";
//	puts(x.ViTri);
//	cout << "Chi so: ";
//	cout << "\n - Luc sut: " << x.ChiSo.LucSut;
//	cout << "\n - The luc: " << x.ChiSo.TheLuc;
//	cout << "\n - Toc do: " << x.ChiSo.TocDo;
//	cout << "\nLuong: " << x.Luong;
//	//PhongDo PhongDo;
//}

//void OutputAll(list &l) //Hien it
//{
//	node *p;
//	p = l.head;
//	while (p != NULL)
//	{
//		ShowAll(p->info);
//		p = p->next;
//	}
//}

//void OutputViTri(list &l)
//{
//	node *p;
//	p = l.head;
//	while (p != NULL)
//	{
//		if (_stricmp("tien dao", p->info.ViTri) == 0)
//		{
//			cout << "Ten cau thu: ";
//			puts(p->info.TenCT);
//			cout << "So ao: " << p->info.SoAo;
//			cout << "\n\n";
//		}
//		p = p->next;
//	}
//}

void OutputLuong(list &l)
{
node *p;
p = l.head;
while (p != NULL)
{
if (p->info.Luong > 20000)
{
cout << "Ten cau thu: ";
puts(p->info.TenCT);
cout << "So ao: " << p->info.SoAo;
cout << "\n\n";
}
p = p->next;
}
}

//void SelectionSort(list &l)
//{
//	node *min, *p, *q;
//	p = l.head;
//	while (p != l.tail)
//	{
//		min = p;
//		q = p->next;
//		while (q != NULL)
//		{
//			if (q->info < min->info)
//				min = q;
//			q = q->next;
//		}
//		swap(min->info, p->info);
//		p = p->next;
//	}
//}

//int BinarySearch(int a[], int n, int x)
//{
//	int l = 0, r = n - 1, mid;
//	do {
//		mid = (l + r) / 2;
//		if (x == a[mid])
//			return mid;
//		else
//			if (x < a[mid])
//				r = mid - 1;
//			else
//				l = m + 1;
//	} while (l <= r);
//	return -1;
//}

void DeleteHead(list &l)
{
node *p;
if (l.head != NULL)
{
p = l.head;
l.head = l.head->next;
delete p;
if (l.head == NULL)
l.tail = NULL;
}
}

void DeleteAfter(list &l, node *q)
{
node *p;
if (q != NULL)
{
p = q->next;
if (p != NULL)
{
if (p == l.tail)
l.tail = q;
q->next = p->next;
delete p;
}
}
}

*/

/*OutputAll(l);
//cout << "CAU 2\n";
//OutputLess(l);
//cout << "CAU 3\n";
//OutputAll(l);
//cout << "CAU 4\n";
//OutputDetail(l);*/