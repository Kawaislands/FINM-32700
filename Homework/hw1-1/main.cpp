#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'pthFactor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER n
 *  2. LONG_INTEGER p
 */

long pthFactor(long n, long p) {
    vector<long> lessFactors;
    long count = 0;

    for (long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            lessFactors.push_back(i);
            ++count;
            if (count == p) {
                return i;
            }
        }
    }

    long totalFactors = count * 2 - (long(sqrt(n)) * long(sqrt(n)) == n ? 1 : 0);
    if (p > totalFactors) {
        return 0;
    }

    return n / lessFactors[totalFactors - p];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    long p = stol(ltrim(rtrim(p_temp)));

    long result = pthFactor(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
