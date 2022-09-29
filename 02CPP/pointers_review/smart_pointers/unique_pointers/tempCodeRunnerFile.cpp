unique_ptr<int>unPtr1 = make_unique<int>(25);
    // //unique_ptr<int>unPtr2 = unPtr1; DO NOT ATTEMPT THIS BECAUSE YOU CANNOT SHARE UNIQUE POINTERS

    // //But you can move the ownership. Think about copyright laws of who owns what
    // unique_ptr<int>unPtr2 = move(unPtr1);
    // cout << "ownership is: " <<  *unPtr2 << endl; //remember that the ownership is now unPtr2
    // cout << "unPtr1 becomes: " << *unPtr1 << endl; //remember that unPtr1 is now nullptr
