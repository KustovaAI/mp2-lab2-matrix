// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j;
  int n;
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;

  cout << "Введите размеры матриц: " << endl;
  cin >> n;
  TMatrix<int> a1(n), b1(n), c1(n);
  cout << "Введите первую матрицу: " << endl;
  cin >> a1;
  cout << "Введите вторую матрицу: " << endl;
  cin >> b1;
  cout << "Matrix a1 = " << endl << a1 << endl;
  cout << "Matrix b1 = " << endl << b1 << endl;
  if (a1 == b1) cout << "Матрицы равны" << endl;
	else cout << "Матрицы не равны" << endl;
  c1 = a1 + b1;
  cout << "Matrix c1 = a1 + b1" << endl << c1 << endl;
  c1 = a1 - b1;
  cout << "Matrix c1 = a1 - b1" << endl << c1 << endl;


}
//---------------------------------------------------------------------------
