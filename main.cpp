#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

///this class includes a vector that contains digits of the big int
class bignum
{
    vector<int> num;
    int size; ///it's good to store the size of the number

public:

    ///constructor creates the vector and sets the size
    explicit bignum(int size = 50)
    {
        this->num = vector<int>(size);
        this->size = size;
    }

    ///this operator returns a specific digit
    int& operator[](int index)
    {
        return this->num[index];
    }

    ///operator= should be available for :
    ///1. a big num
    ///2.  a string
    ///3. a const char*
    ///4. an integer (included in the template)
    bignum& operator=(const bignum& n)
    {
        this->num = n.num;
        return *this;
    }
    bignum& operator=(string n)
    {
        this->num = vector<int>(this->size);

        string nn = "";
        for(int i=n.size()-1; i>=0; i--) nn += n[i];
//        cout << "from operator=, nn : " << nn << endl; ///debug line

        int m = std::min((int)this->size, (int)nn.size());
//        cout << "m : " << m << endl;
        for(int i=0; i<m; i++)
        {
            this->num[i] = nn[i] - '0' ;
//            cout << nn[i] - '0' << endl; ///debug line
        }

//        for(auto x : this->num) cout << x << " "; cout << endl; ///debug line

        return *this;
    }
    bignum& operator=(const char* ncharstar)
    {
        this->num = vector<int>(this->size);

        string n = ncharstar;
        string nn = "";
        for(int i=n.size()-1; i>=0; i--) nn += n[i];
//        cout << "from operator=, nn : " << nn << endl; ///debug line

        int m = std::min((int)this->size, (int)nn.size());
//        cout << "m : " << m << endl;
        for(int i=0; i<m; i++)
        {
            this->num[i] = nn[i] - '0' ;
//            cout << nn[i] - '0' << endl; ///debug line
        }

//        for(auto x : this->num) cout << x << " "; cout << endl; ///debug line

        return *this;
    }
    template<typename T>
    bignum& operator=(T n)
    {
        this->num = vector<int>(this->size);
        int i=0;
        while(n)
        {
            this->num[i] = n%10;
            n /= 10;
            i++;
        }

        return *this;
    }

    ///operator+ should be available for :
    ///1. bigNum
    ///2. int (included in template)
    ///
    /// note :
    /// it's accepted to add numbers in "string" or "char*" format by converting them to "bigNum"
    template<typename T>
    bignum operator+ (T a)
    {
        bignum res(this->size);
        res = *this;

        res[0] += a;
        for(int i=0; i<this->size; i++)
        {
            if(res[i] < 10) break;

            int temp = res[i] / 10;
            res[i] = res[i] % 10;
            res[i+1] += temp;
        }

        return res;
    }


    ///there is a print function but using "cout << bigNum" is recommended
    void print(string end = "")
    {
        int indextemp;
        for(int x = this->num.size()-1; x>=0; x--)
        {
            if(this->num[x] != 0)
            {
                indextemp = x;
                break;
            }
        }

        for(int i=indextemp; i>=0; i--) cout << this->num[i]; cout << end;
    }
    friend ostream& operator<<(ostream& os, const bignum& n)
    {
        int indextemp;
        for(int x = n.num.size()-1; x>=0; x--)
        {
            if(n.num[x] != 0)
            {
                indextemp = x;
                break;
            }
        }
        for(int i=indextemp; i>=0; i--) os << n.num[i];

        return os;
    }
};


int main() {

    ///tests      git:
    bignum t;
    string s = "1265";
    t = "45862";
    cout << t << endl;
    t = t + 12 + 1 + 2;
    cout << t << endl;
    t = 12341;
    cout << t << endl;



    return 0;
}
