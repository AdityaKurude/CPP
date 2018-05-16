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
        cout<<" iterator returned= "<<*(test_vec1.insert(it, 300))<<endl;
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


        test_vec7.push_back(140);
        test_vec7.push_back(150);
        test_vec7.push_back(160);
        test_vec7.push_back(170);
        it=it+4;
        test_vec7.erase(it);
        assert(test_vec7.size() == 4);
        assert(test_vec7[3] == 160);

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

    {
        // Test case for <= operator to be used in future for sort testing

        testA obj1,obj2;
        obj1.val = 2;
        obj1.val2 = 2;
        obj2.val = 2;
        obj2.val2 = 2;
        assert(1 == (obj1<=obj2));

        obj1.val = 1;
        obj1.val2 = 1;
        assert(1 == (obj1<=obj2));

        obj1.val = 3;
        obj1.val2 = 1;
        assert(0 == (obj1<=obj2));

        obj1.val = 1;
        obj1.val2 = 3;
        assert(0 == (obj1<=obj2));

        Vector<int> test_vec10;
        test_vec10.push_back(140);
        test_vec10.push_back(130);
        test_vec10.push_back(135);
        test_vec10.push_back(10);

        //        test_vec10.print_vec();
        assert(test_vec10.size() == 4);

        test_vec10.sort();
        assert(test_vec10[0] == 10);
        assert(test_vec10[1] == 130);

        //        test_vec10.print_vec();
    }

    {
        // Test case for integer sort functionality
        Vector<int> test_vec12;
        test_vec12.push_back(30);
        test_vec12.push_back(20);
        test_vec12.push_back(40);
        test_vec12.push_back(10);
        assert(test_vec12.size() == 4);
        test_vec12.sort();

        assert(test_vec12[0] == 10);
        assert(test_vec12[1] == 20);
        assert(test_vec12[2] == 30);
        assert(test_vec12[3] == 40);
    }

    {
        //Test case for sorting of custom object
        testA obj1,obj2,obj3,obj4;

        obj1.val = 10;
        obj1.val2 = 10;
        obj2.val = 20;
        obj2.val2 = 20;

        obj3.val = 30;
        obj3.val2 = 30;
        obj4.val = 40;
        obj4.val2 = 40;

        Vector<testA> test_vec11;
        test_vec11.push_back(obj3);
        test_vec11.push_back(obj2);
        test_vec11.push_back(obj4);
        test_vec11.push_back(obj1);

//        cout<<"before sort =============="<<endl;

//        cout<< " custom sort 0 = "<<test_vec11[0].val << " "<<test_vec11[0].val2<<endl;
//        cout<< " custom sort 1 = "<<test_vec11[1].val << " "<<test_vec11[1].val2<<endl;
//        cout<< " custom sort 2 = "<<test_vec11[2].val << " "<<test_vec11[2].val2<<endl;
//        cout<< " custom sort 3 = "<<test_vec11[3].val << " "<<test_vec11[3].val2<<endl;


        assert(test_vec11.size() == 4);

        test_vec11.sort();

//        cout<< " custom sort 0 = "<<test_vec11[0].val << " "<<test_vec11[0].val2<<endl;
//        cout<< " custom sort 1 = "<<test_vec11[1].val << " "<<test_vec11[1].val2<<endl;
//        cout<< " custom sort 2 = "<<test_vec11[2].val << " "<<test_vec11[2].val2<<endl;
//        cout<< " custom sort 3 = "<<test_vec11[3].val << " "<<test_vec11[3].val2<<endl;

        assert(test_vec11[0].val == 10);
        assert(test_vec11[0].val2 == 10);

        assert(test_vec11[3].val == 40);
        assert(test_vec11[3].val2 == 40);
    }

    cout << "SUCCESS\n";
}

