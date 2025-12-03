/*
    . A Canvas class that holds a 2D array of Pixels.
        . Topic: 
            . Dynamic memory management
            . Copy constructor and assignment operator: The copy and swap idiom at work.
            . Challenge the students to rewrite this using std::vector as a 2D array.
                . A solution is provided in the modern namespace.
                . Do we still need the copy and swap idiom if we're using std::vector? Food for thought.
            . Good lesson: 
                . Whenever you are dynamically allocating memory, you should always have a destructor
                    to release that memory. You should also set up your own copy constructor and copy assignment operator. to do proper deep copying.

                . The copy-and-swap idiom is not just useful for assignment operators. It can be used for any multi-step operation, where a lot can go wrong, to ensure an all-or-nothing outcome: first, create a copy, modify it, and if successful, swap the result with the original in a non-throwing manner.

                . Sometimes you don't objects of your classes to be copied at all . This is how the Qt QObject class works. It's not copyable. You can only move it. If you need that behavior, you can delete the copy constructor and copy assignment operator.
                    .eg: 
                        . class MyClass {
                        . public:
                        .     MyClass(const MyClass&) = delete;
                        .     MyClass& operator=(const MyClass&) = delete;
                        . };
*/

import utilities;

int main(){

    canvas_demo();
    
}