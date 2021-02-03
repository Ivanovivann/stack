#include "stack.h"

int main() {
    Stack stack = {};
    if (construct_stack (&stack)) {
        printf ("construct is bad");
        dump_stack (&stack);
    }

    //test_stack (&stack);

    //((type_of_stack *)(stack.data))[4] = 5;
    //((type_of_stack *)(stack.data))[5] = 4;

    dump_stack (&stack);

    destruct_stack (&stack);

    return 0;
}
