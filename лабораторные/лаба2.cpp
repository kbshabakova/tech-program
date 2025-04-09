#include <iostream>
#include <iomanip>
#include <cstdlib>

class vect {
private:
    int dim;          // Размерность вектора
    double* b;       // Массив для хранения элементов вектора
    static int count; // Статический счетчик объектов
    int num;         // Номер объекта

public:
    vect(int d) : dim(d), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; ++i) {
            b[i] = rand() % 10; // Инициализация случайными числами
        }
        std::cout << "Конструктор vect " << num << " вызван." << std::endl;
    }

    ~vect() {
        std::cout << "Деструктор vect " << num << " вызван." << std::endl;
        delete[] b;
    }

    // Оператор сложения
    vect operator+(const vect& v) {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = this->b[i] + v.b[i];
        }
        std::cout << "Сложение vect " << num << " и vect " << v.num << " выполнено." << std::endl;
        return result;
    }

    // Оператор вычитания
    vect operator-(const vect& v) {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = this->b[i] - v.b[i];
        }
        std::cout << "Вычитание vect " << num << " и vect " << v.num << " выполнено." << std::endl;
        return result;
    }

    // Оператор унарного минуса
    vect operator-() {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = -this->b[i];
        }
        std::cout << "Унарный минус vect " << num << " выполнен." << std::endl;
        return result;
    }

    // Оператор скалярного произведения
    double operator*(const vect& v) {
        double result = 0;
        for (int i = 0; i < dim; ++i) {
            result += this->b[i] * v.b[i];
        }
        std::cout << "Скалярное произведение vect " << num << " и vect " << v.num << " выполнено." << std::endl;
        return result;
    }

    // Оператор умножения на скаляр
    vect operator*(double k) {
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = k * this->b[i];
        }
        std::cout << "Умножение vect " << num << " на скаляр " << k << " выполнено." << std::endl;
        return result;
    }

    // Оператор присваивания
    vect& operator=(const vect& v) {
        if (this != &v) {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; ++i) {
                b[i] = v.b[i];
            }
        }
        std::cout << "Присваивание vect " << num << " от vect " << v.num << " выполнено." << std::endl;
        return *this;
    }

    // Оператор индексирования
    double& operator[](int index) {
        return b[index]; // Возвращаем элемент по индексу
    }

    // Константный оператор индексирования
    const double& operator[](int index) const {
        return b[index]; // Возвращаем элемент по индексу
    }

    // Метод для получения размерности
    int getDim() const { return dim; }

    // Метод для получения номера объекта
    int getNum() const { return num; }

    void print() {
        std::cout << "vect " << num << ": ";
        for (int i = 0; i < dim; ++i) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }

    static int getCount() { return count; }
};

int vect::count = 0; // Инициализация статического счетчика

class matr {
private:
    int dim;          // Размерность матрицы (предполагается квадратная)
    double** a;      // Двумерный массив для хранения элементов матрицы
    static int count; // Статический счетчик объектов
    int num;         // Номер объекта

public:
    matr(int d) : dim(d), num(++count) {
        a = new double* [dim];
        for (int i = 0; i < dim; ++i) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                a[i][j] = rand() % 10; // Инициализация случайными числами
            }
        }
        std::cout << "Конструктор matr " << num << " вызван." << std::endl;
    }

    ~matr() {
        std::cout << "Деструктор matr " << num << " вызван." << std::endl;
        for (int i = 0; i < dim; ++i) {
            delete[] a[i];
        }
        delete[] a;
    }

    // Оператор сложения
    matr operator+(const matr& m) {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = this->a[i][j] + m.a[i][j];
            }
        }
        std::cout << "Сложение matr " << num << " и matr " << m.num << " выполнено." << std::endl;
        return result;
    }

    // Оператор вычитания
    matr operator-(const matr& m) {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = this->a[i][j] - m.a[i][j];
            }
        }
        std::cout << "Вычитание matr " << num << " и matr " << m.num << " выполнено." << std::endl;
        return result;
    }

    // Оператор унарного минуса
    matr operator-() {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = -this->a[i][j];
            }
        }
        std::cout << "Унарный минус matr " << num << " выполнен." << std::endl;
        return result;
    }

    // Оператор умножения матриц
    matr operator*(const matr& m) {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = 0;
                for (int k = 0; k < dim; ++k) {
                    result.a[i][j] += this->a[i][k] * m.a[k][j];
                }
            }
        }
        std::cout << "Умножение matr " << num << " и matr " << m.num << " выполнено." << std::endl;
        return result;
    }

    // Оператор умножения на скаляр
    matr operator*(double k) {
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                result.a[i][j] = k * this->a[i][j];
            }
        }
        std::cout << "Умножение matr " << num << " на скаляр " << k << " выполнено." << std::endl;
        return result;
    }

    // Оператор присваивания
    matr& operator=(const matr& m) {
        if (this != &m) {
            for (int i = 0; i < dim; ++i) {
                delete[] a[i];
            }
            delete[] a;

            dim = m.dim;
            a = new double* [dim];
            for (int i = 0; i < dim; ++i) {
                a[i] = new double[dim];
                for (int j = 0; j < dim; ++j) {
                    a[i][j] = m.a[i][j];
                }
            }
        }
        std::cout << "Присваивание matr " << num << " от matr " << m.num << " выполнено." << std::endl;
        return *this;
    }

    // Умножение матрицы на вектор
    vect operator*(const vect& v) {
        vect result(v.getDim());
        for (int i = 0; i < dim; ++i) {
            result[i] = 0;
            for (int j = 0; j < dim; ++j) {
                result[i] += this->a[i][j] * v[j];
            }
        }
        std::cout << "Умножение matr " << num << " на vect " << v.getNum() << " выполнено." << std::endl;
        return result;
    }

    void print() {
        std::cout << "matr " << num << ":\n";
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                std::cout << std::setw(5) << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    int getDim() const { return dim; }
    int getNum() const { return num; }
    static int getCount() { return count; }
};

int matr::count = 0; // Инициализация статического счетчика

int main() {
    // Создание векторов
    vect v1(3);
    vect v2(3);
    v1.print();
    v2.print();

    vect v3 = v1 + v2;
    v3.print();

    vect v4 = v1 - v2;
    v4.print();

    vect v5 = -v1;
    v5.print();

    double dotProduct = v1 * v2;
    std::cout << "Скалярное произведение: " << dotProduct << std::endl;

    vect v6 = v1 * 2.5;
    v6.print();

    v1 = v2;
    v1.print();

    // Создание матриц
    matr m1(3);
    matr m2(3);
    m1.print();
    m2.print();

    matr m3 = m1 + m2;
    m3.print();

    matr m4 = m1 - m2;
    m4.print();

    matr m5 = -m1;
    m5.print();

    matr m6 = m1 * m2;
    m6.print();

    matr m7 = m1 * 1.5;
    m7.print();

    vect v7 = m1 * v1;
    v7.print();

    return 0;
}
