#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include"../include/Matrixinverse.hpp"

using namespace std;

int main() {
    // ── File streams ────────────────────────────────────────
    ifstream fin("input/input.txt");
    ofstream fout("output/output.txt");

    // ── Error handling ──────────────────────────────────────
    if (!fin) {
        cout << "Error: Cannot open input file.\n";
        return 1;
    }
    if (!fout) {
        cout << "Error: Cannot open output file.\n";
        return 1;
    }

    // ── Read matrix size ────────────────────────────────────
    int n;
    fin >> n;

    if (n <= 0) {
        fout << "Invalid matrix size.\n";
        return 1;
    }

    // ── Create matrix ───────────────────────────────────────
    MatrixInverse A(n);

    // ── Read matrix elements ────────────────────────────────
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double value;
            fin >> value;
            A.setElement(i, j, value);
        }
    }

    // ── Output Matrix ───────────────────────────────────────
    fout << "===== MATRIX A =====\n";
    for (int i = 0; i < A.getRows(); ++i) {
        for (int j = 0; j < A.getCols(); ++j) {
            fout << setw(10) << fixed << setprecision(4)
                 << A.getElement(i, j) << " ";
        }
        fout << "\n";
    }

    fout << "\n";

    // ── Determinant ─────────────────────────────────────────
    double det = A.determinantLU();
    fout << "Determinant: " << det << "\n";

    // ── Rank ────────────────────────────────────────────────
    fout << "Rank: " << A.rank() << "\n";

    // ── Check Singular ──────────────────────────────────────
    if (abs(det) < 1e-9) {
        fout << "Matrix is singular. Inverse does NOT exist.\n";
    } else {
        fout << "\n===== INVERSE MATRIX =====\n";

        Matrix inv = A.inverseGaussJordan();

        for (int i = 0; i < inv.getRows(); ++i) {
            for (int j = 0; j < inv.getCols(); ++j) {
                fout << setw(10) << fixed << setprecision(4)
                     << inv.getElement(i, j) << " ";
            }
            fout << "\n";
        }

        // ── Verification ────────────────────────────────────
        fout << "\nVerification (A × A⁻¹ ≈ I): ";
        fout << (A.verify() ? "PASSED" : "FAILED") << "\n";

        // ── Condition Number ────────────────────────────────
        fout << "Condition Number: " << A.conditionNumber() << "\n";
    }

    // ── Optional: Solve Ax = b ───────────────────────────────
    // Input format: after matrix, give vector b
    if (!fin.eof()) {
        vector<double> b(n);

        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (!(fin >> b[i])) {
                valid = false;
                break;
            }
        }

        if (valid && abs(det) > 1e-9) {
            fout << "\n===== SOLUTION Ax = b =====\n";
            vector<double> x = A.solve(b);

            for (int i = 0; i < n; ++i) {
                fout << "x[" << i + 1 << "] = "
                     << fixed << setprecision(6) << x[i] << "\n";
            }
        }
    }
    // ── Close files ─────────────────────────────────────────
    fin.close();
    fout.close();

    return 0;
}