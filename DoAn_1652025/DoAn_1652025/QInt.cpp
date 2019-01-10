#include "QInt.h"

QInt Div2(QInt a, int &du)
{
	int i, temp, j;
	QInt b;
	b.sign = a.sign;
	b.dodai = a.dodai;
	int n = a.arrbit[a.dodai - 1];
	i = a.dodai - 1;
	while (i >= 0)
	{
		b.arrbit[i] = n / 2;
		temp = n - b.arrbit[i] * 2;
		du = temp;
		i--;
		n = temp * 10 + a.arrbit[i];
	}
	return b;
}


bool* decToBin(QInt a)
{
	int i, c, du;
	bool *kq = new bool[128];
	int temp = 0;
	QInt b;
	if (a.sign > 0)
		kq[0] = 0;
	else
		kq[0] = 1;
	for (i = 127; i > 0; i--)
	{
		b = Div2(a, du);
		if (du == 0)
			kq[i] = 0;
		else
			kq[i] = 1;
		a = b;
	}
	return kq;
}

_int64 binToDec(bool* a)
{
	int i;
	_int64 tong = 0;
	for (i = 127; i > 0; i--)
	{
		if (a[i] == 0)
			tong = tong;
		else
			tong = tong + pow(2, (127 - i));
	}
	if (a[0] == 0)
		return tong;
	else return tong * -1;
}

void ShowBit(bool* a)
{
	int i;
	for (i = 0; i <= 127; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

void binToHex(bool* a, char h[])
{
	long int n = 0;
	int BinLength = 128;
	for (int i = 0; i < BinLength; i++)
	{
		n += ((a[BinLength - i - 1] - 48) * pow(2, i));
	}

	itoa(n, h, 16);
}

void HexToBin(char a[], char b[], int length)
{
	for (int i = 0; i<length; i++)
	{
		changeHexaBit(a[i], b, i * 4);
		puts(b);
	}
}
void changeHexaBit(char a, char b[], int vitri)
{
	switch (a - 48 + 48)
	{
	case 0:
	{
		b[vitri] = 0;
		b[vitri + 1] = 0;
		b[vitri + 2] = 0;
		b[vitri + 3] = 0;
		break;
	}
	case 1:
	{
		b[vitri] = 0;
		b[vitri + 1] = 0;
		b[vitri + 2] = 0;
		b[vitri + 3] = 1;
		break;
	}
	case 2:
	{
		b[vitri] = 0;
		b[vitri + 1] = 0;
		b[vitri + 2] = 1;
		b[vitri + 3] = 0;
		break;
	}
	case 3:
	{
		b[vitri] = 0;
		b[vitri + 1] = 0;
		b[vitri + 2] = 1;
		b[vitri + 3] = 1;
		break;
	}
	case 4:
	{
		b[vitri] = 0;
		b[vitri + 1] = 1;
		b[vitri + 2] = 0;
		b[vitri + 3] = 0;
		break;
	}
	case 5:
	{
		b[vitri] = 0;
		b[vitri + 1] = 1;
		b[vitri + 2] = 0;
		b[vitri + 3] = 1;
		break;
	}
	case 6:
	{
		b[vitri] = 0;
		b[vitri + 1] = 1;
		b[vitri + 2] = 1;
		b[vitri + 3] = 0;
		break;
	}
	case 7:
	{
		b[vitri] = 0;
		b[vitri + 1] = 1;
		b[vitri + 2] = 1;
		b[vitri + 3] = 1;
		break;
	}
	case 8:
	{
		b[vitri] = 1;
		b[vitri + 1] = 0;
		b[vitri + 2] = 0;
		b[vitri + 3] = 0;
		break;
	}
	case 9:
	{
		b[vitri] = 1;
		b[vitri + 1] = 0;
		b[vitri + 2] = 0;
		b[vitri + 3] = 1;
		break;
	}
	case 'a':
	case 'A':
	{
		b[vitri] = 1;
		b[vitri + 1] = 0;
		b[vitri + 2] = 1;
		b[vitri + 3] = 0;
		break;
	}
	case 'b':
	case 'B':
	{
		b[vitri] = 1;
		b[vitri + 1] = 0;
		b[vitri + 2] = 1;
		b[vitri + 3] = 1;
		break;
	}
	case 'c':
	case 'C':
	{
		b[vitri] = 1;
		b[vitri + 1] = 1;
		b[vitri + 2] = 0;
		b[vitri + 3] = 0;
		break;
	}
	case 'd':
	case 'D':
	{
		b[vitri] = 1;
		b[vitri + 1] = 1;
		b[vitri + 2] = 0;
		b[vitri + 3] = 1;
		break;
	}
	case 'e':
	case 'E':
	{
		b[vitri] = 1;
		b[vitri + 1] = 1;
		b[vitri + 2] = 1;
		b[vitri + 3] = 0;
		break;
	}
	case 'f':
	case 'F':
	{
		b[vitri] = 1;
		b[vitri + 1] = 1;
		b[vitri + 2] = 1;
		b[vitri + 3] = 1;
		break;
	}
	}
	puts(b);
}

void khoiTaoQInt(QInt &n)			//Tao 1 so QInt so lieu ao
{
	for (int i = 0; i < MAX; i++) n.arrbit[i] = 0;
	n.dodai = 0;
	n.sign = 1;
}

void chuoiThanhQInt(char *str, QInt &n)
{
	int i;
	if (str[0] == '-')
	{
		n.sign = -1;
		str++; //bỏ qua kí tự đầu tiên
	}
	else
		n.sign = 1;

	n.dodai = strlen(str);//Chiều dài (số chữ số) của số nguyên lớn

	for (i = 0; i<n.dodai; i++)
		n.arrbit[i] = str[n.dodai - i - 1] - '0';//Chuyển từng kí tự thành số
}

int soSanhKo(QInt &a, QInt &b)
{

	if (a.dodai > b.dodai)//Số nào dài hơn thì số đó lớn hơn
		return 1;
	else if (a.dodai < b.dodai)
		return -1;
	else//Trường hợp chiều dài 2 số bằng nhau
	{
		int len = a.dodai - 1;
		while (len >= 0)
		{
			//So sánh từ chữ số
			if (a.arrbit[len]>b.arrbit[len])
				return 1;
			else if (a.arrbit[len]<b.arrbit[len])
				return -1;
			else
				len--;
		}
	}
	return 0;
}

int soSanh(QInt &a, QInt &b)
{
	if (a.sign * b.sign<0) return a.sign;
	return a.sign * soSanhKo(a, b);
}

void taoQInt(QInt &n)		//Đọc số QInt từ bàn phím
{
	char t[100];
	gets_s(t);
	chuoiThanhQInt(t, n);
}

void inQInt(QInt &n)
{
	if (n.sign<0)
		printf("-");
	for (int i = n.dodai - 1; i >= 0; i--)
		printf("%d", (int)n.arrbit[i]);
}

void congKo(QInt &s, QInt &a, QInt &b)
{
	khoiTaoQInt(s);
	if (a.dodai > b.dodai)
		s.dodai = a.dodai;
	else
		s.dodai = b.dodai;
	char m = 0;				//biến nhớ
	for (int i = 0; i<s.dodai; i++)
	{
		s.arrbit[i] = a.arrbit[i] + b.arrbit[i] + m;
		if (s.arrbit[i]>9)
		{
			s.arrbit[i] -= 10;
			m = 1;
		}
		else
			m = 0;
	}
	if (m)
	{
		s.arrbit[s.dodai] = 1;
		s.dodai++;
	}
}

void cong(QInt &s, QInt &a, QInt &b)
{
	if (a.sign*b.sign>0)//Nếu a và b cùng dấu
	{
		congKo(s, a, b);
		s.sign = a.sign;//Dấu của s cũng là dấu của a hoặc b
	}
	else
	{
		int t = soSanhKo(a, b);
		if (t == 1)
		{
			truKo(s, a, b);
			s.sign = a.sign;
		}
		else if (t == -1)
		{
			truKo(s, b, a);
			s.sign = b.sign;
		}
		else
			khoiTaoQInt(s);

	}
}

void truKo(QInt &r, QInt &a, QInt &b)
{
	khoiTaoQInt(r);
	if (a.dodai > b.dodai)
		r.dodai = a.dodai;
	else
		r.dodai = b.dodai;
	int m = 0;
	for (int i = 0; i<r.dodai; i++)
	{
		if (a.arrbit[i] < b.arrbit[i] + m)
		{
			r.arrbit[i] = 10 + a.arrbit[i] - b.arrbit[i] - m;
			m = 1;
		}
		else
		{
			r.arrbit[i] = a.arrbit[i] - b.arrbit[i] - m;
			m = 0;
		}
	}
	while (r.arrbit[r.dodai - 1] == 0) r.dodai--;
}

void tru(QInt &r, QInt &a, QInt &b)
{
	b.sign = -b.sign;
	truKo(r, a, b);
	b.sign = -b.sign;
}

void nhan(QInt &r, QInt &a, QInt &b)
{
	khoiTaoQInt(r);
	for (int i = 0; i<b.dodai; i++)
		for (int j = 0; j<b.arrbit[i]; j++)
			for (int k = 0; k<a.dodai; k++)
			{
				r.arrbit[k + i] += a.arrbit[k];
				if (r.arrbit[k + i]>9)
				{
					r.arrbit[k + i] -= 10;
					r.arrbit[k + i + 1]++;
				}
			}
	r.dodai = a.dodai + b.dodai;
	while (r.arrbit[r.dodai - 1] == 0) r.dodai--;
	r.sign = a.sign*b.sign;
}

void chia(QInt &r, QInt a, QInt b)
{
		khoiTaoQInt(r);
		r.dodai = a.dodai - b.dodai + 1;
		if (a.dodai >= b.dodai)
		{
			int dodaib = b.dodai;
			int i;
			if (a.dodai > b.dodai)
			{
				i = a.dodai - 1;
				int x = a.dodai - b.dodai;
				while (i >= 0)
				{
					if (i >= x)
						b.arrbit[i] = b.arrbit[i - x];
					else
						b.arrbit[i] = 0;
					i--;
				}
			}
			b.dodai = a.dodai;
			QInt d;
			i = 1;
			while (b.dodai >= dodaib)
			{
				while (soSanhKo(a, b) > -1)
				{
					truKo(d, a, b);
					r.arrbit[r.dodai - i]++;
					a = d;
				}
				b.dodai--;
				i++;
				for (int k = 0; k < b.dodai; k++) b.arrbit[k] = b.arrbit[k + 1];
				b.arrbit[b.dodai] = 0;
			}
			while (r.arrbit[r.dodai - 1] == 0)
				r.dodai--;
		}
		r.sign = a.sign*b.sign;
}

bool* and(bool* x, bool* y)
{
	int i;
	bool *kq = new bool[128];
	for (i = 0; i < 128; i++)
	{
		if (x[i] == 1 && y[i] == 1)
			kq[i] = 1;
		else kq[i] = 0;
	}
	return kq;
}

bool* or (bool *x, bool*y)
{
	int i;
	bool *kq = new bool[128];
	for (i = 0; i < 128; i++)
	{
		if (x[i] == 1 || y[i] == 1)
			kq[i] = 1;
		else kq[i] = 0;
	}
	return kq;
}

bool* xor(bool *x, bool *y)
{
	int i;
	bool *kq = new bool[128];
	for (i = 0; i < 128; i++)
	{
		if (x[i] != y[i])
			kq[i] = 1;
		else kq[i] = 0;
	}
	return kq;
}

bool* not(bool* x)
{
	int i;
	bool *kq1 = new bool[128];
	for (i = 0; i < 128; i++)
	{
		if (x[i] == 0)
			kq1[i] = 1;
		else kq1[i] = 0;
	}
	return kq1;
}

bool* shiftleft(bool* x, int j)
{
	int i, dem;
	bool *kq2 = new bool[128];
	kq2 = x;
	for (dem = 1; dem <= j; dem++)
	{
		int i = 1;
		while (i < 127)
		{
			kq2[i] = kq2[i + 1];
			i++;
		}
		kq2[127] = 0;

	}
	return kq2;
}

bool* shiftright(bool* x, int j)
{
	int i, dem;
	bool *kq = new bool[128];
	kq = x;
	for (dem = 1; dem <= j; dem++)
	{
		int i = 127;
		while (i >= 0)
		{
			kq[i] = kq[i - 1];
			i--;
		}
		kq[0] = 0;
	}
	kq[0] = x[0];
	return kq;
}