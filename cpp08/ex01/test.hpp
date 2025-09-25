#include <vector>

class test
{
private:
    std::vector<int> cont;
public:
    test(int N)
    {
        cont.resize(N);
        cont.clear();
    };
    ~test();
};

test::test(/* args */)
{
}

test::~test()
{
}
