#include <iostream>

using namespace std;

string add(string x, string y) {
    if (x.length() < y.length()) swap(x, y);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    while (y.length() < x.length()) y += '0';
    string res;
    int carry = 0;
    for (size_t i = 0; i < x.length(); ++i) {
        int sum = (x[i] - '0') + (y[i] - '0') + carry;
        res += (sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) res += (carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

string subtract(string x, string y) {
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    while (y.length() < x.length()) y += '0';
    string res;
    int borrow = 0;
    for (size_t i = 0; i < x.length(); ++i) {
        int diff = (x[i] - '0') - (y[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res += (diff + '0');
    }
    reverse(res.begin(), res.end());
    size_t pos = res.find_first_not_of('0');
    if (pos != string::npos) res = res.substr(pos);
    else res = "0";
    return res;
}

string karatsuba(string a, string b) {
    size_t len1 = a.size(), len2 = b.size();
    if (len1 == 0 || len2 == 0) return "0";
    if (len1 < len2) return karatsuba(b, a);
    while (b.size() < a.size()) b = '0' + b;
    size_t n = a.size();
    if (n == 1) {
        int prod = (a[0] - '0') * (b[0] - '0');
        return to_string(prod);
    }
    size_t m = n / 2;
    string a1 = a.substr(0, n - m);
    string a0 = a.substr(n - m);
    string b1 = b.substr(0, n - m);
    string b0 = b.substr(n - m);
    string p = karatsuba(a1, b1);
    string q = karatsuba(a0, b0);
    string sum_a = add(a1, a0);
    string sum_b = add(b1, b0);
    string r = karatsuba(sum_a, sum_b);
    r = subtract(r, p);
    r = subtract(r, q);
    string part1 = p + string(2 * m, '0');
    string part2 = r + string(m, '0');
    string part3 = q;
    string res = add(add(part1, part2), part3);
    size_t pos = res.find_first_not_of('0');
    if (pos != string::npos) res = res.substr(pos);
    else res = "0";
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << karatsuba(a, b) << endl;
    return 0;
}
