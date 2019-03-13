#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("matrice.in");
ofstream fout("matrice1.out");

class Matrice;

class Vector {
private:
    int n;
    int v[100];
public:
    friend class Matrice;

    Vector() {

    }

    Vector(int n, int v[]) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            this->v[i] = v[i];
        }
        //   fout << "constr parametri\n";
    }

    void seteazaN(int n) {
        this->n = n;
    }

    void afisare() {
        //         cout << "n=" << n << endl;
        for (int i = 0; i < n; i++) {
            fout << v[i] << " ";
        }
        fout << endl;
    }

    int suma() {
        int s = 0;
        for (int i = 0; i < n; i++)
            s = s + v[i];
        return s;
    }

    void maxim() {
        int maxi = 0, poz = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] > maxi) {
                maxi = v[i];
                poz = i;
            }
        }
        fout << "valoarea maxima din vector este " << maxi << "si pozitia sa este " << poz;
    }

    void ord_vect(int c[]) {

        for (int i = 0; i < n; i++)
            c[i] = v[i];

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (c[i] > c[j]) {
                    int aux;
                    aux = c[i];
                    c[i] = c[j];
                    c[j] = aux;

                }
            }
        }



    }

    int operator*(Vector v) //produsul scalar a doi vectori
    {
        //return e1 * v.e1 + e2 * v.e2;
        int p = 1;
        for (int i = 0; i < n; i++) {
            p = p * (this->v[i] * v.v[i]);
            fout << endl << p << endl;
        }

        return p;
    }

    friend ostream& operator<<(ostream& os, const Vector& v) {
        // fout << "operator in vector <<\n";

        for (int i = 0; i < v.n; i++) {
            os << v.v[i] << " ";
        }

        fout << endl;

        return os;
    }

    friend istream & operator>>(istream &in, Vector &c);

    ~Vector() {
    }
};

istream & operator>>(istream &in, Vector &c) {
    in >> c.n;
    for (int i = 0; i < c.n; i++) {
        in >> c.v[i];
    }

    return in;
}

class Matrice {
private:

    int m;
    int n;
    Vector v1[100];

public:

    Matrice() {
    }

    Matrice(int m, int n, Vector vec[100]) {

        this->m = m;
        this->n = n;
        for (int i = 0; i < m; i++) {
            this->v1[i] = vec[i];
        }
        //  fout << "matr parametri\n";
    }

    void afisare() {
        //fout << "matrice param: "<< endl;
        for (int i = 0; i < m; i++) {
            v1[i].afisare();
        }

    }

    Matrice operator+(Matrice &b) {
        Matrice m3;

        if (this->m != b.m || this->n != b.n) {
            fout << "matricele nu se pot aduna\n";

            return m3;
        }

        m3.m = this->m;
        m3.n = this->n;

        fout << m3.m << " -- " << m3.n << endl;
        fout<<"suma matricelor:\n";

        for (int i = 0; i < m; i++) {
            // fout << "adunare vector\n";
            m3.v1[i].n = n;
            for (int j = 0; j < n; j++) {

                m3.v1[i].v[j] = this->v1[i].v[j] + b.v1[i].v[j];
            }
        }

        return m3;
    }

    friend ostream& operator<<(ostream& os, const Matrice& mat) {
        //fout << "Afisare Matrice <<\n";

        os << mat.m << ' ' << mat.n << '\n';

        for (int i = 0; i < mat.m; i++) {
            os << mat.v1[i];
        }


        return os;
    }

    friend istream & operator>>(istream &in, Matrice &mat);

    ~Matrice() {
    }
};

istream & operator>>(istream &in, Matrice &mat) {
    in >> mat.m;
    in >> mat.n;
    for (int i = 0; i < mat.m; i++) {
        mat.v1[i].seteazaN(mat.n);
        in >> mat.v1[i];
    }

    return in;
}

int main() {

    int m, n;
    fin >> m>>n;
    int v[100];
    int v1[100];
    Vector arr[100];
    Vector arr1[100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fin >> v[j];
        Vector z(n, v);
        arr[i] = z;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fin >> v1[j];
        Vector z(n, v1);
        arr1[i] = z;

    }

    //  fout << "constr matrice\n";

    Matrice matr(m, n, arr);
    Matrice matr1(m, n, arr1);

    fout << "Matricele sunt:" << endl;

    matr.afisare();

    fout << endl;

    matr1.afisare();

    fout << endl;

    Matrice suma = matr + matr1;
    suma.afisare();

    // cout << "afisare cu supraincarcare\n";
   // fout << suma;
    fout << endl;
/*
    fout<<"vector: "<<endl;
    Vector test;
    fin >> test;
    fout << test;
    fout << endl;
    // cout << "citire afisare test\n";
    Matrice tesst;
    fin >> tesst;
    fout << tesst;
    fout << endl;
*/

    return 0;
}

