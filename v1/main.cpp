#include"CVector.h"

int main()
{
    //Scope is restricted for every test case to avoid any possible overlap between them.
    //For extra safety variable names are used different for each test case as well.
    {
        // Test case for Iterator, front, end functionality
        Vector<int> test_vec0;
        test_vec0.push_back(120);
        test_vec0.push_back(130);

        auto it = test_vec0.begin();
        assert(test_vec0[0] == *it);
        it = test_vec0.end();
        assert(test_vec0[1] == *it);
    }

    {
        // Test case for Insert functionality
        Vector<int> test_vec1;
        test_vec1.push_back(120);
        test_vec1.push_back(130);

        auto it = test_vec1.begin();
        test_vec1.insert(it, 200);
        assert(test_vec1[0] == 200);
        it++;
        test_vec1.insert(it, 300);
        assert(test_vec1[0] == 200);
        assert(test_vec1[1] == 300);
        assert(test_vec1[2] == 120);
        assert(test_vec1[3] == 130);
    }

    {
        // Test cases for copy constructor
        Vector<int> test_vec2;
        test_vec2.push_back(120);
        Vector<int> test_vec3(test_vec2);

        assert(test_vec3.size() == 1);
        assert(test_vec3[0] == 120);
    }

    {
        // String test cases
        Vector<string> test_vec4;
        test_vec4.push_back("string_200");
        test_vec4.push_back("string_130");
        assert(test_vec4[0] == "string_200");
        assert(test_vec4[1] == "string_130");
    }

    {
        // Test case for front, back and pop_back functionality
        Vector<int> test_vec5;
        test_vec5.push_back(120);
        test_vec5.push_back(130);

        assert(test_vec5.front() == 120);
        assert(test_vec5.back() == 130);
        test_vec5.pop_back();
        assert(test_vec5.back() == 120);
    }

    {
        // Test case for capacity and size functionality
        Vector<int> test_vec6;
        assert(test_vec6.capacity() == DEF_CAP);
        assert(test_vec6.size() == 0);

        test_vec6.push_back(120);
        test_vec6.push_back(130);

        assert(test_vec6.capacity() == (DEF_CAP -2));
        assert(test_vec6.size() == 2);
    }

    {
        // Test case for Erase functionality
        Vector<int> test_vec7;
        test_vec7.push_back(120);
        test_vec7.push_back(130);
        assert(test_vec7.size() == 2);

        auto it = test_vec7.begin();
        test_vec7.erase(it);
        assert(test_vec7.size() == 1);
        assert(test_vec7[0] == 130);
    }

    {
        // Test case for custom class object
        Vector<testA> test_vec8;
        assert(test_vec8.capacity() == DEF_CAP);
        assert(test_vec8.size() == 0);
        testA obj1;
        test_vec8.push_back(obj1);
        assert(test_vec8.capacity() == (DEF_CAP -1));
        assert(test_vec8.size() == 1);
    }

    {
        // Test case for overloaded constructors
        Vector<testA> test_vec9(2);
        assert(test_vec9.capacity() == (DEF_CAP-2));
        assert(test_vec9.size() == 2);
    }

    cout << "SUCCESS\n";
}

