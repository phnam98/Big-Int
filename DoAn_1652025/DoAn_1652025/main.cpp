#include "QInt.h"

void main()
{
	QInt a, b, c;
	bool* x, *y, *d, *e, *f, *k1, *k2, *m, *n, *p1, *p2;
	char h[128], g[128], i[128], j[128];
	int z;
	khoiTaoQInt(a);
	khoiTaoQInt(b);
	khoiTaoQInt(c);
	printf("Nhap vao so QInt thu 1: ");
	taoQInt(a);
	x = decToBin(a);
	ShowBit(x);
	printf("Nhi phan sang thap phan: %d\n", binToDec(x));
	binToHex(x, h);
	printf("Chuyen thanh he hexa la: ");
	puts(h);
	/*HexToBin(h, i, 128);*/

	printf("Nhap vao so QInt thu 2: ");
	taoQInt(b);
	y = decToBin(b);
	ShowBit(y);
	printf("Nhi phan sang thap phan: %d\n", binToDec(y));
	binToHex(y, g);
	printf("Chuyen thanh he hexa la: ");
	puts(g);
	/*HexToBin(g, j, 128);*/

	d = and (x, y);
	printf("\nKet qua x and y: ");
	ShowBit(d);
	printf("\n");

	e = or (x, y);
	printf("\nKet qua x or y:  ");
	ShowBit(e);
	printf("\n");

	f = xor (x, y);
	printf("\nKet qua x xor y:  ");
	ShowBit(f);
	printf("\n");

	m = not(x);
	printf("\nKet qua not x:  ");
	ShowBit(m);
	printf("\n");

	n = not(y);
	printf("\nKet qua not y:  ");
	ShowBit(n);
	printf("\n");

	printf("So bit can dich: ");
	scanf_s("%d", &z);
	
	k1 = shiftleft(x, z);
	printf("\nKet qua dich trai x:  ");
	ShowBit(k1);
	printf("\n");

	k2 = shiftleft(y, z);
	printf("\nKet qua dich trai y:  ");
	ShowBit(k2);
	printf("\n");
	
	p1 = shiftright(k1, z);
	printf("\nKet qua dich phai sau khi dich trai x:  ");
	ShowBit(p1);
	printf("\n");

	p2 = shiftright(k2, z);
	printf("\nKet qua dich phai sau khi dich trai y:  ");
	ShowBit(p2);
	printf("\n");

	cong(c, a, b);
	printf("a + b = ");
	inQInt(c);
	printf("\n");

	tru(c, a, b);
	printf("a - b = ");
	inQInt(c);
	printf("\n");

	nhan(c, a, b);
	printf("a * b = ");
	inQInt(c);
	printf("\n");

	if (soSanh(a, b) == -1)
		printf("a / b = 0");
	else
	{
		chia(c, a, b);
		printf("a / b = ");
		inQInt(c);
		printf("\n");
	}

	printf("\n");
	system("pause");

}
