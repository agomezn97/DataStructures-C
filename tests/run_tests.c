/*
 *
 */

#include "unity_fixture.h"

TEST_GROUP_RUNNER(stack)
{
    RUN_TEST_CASE(stack, InitializeStackDynamically);
    RUN_TEST_CASE(stack, InitializeStackDynamicallyWrong);
    RUN_TEST_CASE(stack, InitializeStackStatically);
    RUN_TEST_CASE(stack, PushPopStackDynamically);
    RUN_TEST_CASE(stack, PushPopStackStatically);
    RUN_TEST_CASE(stack, PushBeyondLimits);
    RUN_TEST_CASE(stack, PopBeyondLimits);
    RUN_TEST_CASE(stack, StackClear);
    RUN_TEST_CASE(stack, StackPeek);
    RUN_TEST_CASE(stack, StackPeekIndex);
    RUN_TEST_CASE(stack, StackSize);
}

TEST_GROUP_RUNNER(queue)
{
    RUN_TEST_CASE(queue, InitializeQueueDynamically);
    RUN_TEST_CASE(queue, InitializeQueueDynamicallyWrong);
    RUN_TEST_CASE(queue, InitializeQueueStatically);
    RUN_TEST_CASE(queue, AddRemoveQueueDynamically);
    RUN_TEST_CASE(queue, AddBeyondLimits);
    RUN_TEST_CASE(queue, RemoveBeyondLimits);
    RUN_TEST_CASE(queue, QueueClear);
    RUN_TEST_CASE(queue, QueuePeek);
    //RUN_TEST_CASE(queue, QueuePeekIndex);
    RUN_TEST_CASE(queue, QueueSize);
}

TEST_GROUP_RUNNER(linked_list)
{
    RUN_TEST_CASE(linked_list, InitializeList);
    RUN_TEST_CASE(linked_list, InitializeListWrong);
    RUN_TEST_CASE(linked_list, AddPeekRemoveSinglyNotCircular);
    RUN_TEST_CASE(linked_list, AddPeekRemoveSinglyCircular);
    RUN_TEST_CASE(linked_list, AddPeekRemoveDoublyNotCircular);
    RUN_TEST_CASE(linked_list, AddPeekRemoveDoublyCircular);
    RUN_TEST_CASE(linked_list, ListSearch);
}

TEST_GROUP_RUNNER(trees)
{


}

TEST_GROUP_RUNNER(hashtable)
{
    RUN_TEST_CASE(hashtable, InitializeTable);
    RUN_TEST_CASE(hashtable, InsertAndGet);
    RUN_TEST_CASE(hashtable, InsertAndRemove);
    RUN_TEST_CASE(hashtable, InsertAndClear);

}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(stack);
    RUN_TEST_GROUP(queue);
    RUN_TEST_GROUP(linked_list);
    //RUN_TEST_GROUP(trees);
    RUN_TEST_GROUP(hashtable);
}

int main(int argc, char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
